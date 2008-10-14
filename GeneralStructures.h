#ifndef GENERALSTRUCTURES_H
#define GENERALSTRUCTURES_H

#include <YRPPCore.h>
#include <YRMathVector.h>

//used for cell coordinates/vectors
#ifndef VECTORSTRUCTS
#define VECTORSTRUCTS
typedef Vector2D<short> CellStruct;
typedef Vector2D<int> Point2D;
typedef Vector3D<int> CoordStruct;

// used for particle ColorList
typedef Vector3D<BYTE> RGBClass; // <pd> wuhaha
#endif

//used for most colors
struct ColorStruct
{
	BYTE R, G, B;

	void operator = (ColorStruct Color)
	{
		R = Color.R;
		G = Color.G;
		B = Color.B;
	}

	ColorStruct()
	{
	}

	ColorStruct(BYTE _R, BYTE _G, BYTE _B)
	{
		R = _R;
		G = _G;
		B = _B;
	}
};

//used for light colors
struct TintStruct
{
	int Red, Green, Blue;
};

//uses the clock values
struct DirStruct
{
	short Facing;
};

//Random numbe range
struct RandomStruct
{
	int Min, Max;
};

//3D Matrix
struct Matrix3DStruct
{
	float Data[12];
};

//obvious
struct RectangleStruct
{
	int X, Y, Width, Height;
};

//used for timed events, time measured in frames!
class TimerStruct
{
public:
	int StartTime;
	int unknown;
	int TimeLeft;

	void Stop()
		{ this->StartTime = -1; this->TimeLeft = 0; }

	bool IsDone()
		{ return this->StartTime != -1 && this->GetTimeLeft() <= 0; }

	int GetTimeLeft()
		JMP_STD(0x426630);

	void Start(int duration)
		JMP_STD(0x46B640);

	void StartIfEmpty() // just sets start frame
		JMP_STD(0x6CE2C0);
};

//also see FACING definitions
struct FacingStruct
{
	WORD Facing1; //current facing?
	WORD unused_2;
	WORD Facing2; //??
	WORD unused_6;
	TimerStruct Timer; //rotation?
	WORD ROT; //Rate of Turn. INI Value * 256
	WORD unused_16;
};

#endif
