#ifndef GENERALSTRUCTURES_H
#define GENERALSTRUCTURES_H

#include <ASMMacros.h>
#include <YRPPCore.h>
#include <YRMathVector.h>
#include <GeneralDefinitions.h> // need eDirection for FacingStruct
#include <BasicStructures.h>

#include <string.h>

//used for cell coordinates/vectors
#ifndef VECTORSTRUCTS
#define VECTORSTRUCTS
typedef Vector2D<short> CellStruct;
typedef Vector2D<int> Point2D;
typedef Vector3D<int> CoordStruct;

// used for particle ColorList
typedef Vector3D<BYTE> RGBClass; // <pd> wuhaha
#endif

//used for timed events, time measured in frames!
class TimerStruct
{
public:
	int StartTime;
	int unknown;
	int TimeLeft;

	TimerStruct() : StartTime(-1), TimeLeft(0) { }
	TimerStruct(int duration) { this->Start(duration); }

	void Start(int duration) {
		this->StartTime = Unsorted::CurrentFrame;
		this->TimeLeft = duration;
	}

	void Stop() {
		this->StartTime = -1;
		this->TimeLeft = 0;
	}

	void Pause() {
		if(this->IsTicking()) {
			this->TimeLeft = this->GetTimeLeft();
			this->StartTime = -1;
		}
	}

	void Resume() {
		if(!this->IsTicking()) {
			this->StartTime = Unsorted::CurrentFrame;
		}
	}

	int GetTimeLeft() const {
		if(!this->IsTicking()) {
			return this->TimeLeft;
		}

		auto passed = Unsorted::CurrentFrame - this->StartTime;
		auto left = this->TimeLeft - passed;

		return (left <= 0) ? 0 : left;
	}

	// returns whether a ticking timer has finished counting down.
	bool Completed() const {
		return this->IsTicking() && !this->HasTimeLeft();
	}

	// returns whether a delay is active or a timer is still counting down.
	// this is the 'opposite' of Completed() (meaning: incomplete / still busy)
	// and logically the same as !Expired() (meaning: blocked / delay in progress)
	bool InProgress() const {
		return this->IsTicking() && this->HasTimeLeft();
	}

	// returns whether a delay is inactive. same as !InProgress().
	bool Expired() const {
		return !this->IsTicking() || !this->HasTimeLeft();
	}

protected:
	bool IsTicking() const {
		return this->StartTime != -1;
	}

	bool HasTimeLeft() const {
		return this->GetTimeLeft() > 0;
	}
};

class RepeatableTimerStruct : public TimerStruct
{
public:
	int Duration;

	void Start(int duration)
		{ this->Duration = duration; this->Restart(); }

	void Restart()
		{ this->TimerStruct::Start(this->Duration); }
};

inline unsigned int TranslateFixedPoint(size_t bitsFrom, size_t bitsTo, unsigned int value, unsigned int offset = 0) {
	const size_t MaskIn = ((1u << bitsFrom) - 1);
	const size_t MaskOut = ((1u << bitsTo) - 1);

	if(bitsFrom > bitsTo) {
		// converting down
		return (((((value & MaskIn) >> (bitsFrom - bitsTo - 1)) + 1) >> 1) + offset) & MaskOut;

	} else if(bitsFrom < bitsTo) {
		// converting up
		return (((value - offset) & MaskIn) << (bitsTo - bitsFrom)) & MaskOut;

	} else {
		return value & MaskOut;
	}
}

// like a compass with 2 ^ 16 units equalling 360°
struct DirStruct
{
	typedef short value_type;
	typedef unsigned short unsigned_type;

	DirStruct() : DirStruct(0) { }
	explicit DirStruct(value_type value) : Value(value) { }

	DirStruct(size_t bits, value_type value)
		: DirStruct(static_cast<value_type>(TranslateFixedPoint(bits, 16, static_cast<unsigned_type>(value), 0)))
	{ }

	bool operator == (const DirStruct& rhs) const {
		return this->Value == rhs.Value;
	}

	bool operator != (const DirStruct& rhs) const {
		return this->Value != rhs.Value;
	}

	DirStruct& operator += (const DirStruct& rhs) {
		reinterpret_cast<unsigned_type&>(this->Value) += static_cast<unsigned_type>(rhs.value());
		return *this;
	}

	DirStruct operator + (const DirStruct& rhs) const {
		return DirStruct(*this) += rhs;
	}

	DirStruct& operator -= (const DirStruct& rhs) {
		reinterpret_cast<unsigned_type&>(this->Value) -= static_cast<unsigned_type>(rhs.value());
		return *this;
	}

	DirStruct operator - (const DirStruct& rhs) const {
		return DirStruct(*this) -= rhs;
	}

	DirStruct operator - () const {
		return DirStruct(-this->Value);
	}

	DirStruct operator + () const {
		return *this;
	}

	template <size_t Bits>
	value_type value() const {
		static_assert(Bits > 0 && Bits <= 16, "Bits has to be greater than 0 and lower or equal to 16.");

		return static_cast<value_type>(TranslateFixedPoint(16, Bits, static_cast<unsigned_type>(this->Value), 0));
	}

	template <>
	value_type value<16>() const {
		return this->Value;
	}

	template <size_t Bits>
	void value(value_type value) {
		static_assert(Bits > 0 && Bits <= 16, "Bits has to be greater than 0 and lower or equal to 16.");

		this->Value = static_cast<value_type>(TranslateFixedPoint(Bits, 16, static_cast<unsigned_type>(value), 0));
	}

	value_type value8() const {
		return this->value<3>();
	}

	void value8(value_type value) {
		this->value<3>(value);
	}

	value_type value32() const {
		return this->value<5>();
	}

	void value32(value_type value) {
		this->value<5>(value);
	}

	value_type value256() const {
		return this->value<8>();
	}

	void value256(value_type value) {
		this->value<8>(value);
	}

	value_type value() const {
		return this->value<16>();
	}

	void value(value_type value) {
		this->value<16>(value);
	}

	template <size_t Bits = 16>
	double radians() const {
		static_assert(Bits > 0 && Bits <= 16, "Bits has to be greater than 0 and lower or equal to 16.");

		static const int Max = ((1u << Bits) - 1);

		double value = Max / 4 - this->value<Bits>();
		return value * Math::TwoPi / Max;
	}

	template <size_t Bits = 16>
	void radians(double rad) {
		static_assert(Bits > 0 && Bits <= 16, "Bits has to be greater than 0 and lower or equal to 16.");

		static const int Max = ((1u << Bits) - 1);

		int value = static_cast<int>(rad * Max / Math::TwoPi);
		this->value<Bits>(static_cast<value_type>(Max / 4 - value));
	}

private:
	value_type Value;
	unsigned_type unused_2;
};

// managing a facing that can change over time
struct FacingStruct
{
	FacingStruct() : Timer(0) { }

	FacingStruct(short rot) : FacingStruct() {
		this->turn_rate(rot);
	}

	short turn_rate() const {
		return this->ROT.value();
	}

	void turn_rate(short value) {
		if(value > 127) {
			value = 127;
		}

		this->ROT.value<8>(value);
	}

	bool in_motion() const {
		return this->turn_rate() > 0 && this->Timer.GetTimeLeft();
	}

	DirStruct target() const {
		return this->Value;
	}

	DirStruct current() const {
		auto ret = this->Value;

		if(this->in_motion()) {
			auto diff = this->difference();
			auto num_steps = static_cast<short>(this->num_steps());

			if(num_steps > 0) {
				auto steps_left = this->Timer.GetTimeLeft();
				ret.value(static_cast<short>(ret.value() - steps_left * diff / num_steps));
			}
		}

		return ret;
	}

	bool set(const DirStruct& value) {
		bool ret = (this->current() != value);

		if(ret) {
			this->Value = value;
			this->Initial = value;
		}

		this->Timer.Start(0);

		return ret;
	}

	bool turn(const DirStruct& value) {
		if(this->Value == value) {
			return false;
		}

		this->Initial = this->current();
		this->Value = value;

		if(this->turn_rate() > 0) {
			this->Timer.Start(this->num_steps());
		}

		return true;
	}

private:
	short difference() const {
		return static_cast<short>(this->Value.value() - this->Initial.value());
	}

	int num_steps() const {
		return abs(this->difference()) / this->turn_rate();
	}

	DirStruct Value; // target facing
	DirStruct Initial; // rotation started here
	TimerStruct Timer; // counts rotation steps
	DirStruct ROT; // Rate of Turn. INI Value * 256
};

struct SomeVoxelCache {
	void *ptr;
	DWORD f_4;
	DWORD f_8;
	BYTE f_C;
	DWORD * ptr_10;
};

struct BasePlanningCell {
	int Weight;
	CellStruct Position;
};

// this crap is used in several Base planning routines
struct BasePlanningCellContainer {
	BasePlanningCell * Items;
	int Count;
	int Capacity;
	bool Sorted;
	DWORD Unknown_10;

	bool AddCapacity(int AdditionalCapacity)
		{ JMP_THIS(0x510860); }

	// for qsort
	static int __cdecl Comparator(const void *, const void *)
		{ JMP_STD(0x5108F0); }
};

// combines number and a string
struct NamedValue {
	const char* Name;
	int Value;

	bool operator == (int value) const {
		return this->Value == value;
	}

	bool operator == (const char* name) const {
		return !_strcmpi(this->Name, name);
	}

	bool operator == (const NamedValue& other) const {
		return this->Value == other.Value && *this == other.Name;
	}
};

#endif
