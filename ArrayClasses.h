#ifndef DVC_H
#define DVC_H

#include <YRPPCore.h>

//========================================================================
//=== VectorClass ========================================================
//========================================================================

template <typename T> class VectorClass
{
public:
	virtual ~VectorClass()
		{ Clear(); }

	virtual bool IsEqual(VectorClass* pVec)
		{
			if(Capacity == pVec->get_Capacity())
			{
				if(Capacity == 0)
					return true;

				for(int i = 0; i < Capacity; i++)
				{
					if(!(Items[i] == pVec->get_Items()[i]))
						return false;
				}
				return true;
			}
			return false;
		}


	virtual bool SetCapacity(int nNewCapacity, T* pMem)
		{
			if(nNewCapacity != 0)
			{
				IsInitialized = false;

				if(!pMem)
					pMem = new T[nNewCapacity];

				IsInitialized = true;
				if(pMem)
				{
					if(Items)
					{
						int n = (nNewCapacity < Capacity) ? nNewCapacity : Capacity;
						for(int i = 0; i < n; i++)
							pMem[i] = Items[i];

						if(this->IsAllocated)
						{
							delete Items;
							Items = NULL;
						}
					}

					IsAllocated = (pMem == NULL);
					Items = pMem;
					Capacity = nNewCapacity;
					return true;
				}
				return false;
			}
			Clear();
			return true;
		}

	virtual void Clear()
		{
			if(Items && IsAllocated)
			{
				delete Items;
				Items = NULL;
			}
			IsAllocated = false;
			Capacity = 0;
		}

	virtual int FindItemIndex(T tItem)
		{
			if(!IsInitialized) return 0;

			for(int i = 0; i < Capacity; i++)
				if(Items[i] == tItem) return i;

			return -1;
		}

	virtual int GetItemIndex(T* pItem)
		{
			if(!IsInitialized) return 0;
			return (pItem - Items) / sizeof(T);
		}

	virtual T GetItem(int i) 
		{ return Items[i]; }

	T& operator [](int i)
		{ return Items[i]; }

	VectorClass()
	{
		Items = NULL;
		Capacity = 0;
		IsInitialized = true;
		IsAllocated = false;
	}

	VectorClass(int nCapacity, T* pMem)
	{
		Items = NULL;
		Capacity = nCapacity;
		IsInitialized = true;
		IsAllocated = false;

		if(nCapacity != 0)
		{
			if(pMem)
				Items = pMem;
			else
			{
				Items = new T[nCapacity];
				IsAllocated = true;
			}
		}
	}

	PROPERTY(T*,		Items);
	PROPERTY_READONLY(int,		Capacity);
	PROPERTY(bool,		IsInitialized);
	PROPERTY(bool,		IsAllocated);
};

//========================================================================
//=== DynamicVectorClass =================================================
//========================================================================

template <typename T> class DynamicVectorClass : public VectorClass<T>
{
public:
	virtual ~DynamicVectorClass()
		{ Clear(); }

	virtual bool SetCapacity(int nNewCapacity, T* pMem)
		{
			bool bRet = VectorClass<T>::SetCapacity(nNewCapacity, pMem);

			if(this->Capacity < Count)
				Count = this->Capacity;

			return bRet;
		}

	virtual void Clear()
		{
			Count = 0;
			VectorClass<T>::Clear();
		}

	// this doesn't work right for some reason, see Bugfixes.cpp TechnoTypeClass_GetCameo
	// passing a pointer that's in the array still returns -1
	virtual int FindItemIndex(T tItem)
		{
			if(!this->IsInitialized) return -1;

			for(int i = 0; i < Count; i++)
				if(this->Items[i] == tItem) return i;

			return -1;
		}

	DynamicVectorClass() : VectorClass<T>()
		{
			Count = 0;
			CapacityIncrement = 10;
		}

	DynamicVectorClass(int nCapacity, T* pMem) : VectorClass<T>(nCapacity, pMem)
		{
			Count = 0;
			CapacityIncrement = 10;
		}

public:
	bool AddItem(T tItem)
		{
			if(Count >= this->Capacity)
			{
				if((!this->IsAllocated && this->Capacity != 0) || (CapacityIncrement == 0))
					return false;

				if(!SetCapacity(this->Capacity + CapacityIncrement, NULL))
					return false;
			}
			this->Items[Count++] = tItem;

			return true;
		}

	bool RemoveItem(int nIndex)
		{
			if(nIndex >= 0 && nIndex < Count)
			{
				--Count;
				if(nIndex < Count)
				{
					for(int i = nIndex; i < Count; i++)
						this->Items[i] = this->Items[i+1];
				}
				return true;
			}
			return false;
		}

	PROPERTY(int,	Count);
	PROPERTY(int,	CapacityIncrement);
};

//========================================================================
//=== TypeList ===========================================================
//========================================================================

template <typename T> class TypeList : public DynamicVectorClass<T>
{
public:
	virtual ~TypeList()
		{ DynamicVectorClass<T>::Clear(); }

	TypeList() : DynamicVectorClass<T>()
		{ }
	
	TypeList(int nCapacity, T* pMem) : DynamicVectorClass<T>(nCapacity, pMem)
		{ }

	PROPERTY(DWORD,	unknown_18);
};

//========================================================================
//=== CounterClass =======================================================
//========================================================================

class CounterClass : public VectorClass<int>
{
public:
	virtual ~CounterClass()
		{
			if(Items && IsAllocated)
			{
				delete Items;
				Items = NULL;
			}
			IsAllocated = false;
			Capacity = 0;
			Count = 0;
		}

	virtual void Clear()
		{
			for(int i = 0; i < this->Capacity; i++)
				Items[i] = 0;

			Count = 0;
		}

	int GetItemCount(int nIndex)
		{ PUSH_VAR32(nIndex); THISCALL(0x49FAE0); }

	CounterClass() : VectorClass<int>()
		{ Count = 0; }

	int Increment(int nIndex)
		{ PUSH_VAR32(nIndex); THISCALL(0x49FA00); }

	int Decrement(int nIndex)
		{ PUSH_VAR32(nIndex); THISCALL(0x49FA70); }

	PROPERTY(int,	Count);	//not sure what this is, but it's different from DVC's count
};

#endif
