/*
	Ballistic trajectory data used by Animations and Voxel Animations.
*/

#ifndef BOUNCE_H
#define BOUNCE_H

#include <GeneralStructures.h>
#include <YRMathVector.h>
#include <Quaternion.h>

class BounceClass
{
public:
	class Status {
		public:
		typedef int Value;
		enum {
			None = 0,
			Bounce = 1,
			Impact = 2
		};
	};

	// constructors
	BounceClass() : Elasticity(0.0), Gravity(0.0), MaxVelocity(0.0) {}

	BounceClass(CoordStruct* pCoords, double elasticity, double gravity,
		double maxVelocity, Vector3D<float>* velocity, double angularVelocity)
	{
		this->Initialize(pCoords, elasticity, gravity, maxVelocity, velocity, angularVelocity);
	}

	void Initialize(CoordStruct* pCoords, double elasticity, double gravity,
			double maxVelocity, Vector3D<float>* velocity, double angularVelocity)
		{ JMP_THIS(0x4397E0); }

	CoordStruct* GetCoords(CoordStruct* pBuffer) const
		{ JMP_THIS(0x4399A0); }

	Matrix3DStruct* GetDrawingMatrix(Matrix3DStruct* pBuffer) const
		{ JMP_THIS(0x4399E0); }

	Status::Value Update()
		{ JMP_THIS(0x439B00); }

	double Elasticity; // speed multiplier when bouncing off the ground
	double Gravity; // subtracted from the Z coords every frame
	double MaxVelocity; // 0.0 disables check
	Vector3D<float> Coords; // position with precision
	Vector3D<float> Velocity; // speed components
	Quaternion CurrentAngle; // quaternion for drawing
	Quaternion AngularVelocity; // second quaternion as per-frame delta
};

#endif
