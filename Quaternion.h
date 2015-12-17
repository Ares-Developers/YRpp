#pragma once

// an imaginary³ world where only one quarter is real.
// obviously, this class needs some serious expansion
// if it is to be used for serious stuff.

class Quaternion
{
public:
	Quaternion() = default;
	Quaternion(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) {}

	float X{ 0.0f };
	float Y{ 0.0f };
	float Z{ 0.0f };
	float W{ 0.0f }; // the real part
};
