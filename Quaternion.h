#pragma once

// an imaginary³ world where only one quarter is real.
// obviously, this class needs some serious expansion
// if it is to be used for serious stuff.

class Quaternion
{
public:
	Quaternion() : X(0.0f), Y(0.0f), Z(0.0f), W(1.0f) {}
	Quaternion(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) {}

	float X, Y, Z, W; // W is the real part
};
