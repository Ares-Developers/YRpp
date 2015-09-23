#pragma once

#include <Memory.h>

#include <algorithm>


//========================================================================
//=== VectorClass ========================================================
//========================================================================

template <typename T>
class VectorClass
{
public:
	// the hidden element count messes with alignment. only applies to align 8, 16, ... 
	static_assert(!needs_vector_delete<T>::value || (__alignof(T) <= 4), "Alignment of T needs to be less than or equal to 4.");

	constexpr VectorClass() noexcept = default;

	explicit VectorClass(int capacity, T* pMem = nullptr) {
		if(capacity != 0) {
			this->Capacity = capacity;

			if(pMem) {
				this->Items = pMem;
			} else {
				this->Items = GameCreateArray<T>(static_cast<size_t>(capacity));
				this->IsAllocated = true;
			}
		}
	}

	VectorClass(const VectorClass &other) {
		if(other.Capacity > 0) {
			this->Items = GameCreateArray<T>(static_cast<size_t>(other.Capacity));
			this->IsAllocated = true;
			this->Capacity = other.Capacity;
			for(auto i = 0; i < other.Capacity; ++i) {
				this->Items[i] = other.Items[i];
			}
		}
	}

	VectorClass(VectorClass &&other) noexcept {
		other.Swap(*this);
	}

	virtual ~VectorClass() noexcept {
		// not a virtual call
		VectorClass::Clear();
	}

	VectorClass& operator = (const VectorClass &other) {
		VectorClass(other).Swap(*this);
		return *this;
	}

	VectorClass& operator = (VectorClass &&other) noexcept {
		VectorClass(std::move(other)).Swap(*this);
		return *this;
	}

	virtual bool operator == (const VectorClass &other) const {
		if(this->Capacity != other.Capacity) {
			return false;
		}

		for(auto i = 0; i < this->Capacity; ++i) {
			if(this->Items[i] == other.Items[i]) {
				continue; // kapow! don't rewrite this to != unless you know why you're doing it
			}
			return false;
		}

		return true;
	}

	bool operator != (const VectorClass &other) const {
		return !(*this == other);
	}

	virtual bool SetCapacity(int capacity, T* pMem = nullptr) {
		if(capacity != 0) {
			this->IsInitialized = false;

			bool bMustAllocate = (pMem == nullptr);
			if(!pMem) {
				pMem = GameCreateArray<T>(static_cast<size_t>(capacity));
			}

			this->IsInitialized = true;

			if(!pMem) {
				return false;
			}

			if(this->Items) {
				auto n = (capacity < this->Capacity) ? capacity : this->Capacity;
				for(auto i = 0; i < n; ++i) {
					pMem[i] = std::move_if_noexcept(this->Items[i]);
				}

				if(this->IsAllocated) {
					GameDeleteArray(this->Items, static_cast<size_t>(this->Capacity));
					this->Items = nullptr;
				}
			}

			this->IsAllocated = bMustAllocate;
			this->Items = pMem;
			this->Capacity = capacity;
		} else {
			Clear();
		}
		return true;
	}

	virtual void Clear() {
		if(this->Items && this->IsAllocated) {
			GameDeleteArray(this->Items, static_cast<size_t>(this->Capacity));
			this->Items = nullptr;
		}
		this->IsAllocated = false;
		this->Capacity = 0;
	}

	virtual int FindItemIndex(const T& item) const {
		if(!this->IsInitialized) {
			return 0;
		}

		for(auto i = 0; i < this->Capacity; ++i) {
			if(this->Items[i] == item) {
				return i;
			}
		}

		return -1;
	}

	virtual int GetItemIndex(const T* pItem) const {
		if(!this->IsInitialized) {
			return 0;
		}

		return pItem - this->Items;
	}

	virtual T GetItem(int i) const {
		return this->Items[i];
	}

	T& operator [] (int i) {
		return this->Items[i];
	}

	const T& operator [] (int i) const {
		return this->Items[i];
	}

	bool Reserve(int capacity) {
		if(!this->IsInitialized) {
			return false;
		}

		if(this->Capacity >= capacity) {
			return true;
		}

		return SetCapacity(capacity, nullptr);
	}

	void Purge() {
		this->Items = nullptr;
		this->IsAllocated = false;
		this->Capacity = 0;
	}

	void Swap(VectorClass& other) noexcept {
		using std::swap;
		swap(this->Items, other.Items);
		swap(this->Capacity, other.Capacity);
		swap(this->IsInitialized, other.IsInitialized);
		swap(this->IsAllocated, other.IsAllocated);
	}

	T* Items{ nullptr };
	int Capacity{ 0 };
	bool IsInitialized{ true };
	bool IsAllocated{ false };
};

//========================================================================
//=== DynamicVectorClass =================================================
//========================================================================

template <typename T>
class DynamicVectorClass : public VectorClass<T>
{
public:
	constexpr DynamicVectorClass() noexcept = default;

	explicit DynamicVectorClass(int capacity, T* pMem = nullptr)
		: VectorClass(capacity, pMem)
	{ }

	DynamicVectorClass(const DynamicVectorClass &other) {
		if(other.Capacity > 0) {
			this->Items = GameCreateArray<T>(static_cast<size_t>(other.Capacity));
			this->IsAllocated = true;
			this->Capacity = other.Capacity;
			this->Count = other.Count;
			this->CapacityIncrement = other.CapacityIncrement;
			for(auto i = 0; i < other.Count; ++i) {
				this->Items[i] = other.Items[i];
			}
		}
	}

	DynamicVectorClass(DynamicVectorClass &&other) noexcept {
		other.Swap(*this);
	}

	// not needed. base class destructor will call base class Clear()
	//virtual ~DynamicVectorClass() noexcept override {
	//	Clear();
	//}

	DynamicVectorClass& operator = (const DynamicVectorClass &other) {
		DynamicVectorClass(other).Swap(*this);
		return *this;
	}

	DynamicVectorClass& operator = (DynamicVectorClass &&other) noexcept {
		DynamicVectorClass(std::move(other)).Swap(*this);
		return *this;
	}

	virtual bool SetCapacity(int capacity, T* pMem = nullptr) override {
		bool bRet = VectorClass::SetCapacity(capacity, pMem);

		if(this->Capacity < this->Count) {
			this->Count = this->Capacity;
		}

		return bRet;
	}

	virtual void Clear() override {
		this->Count = 0;
		VectorClass::Clear();
	}

	virtual int FindItemIndex(const T& item) const override {
		if(!this->IsInitialized) {
			return 0;
		}

		for(int i = 0; i < this->Count; i++) {
			if(this->Items[i] == item) {
				return i;
			}
		}

		return -1;
	}

	bool ValidIndex(int index) const {
		return static_cast<unsigned int>(index) < static_cast<unsigned int>(this->Count);
	}

	T GetItemOrDefault(int i) const {
		return this->GetItemOrDefault(i, T());
	}

	T GetItemOrDefault(int i, T def) const {
		if(this->ValidIndex(i)) {
			return this->Items[i];
		}
		return def;
	}

	T* begin() const {
		//if(!this->IsInitialized) {
		//	return nullptr;
		//}
		return &this->Items[0];
	}

	T* end() const {
		//if(!this->IsInitialized) {
		//	return nullptr;
		//}
		return &this->Items[this->Count];
	}

	bool AddItem(T item) {
		if(this->Count >= this->Capacity) {
			if(!this->IsAllocated && this->Capacity != 0) {
				return false;
			}

			if(this->CapacityIncrement <= 0) {
				return false;
			}

			if(!this->SetCapacity(this->Capacity + this->CapacityIncrement, nullptr)) {
				return false;
			}
		}

		this->Items[Count++] = std::move(item);
		return true;
	}

	bool AddUnique(const T &item) {
		int idx = this->FindItemIndex(item);
		return idx < 0 && this->AddItem(item);
	}

	bool RemoveItem(int index) {
		if(!this->ValidIndex(index)) {
			return false;
		}

		--this->Count;
		for(int i = index; i < this->Count; ++i) {
			this->Items[i] = std::move_if_noexcept(this->Items[i + 1]);
		}

		return true;
	}

	bool Remove(const T &item) {
		int idx = this->FindItemIndex(item);
		return idx >= 0 && this->RemoveItem(idx);
	}

	void Purge() {
		this->Count = 0;
		VectorClass::Purge();
	}

	void Swap(DynamicVectorClass& other) noexcept {
		VectorClass::Swap(other);
		using std::swap;
		swap(this->Count, other.Count);
		swap(this->CapacityIncrement, other.CapacityIncrement);
	}

	int Count{ 0 };
	int CapacityIncrement{ 10 };
};

//========================================================================
//=== TypeList ===========================================================
//========================================================================

template <typename T>
class TypeList : public DynamicVectorClass<T>
{
public:
	constexpr TypeList() noexcept = default;

	explicit TypeList(int capacity, T* pMem = nullptr)
		: DynamicVectorClass(capacity, pMem)
	{ }

	TypeList(const TypeList &other) {
		this->unknown_18 = other.unknown_18;
		DynamicVectorClass::operator=(other);
	}

	TypeList(TypeList &&other) noexcept {
		other.Swap(*this);
	}

	TypeList& operator = (const TypeList &other) {
		TypeList(other).Swap(*this);
		return *this;
	}

	TypeList& operator = (TypeList &&other) noexcept {
		TypeList(std::move(other)).Swap(*this);
		return *this;
	}

	void Swap(TypeList& other) noexcept {
		DynamicVectorClass::Swap(other);
		using std::swap;
		swap(this->unknown_18, other.unknown_18);
	}

	int unknown_18{ 0 };
};

//========================================================================
//=== CounterClass =======================================================
//========================================================================

class CounterClass : public VectorClass<int>
{
public:
	constexpr CounterClass() noexcept = default;

	CounterClass(const CounterClass& other)
		: VectorClass(other), Total(other.Total)
	{ }

	CounterClass(CounterClass &&other) noexcept {
		other.Swap(*this);
	}

	// not needed. base class destructor will call base class Clear()
	//virtual ~CounterClass() noexcept override {
	//	VectorClass::Clear();
	//	this->Total = 0;
	//}

	CounterClass& operator = (const CounterClass &other) {
		CounterClass(other).Swap(*this);
		return *this;
	}

	CounterClass& operator = (CounterClass &&other) noexcept {
		CounterClass(std::move(other)).Swap(*this);
		return *this;
	}

	virtual void Clear() override {
		for(int i = 0; i < this->Capacity; ++i) {
			this->Items[i] = 0;
		}

		this->Total = 0;
	}

	int GetTotal() const {
		return this->Total;
	}

	bool EnsureItem(int index) {
		if(index < this->Capacity) {
			return true;
		}

		int count = this->Capacity;
		if(this->SetCapacity(index + 10, nullptr)) {
			for(auto i = count; i < this->Capacity; ++i) {
				this->Items[i] = 0;
			}
			return true;
		}

		return false;
	}

	int operator[] (int index) const {
		return this->GetItemCount(index);
	}

	int GetItemCount(int index) {
		return this->EnsureItem(index) ? this->Items[index] : 0;
	}

	int GetItemCount(int index) const {
		return (index < this->Capacity) ? this->Items[index] : 0;
	}

	int Increment(int index) {
		if(this->EnsureItem(index)) {
			++this->Total;
			return ++this->Items[index];
		}
		return 0;
	}

	int Decrement(int index) {
		if(this->EnsureItem(index)) {
			--this->Total;
			return --this->Items[index];
		}
		return 0;
	}

	void Swap(CounterClass& other) noexcept {
		VectorClass::Swap(other);
		using std::swap;
		swap(this->Total, other.Total);
	}

	int Total{ 0 };
};
