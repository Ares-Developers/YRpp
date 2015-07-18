#pragma once

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

	bool operator == (ColorStruct rhs)
	{
		return R == rhs.R && G == rhs.G && B == rhs.B;
	}

	ColorStruct() = default;

	ColorStruct(BYTE _R, BYTE _G, BYTE _B)
	{
		R = _R;
		G = _G;
		B = _B;
	}
};

#ifndef PALETTE_STRUCT
#define PALETTE_STRUCT
struct BytePalette {
	ColorStruct Entries[256];
	ColorStruct & operator [](const int idx) {
		return this->Entries[idx];
	}
};
#endif

//used for light colors
struct TintStruct
{
	int Red, Green, Blue;
};

//16bit colors
#pragma pack(push, 1)
struct Color16Struct
{
	int R : 5;
	int G : 6;
	int B : 5;

	void operator = (Color16Struct Color)
	{
		R = Color.R;
		G = Color.G;
		B = Color.B;
	}

	void operator = (ColorStruct Color)
	{
		R = Color.R >> 3;
		G = Color.G >> 2;
		B = Color.B >> 3;
	}

	bool operator == (Color16Struct rhs)
	{
		return R == rhs.R && G == rhs.G && B == rhs.B;
	}

	Color16Struct() = default;
};
#pragma pack(pop)


//Random number range
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

struct LTRBStruct
{
	int Left;
	int Top;
	int Right;
	int Bottom;
};
