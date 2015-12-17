/*
	Ballistic trajectory data used by Animations and Voxel Animations.
*/

#pragma once

#include <GeneralStructures.h>
#include <YRMathVector.h>
#include <Quaternion.h>

class BounceClass
{
public:
	enum class Status : int {
		None = 0,
		Bounce = 1,
		Impact = 2
	};

	// constructors
	BounceClass() = default;

	BounceClass(const CoordStruct& coords, double elasticity, double gravity,
		double maxVelocity, const Vector3D<float>& velocity, double angularVelocity)
	{
		this->Initialize(coords, elasticity, gravity, maxVelocity, velocity, angularVelocity);
	}

	void Initialize(const CoordStruct& coords, double elasticity, double gravity,
			double maxVelocity, const Vector3D<float>& velocity, double angularVelocity)
		{ JMP_THIS(0x4397E0); }

	CoordStruct* GetCoords(CoordStruct* pBuffer) const
		{ JMP_THIS(0x4399A0); }

	CoordStruct GetCoords() const {
		CoordStruct buffer;
		this->GetCoords(&buffer);
		return buffer;
	}

	Matrix3DStruct* GetDrawingMatrix(Matrix3DStruct* pBuffer) const
		{ JMP_THIS(0x4399E0); }

	Matrix3DStruct GetDrawingMatrix() const {
		Matrix3DStruct buffer;
		this->GetDrawingMatrix(&buffer);
		return buffer;
	}

	Status Update()
		{ JMP_THIS(0x439B00); }

	double Elasticity{ 0.0 }; // speed multiplier when bouncing off the ground
	double Gravity{ 0.0 }; // subtracted from the Z coords every frame
	double MaxVelocity{ 0.0 }; // 0.0 disables check
	Vector3D<float> Coords; // position with precision
	Vector3D<float> Velocity; // speed components
	Quaternion CurrentAngle; // quaternion for drawing
	Quaternion AngularVelocity; // second quaternion as per-frame delta
};

