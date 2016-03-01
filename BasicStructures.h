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

	explicit ColorStruct(DWORD const color) {
		memcpy(this, &color, sizeof(ColorStruct));
	}

	inline explicit ColorStruct(WORD const color);

	bool operator == (ColorStruct const rhs) const {
		return R == rhs.R && G == rhs.G && B == rhs.B;
	}

	bool operator != (ColorStruct const rhs) const {
		return !(*this == rhs);
	}

	explicit operator DWORD() const {
		DWORD ret = 0;
		memcpy(&ret, this, sizeof(ColorStruct));
		return ret;
	}

	inline explicit operator WORD() const;

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
		B(static_cast<unsigned short>(color.B >> 3u)),
		G(static_cast<unsigned short>(color.G >> 2u)),
		R(static_cast<unsigned short>(color.R >> 3u))
	{ }

	explicit Color16Struct(WORD const color) {
		memcpy(this, &color, sizeof(Color16Struct));
	}

	explicit Color16Struct(DWORD const color)
		: Color16Struct(ColorStruct(color))
	{ }

	bool operator == (Color16Struct const rhs) const {
		return R == rhs.R && G == rhs.G && B == rhs.B;
	}

	bool operator != (Color16Struct const rhs) const {
		return !(*this == rhs);
	}

	explicit operator WORD() const {
		WORD ret;
		memcpy(&ret, this, sizeof(Color16Struct));
		return ret;
	}

	explicit operator DWORD() const {
		return static_cast<DWORD>(ColorStruct(*this));
	}

	unsigned short B : 5;
	unsigned short G : 6;
	unsigned short R : 5;
};
#pragma pack(pop)

inline ColorStruct::ColorStruct(Color16Struct const color) :
	B(static_cast<BYTE>(color.B << 3u | color.B >> 2u)),
	G(static_cast<BYTE>(color.G << 2u | color.G >> 4u)),
	R(static_cast<BYTE>(color.R << 3u | color.R >> 2u))
{ }

inline ColorStruct::ColorStruct(WORD const color) :
	ColorStruct(Color16Struct(color))
{ }

ColorStruct::operator WORD() const {
	return static_cast<WORD>(Color16Struct(*this));
}

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
