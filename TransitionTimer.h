#ifndef TRANSITIONTIMER_H
#define TRANSITIONTIMER_H

#include <GeneralDefinitions.h>

struct TransitionTimer
{
public:
	//Constructor, Destructor
	TransitionTimer()
		JMP_THIS(0x4A50F0);

	~TransitionTimer()
		{ }

	bool AreStates11() // 0x4A5110
		{ return this->State1 && this->State2; }

	bool AreStates10() // 0x4A5130
		{ return this->State1 && !this->State2; }

	bool AreStates01() // 0x4A51B0
		{ return !this->State1 && this->State2 == 1; }

	bool AreStates00() // 0x4A51D0
		{ return !this->State1 && !this->State2; }

	bool IsTimerFinished()
		JMP_THIS(0x4A5150);

	void StartTimer11(double time)
		JMP_THIS(0x4A51F0);

	void StartTimer10(double time)
		JMP_THIS(0x4A5240);

	void Update()
		JMP_THIS(0x4A5290);

	double PercentageDone()
		JMP_THIS(0x4A52F0);

	void SetToDone()
		JMP_THIS(0x4A5360);

	//===========================================================================
	//===== Properties ==========================================================
	//===========================================================================
	PROPERTY(double,      Rate1);
	PROPERTY_STRUCT(TimerStruct, ActionTimer);
	PROPERTY(DWORD,       Rate2);
	PROPERTY(bool,        State1);
	PROPERTY(bool,        State2);
};

#endif
