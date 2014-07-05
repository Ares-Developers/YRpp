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


//uses the clock values
struct DirStruct
{
	typedef WORD Raw;
	typedef int Rounded;

	DirStruct() : Value(0) { }
	DirStruct(Raw value) : Value(value) { }
	DirStruct(Rounded facing) : Value((facing & 0xFF) << 8) { }

	operator Rounded() const {
		// value / 256 with rounding
		return (((this->Value >> 7) + 1) >> 1) & 0xFF;
	}

	operator Raw() const {
		return this->Value;
	}

	Raw Value;
private:
	WORD unused_2;
};

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

	bool IsDone() const
		{ return this->StartTime != -1 && this->GetTimeLeft() <= 0; }


	// returns whether a delay is active or a timer is still counting down.
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

//also see FACING definitions
struct FacingStruct
{
	DirStruct Value; //current facing
	DirStruct Target; //target facing
	TimerStruct Timer; //rotation?
	DirStruct ROT; //Rate of Turn. INI Value * 256

	DirStruct* GetFacing(DirStruct *buffer) const
		{ JMP_THIS(0x4C93D0); }

	void SetFacing(DirStruct *dir)
		{ JMP_THIS(0x4C9300); }

	operator int() const {
		// <DCoder> I don't know how or what it does, but that's what the game uses
		DirStruct nessie;
		this->GetFacing(&nessie); // mysterious facing value from the depths of the game
		return nessie;
	}
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
