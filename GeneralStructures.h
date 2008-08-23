#ifndef GENERALSTRUCTURES_H
#define GENERALSTRUCTURES_H

#include <YRPPCore.h>
#include <YRMathVector.h>

//used for cell coordinates/vectors
#ifndef VECTORSTRUCTS
#define VECTORSTRUCTS
typedef Vector2D<short> CellStruct;
typedef Vector2D<int>	Point2D;
typedef Vector3D<int>	CoordStruct;
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
	int	TimeLeft;
};

#endif
