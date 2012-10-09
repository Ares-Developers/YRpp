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
	void operator=(Vector2D a)
	{
		X=a.X;Y=a.Y;
	}
	//addition
	Vector2D operator+(Vector2D a)
	{
		Vector2D v={X+a.X,Y+a.Y};
		return v;
	}
	//addition
	void operator+=(Vector2D a)
	{
		X+=a.X;Y+=a.Y;
	}
	//substraction
	Vector2D operator-(Vector2D a)
	{
		Vector2D v={X-a.X,Y-a.Y};
		return v;
	}
	//substraction
	void operator-=(Vector2D a)
	{
		X-=a.X;Y-=a.Y;
	}
	//negation
	Vector2D operator-()
	{
		Vector2D v={-X,-Y};
		return v;
	}
	//equality
	bool operator==(Vector2D a)
	{
		return (X==a.X && Y==a.Y);
	}
	//unequality
	bool operator!=(Vector2D a)
	{
		return (X!=a.X || Y!=a.Y);
	}
	//scalar multiplication
	Vector2D operator*(double r)
	{
		Vector2D v={(T)(X*r),(T)(Y*r)};
		return v;
	}
	//scalar multiplication
	Vector2D operator*=(double r)
	{
		X*=r;Y*=r;
	}
	//vector multiplication
	double operator*(Vector2D a)
	{
		return (double)(X*a.X+Y*a.Y);
	}
	//magnitude
	double Magnitude()
	{
		return sqrt((double)(X*X+Y*Y));
	}
	//distance from another vector
	double DistanceFrom(Vector2D a)
	{
		return (a-(*this)).Magnitude();
	}
	//collinearity
	bool IsCollinearTo(Vector2D a)
	{
		double r=(double)a.X/(double)X;
		return ((T)(r*Y)==a.Y);
	}
	//find scalar
	double FindScalar(Vector2D a)
	{
		double r=(double)a.X/(double)X;
		if((T)(r*Y)==a.Y)
			return r;
		else
		{
			//the vectors are not collinear, return NaN!
			unsigned long NaN[2]={0xFFFFFFFF,0x7FFFFFFF};
			return *(double*)NaN;
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
	void operator=(Vector3D a)
	{
		X = a.X; Y = a.Y; Z = a.Z;
	}
	//addition
	Vector3D operator+(Vector3D a)
	{
		Vector3D v={X+a.X,Y+a.Y,Z+a.Z};
		return v;
	}
	//addition
	void operator+=(Vector3D a)
	{
		X+=a.X;Y+=a.Y,Z+=a.Z;
	}
	//substraction
	Vector3D operator-(Vector3D a)
	{
		Vector3D v={X-a.X,Y-a.Y,Z-a.Z};
		return v;
	}
	//substraction
	void operator-=(Vector3D a)
	{
		X-=a.X;Y-=a.Y;Z-=a.Z;
	}
	//negation
	Vector3D operator-()
	{
		Vector3D v={-X,-Y,-Z};
		return v;
	}
	//equality
	bool operator==(Vector3D a)
	{
		return (X==a.X && Y==a.Y && Z==a.Z);
	}
	//unequality
	bool operator!=(Vector3D a)
	{
		return (X!=a.X || Y!=a.Y || Z!=a.Z);
	}
	//scalar multiplication
	Vector3D operator*(double r)
	{
		Vector3D v={(T)(X*r),(T)(Y*r),(T)(Z*r)};
		return v;
	}
	//scalar multiplication
	Vector3D operator*=(double r)
	{
		X*=r;Y*=r;Z*=r;
	}
	//vector multiplication
	double operator*(Vector3D a)
	{
		return (double)(X*a.X+Y*a.Y+Z*a.Z);
	}
	//magnitude
	double Magnitude()
	{
		return sqrt(((double)X)*X+((double)Y)*Y+((double)Z)*Z);
	}
	//distance from another vector
	double DistanceFrom(Vector3D a)
	{
		return (a-(*this)).Magnitude();
	}
	//collinearity
	bool IsCollinearTo(Vector3D a)
	{
		double r=(double)a.X/(double)X;
		return ((T)(r*Y)==a.Y) && ((T)(r*Z)==a.Z);
	}
	//find scalar
	double FindScalar(Vector3D a)
	{
		double r=(double)a.X/(double)X;
		if(((T)(r*Y)==a.Y) && ((T)(r*Z)==a.Z))
			return r;
		else
		{
			//the vectors are not collinear, return NaN!
			unsigned long NaN[2]={0xFFFFFFFF,0x7FFFFFFF};
			return *(double*)NaN;
		}
	}
	//cross product
	Vector3D CrossProduct(Vector3D a)
	{
		Vector3D v={
			Y*a.Z-Z*a.Y,
			Z*a.X-X*a.Z,
			X*a.Y-Y*a.X};
		return v;
	}
};

template <typename T>
const Vector3D<T> Vector3D<T>::Empty = {T(), T(), T()};

#endif
