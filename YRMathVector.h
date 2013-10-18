//pd's Vector classes (math sense)
#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

/*==========================================
============ 2D Vector =====================
==========================================*/

template <typename T> class Vector2D
{
public:
	static const Vector2D Empty;

	//no constructor, so this class stays aggregate and can be initialized using the curly braces {}
	T X,Y;

	//operator overloads
	//assignment
	Vector2D& operator=(const Vector2D& a)
	{
		X = a.X;
		Y = a.Y;
		return *this;
	}
	//addition
	const Vector2D operator+(const Vector2D& a) const
	{
		Vector2D v = {X + a.X, Y + a.Y};
		return v;
	}
	//addition
	Vector2D& operator+=(const Vector2D& a)
	{
		X += a.X;
		Y += a.Y;
		return *this;
	}
	//substraction
	const Vector2D operator-(const Vector2D& a) const
	{
		Vector2D v = {X - a.X, Y - a.Y};
		return v;
	}
	//substraction
	Vector2D& operator-=(const Vector2D& a)
	{
		X -= a.X;
		Y -= a.Y;
		return *this;
	}
	//negation
	const Vector2D operator-() const
	{
		Vector2D v = {-X, -Y};
		return v;
	}
	//equality
	bool operator==(const Vector2D& a) const
	{
		return (X == a.X && Y == a.Y);
	}
	//unequality
	bool operator!=(const Vector2D& a) const
	{
		return (X != a.X || Y != a.Y);
	}
	//scalar multiplication
	const Vector2D operator*(double r) const
	{
		Vector2D v = {static_cast<T>(X * r), static_cast<T>(Y * r)};
		return v;
	}
	//scalar multiplication
	Vector2D& operator*=(double r)
	{
		X *= r;
		Y *= r;
		return *this;
	}
	//vector multiplication
	double operator*(const Vector2D& a) const
	{
		return static_cast<double>(X) * a.X + static_cast<double>(Y) * a.Y;
	}
	//magnitude
	double Magnitude() const
	{
		return sqrt(static_cast<double>(X) * X + static_cast<double>(Y) * Y);
	}
	//distance from another vector
	double DistanceFrom(const Vector2D& a) const
	{
		return (a - *this).Magnitude();
	}
	//collinearity
	bool IsCollinearTo(const Vector2D& a) const
	{
		double r = static_cast<double>(a.X) / static_cast<double>(X);
		return (static_cast<T>(r * Y) == a.Y);
	}
	//find scalar
	double FindScalar(const Vector2D& a) const
	{
		double r = static_cast<T>(a.X) / static_cast<T>(X);
		if(static_cast<T>(r * Y) == a.Y) {
			return r;
		} else {
			//the vectors are not collinear, return NaN!
			unsigned long NaN[2] = {0xFFFFFFFF,0x7FFFFFFF};
			return *reinterpret_cast<double*>(NaN);
		}
	}
};

template <typename T>
const Vector2D<T> Vector2D<T>::Empty = {T(), T()};

/*==========================================
============ 3D Vector =====================
==========================================*/

template <typename T> class Vector3D
{
public:
	static const Vector3D Empty;

	//no constructor, so this class stays aggregate and can be initialized using the curly braces {}
	T X,Y,Z;

	//operator overloads
	//assignment
	Vector3D& operator=(const Vector3D& a)
	{
		X = a.X;
		Y = a.Y;
		Z = a.Z;
		return *this;
	}
	//addition
	const Vector3D operator+(const Vector3D& a) const
	{
		Vector3D v= {X + a.X, Y + a.Y, Z + a.Z};
		return v;
	}
	//addition
	Vector3D& operator+=(const Vector3D& a)
	{
		X += a.X;
		Y += a.Y;
		Z += a.Z;
		return *this;
	}
	//substraction
	const Vector3D operator-(const Vector3D& a) const
	{
		Vector3D v = {X - a.X, Y - a.Y, Z - a.Z};
		return v;
	}
	//substraction
	Vector3D& operator-=(const Vector3D& a)
	{
		X -= a.X;
		Y -= a.Y;
		Z -= a.Z;
		return *this;
	}
	//negation
	const Vector3D operator-() const
	{
		Vector3D v = {-X, -Y, -Z};
		return v;
	}
	//equality
	bool operator==(const Vector3D& a) const
	{
		return (X == a.X && Y == a.Y && Z == a.Z);
	}
	//unequality
	bool operator!=(const Vector3D& a) const
	{
		return (X != a.X || Y != a.Y || Z != a.Z);
	}
	//scalar multiplication
	const Vector3D operator*(double r) const
	{
		Vector3D v= {static_cast<T>(X * r), static_cast<T>(Y * r), static_cast<T>(Z * r)};
		return v;
	}
	//scalar multiplication
	Vector3D& operator*=(double r)
	{
		X *= r;
		Y *= r;
		Z *= r;
		return *this;
	}
	//vector multiplication
	double operator*(const Vector3D& a) const
	{
		return static_cast<double>(X) * a.X
			+ static_cast<double>(Y) * a.Y
			+ static_cast<double>(Z) * a.Z;
	}
	//magnitude
	double Magnitude() const
	{
		return sqrt(static_cast<double>(X) * X
			+ static_cast<double>(Y) * Y
			+ static_cast<double>(Z) * Z);
	}
	//distance from another vector
	double DistanceFrom(const Vector3D& a) const
	{
		return (a - *this).Magnitude();
	}
	//collinearity
	bool IsCollinearTo(const Vector3D& a) const
	{
		double r = static_cast<double>(a.X) / static_cast<double>(X);
		return (static_cast<T>(r * Y) == a.Y) && (static_cast<T>(r * Z) == a.Z);
	}
	//find scalar
	double FindScalar(const Vector3D& a) const
	{
		double r = static_cast<double>(a.X) / static_cast<double>(X);
		if((static_cast<T>(r * Y) == a.Y) && (static_cast<T>(r * Z) == a.Z)) {
			return r;
		} else {
			//the vectors are not collinear, return NaN!
			unsigned long NaN[2] = {0xFFFFFFFF,0x7FFFFFFF};
			return *reinterpret_cast<double*>(NaN);
		}
	}
	//cross product
	const Vector3D CrossProduct(const Vector3D& a) const
	{
		Vector3D v = {
			Y * a.Z - Z * a.Y,
			Z * a.X - X * a.Z,
			X * a.Y - Y * a.X};
		return v;
	}
};

template <typename T>
const Vector3D<T> Vector3D<T>::Empty = {T(), T(), T()};

#endif
