#ifndef GENERALSTRUCTURES_H
#define GENERALSTRUCTURES_H

#include <YRPPCore.h>
#include <YRMathVector.h>

//used for cell coordinates/vectors
#ifndef VECTORSTRUCTS
#define VECTORSTRUCTS
typedef Vector2D<short> CellStruct;
typedef Vector2D<int>	Point2D;

struct CoordStruct : public Vector3D<int>
{
public:
	int X, Y, Z;
	CoordStruct()
	{
		this->X = this->Y = this->Z = 0;
	}
	CoordStruct(CellStruct* cell)
	{
		this->X = cell->X * 256 + 128;
		this->Y = cell->Y * 256 + 128;
		this->Z = 0;
	}
};
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
	{ }

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
	int Red,Green,Blue;
};

//uses the clock values
struct DirStruct
{
	short Facing;
};

//Random numbe range
struct RandomStruct
{
	int Min,Max;
};

//3D Matrix
struct Matrix3DStruct
{
	float Data[12];
};

//obvious
struct RectangleStruct
{
	int X,Y,Width,Height;
};

//used for timed events, time measured in frames!
struct TimerStruct
{
	int StartTime;
	int unknown;
	int TimeLeft;

	void Stop()
		{ this->StartTime = -1; this->TimeLeft = 0; }

	bool IsDone()
		{ return this->StartTime != -1 && this->GetTimeLeft() <= 0; }

	int GetTimeLeft()
		{ THISCALL(0x426630); }

	void Start(int duration)
		{ PUSH_VAR32(duration); THISCALL(0x46B640); }

	void StartIfEmpty() // just sets start frame
		{ THISCALL(0x6CE2C0); }
};

#endif
