#pragma once

struct Color16Struct;

//used for most colors
struct ColorStruct
{
	ColorStruct() = default;

	ColorStruct(BYTE const r, BYTE const g, BYTE const b)
		: R(r), G(g), B(b)
	{ }

	inline explicit ColorStruct(Color16Struct const color);

	bool operator == (ColorStruct const rhs) const {
		return R == rhs.R && G == rhs.G && B == rhs.B;
	}

	bool operator != (ColorStruct const rhs) const {
		return !(*this == rhs);
	}

	BYTE R, G, B;
};

struct BytePalette {
	ColorStruct Entries[256];

	ColorStruct& operator [](int const idx) {
		return this->Entries[idx];
	}

	ColorStruct const& operator [](int const idx) const {
		return this->Entries[idx];
	}
};

//used for light colors
struct TintStruct
{
	int Red, Green, Blue;
};

//16bit colors
#pragma pack(push, 1)
struct Color16Struct
{
	Color16Struct() = default;

	explicit Color16Struct(ColorStruct const color) :
		R(static_cast<unsigned short>(color.R >> 3u)),
		G(static_cast<unsigned short>(color.G >> 2u)),
		B(static_cast<unsigned short>(color.B >> 3u))
	{ }

	bool operator == (Color16Struct const rhs) const {
		return R == rhs.R && G == rhs.G && B == rhs.B;
	}

	bool operator != (Color16Struct const rhs) const {
		return !(*this == rhs);
	}

	unsigned short R : 5;
	unsigned short G : 6;
	unsigned short B : 5;
};
#pragma pack(pop)

inline ColorStruct::ColorStruct(Color16Struct const color) :
	R(static_cast<BYTE>(color.R << 3)),
	G(static_cast<BYTE>(color.G << 2)),
	B(static_cast<BYTE>(color.B << 3))
{ }

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
