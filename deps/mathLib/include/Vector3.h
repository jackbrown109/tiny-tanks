
#pragma once

#ifndef __VECTOR3_H__
#define __VECTOR3_H__

#include "mathLib.h"

// Class that implements a 3-dimensional float vector

class Vector3
{
public:

	//Member Variables held in unnamed union for accessibility
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};
		struct
		{
			float i[3];
		};
	};


	//\===================================================
	//\ Constant Vectors
	//\===================================================
	static const Vector3 ONE;
	static const Vector3 ZERO;
	static const Vector3 AXIS_X;
	static const Vector3 AXIS_Y;
	static const Vector3 AXIS_Z;
	//\===================================================
	//\ Constructors
	//\===================================================
	Vector3();
	Vector3(const Vector3& a_v3);
	Vector3(const float a_fVal);
	Vector3(float a_x, float a_y, float a_z);

	//Vector3(const Vector2& a_xy, float a_z = 1.f);
	//explicit Vector3(const float* a_v3fp);

	//\===================================================
	//\ Destructor
	//\===================================================
	~Vector3();
	//\===================================================
	//\ Casting Operators
	//\===================================================
	operator float*		();
	operator const		float*		() const;
	//\===================================================
	//\ Accessor Operators
	//\===================================================
	void				Get(float& a_x, float& a_y, float& a_z) const;
	void				Set(const float& a_x, const float& a_y, const float& a_z);
	//\===================================================
	//\ Equivalence Operators
	//\===================================================
	bool				operator ==		(const Vector3& a_v3) const;
	bool				operator !=		(const Vector3& a_v3) const;
	//\===================================================
	//\ Neg Operator
	//\===================================================
	const Vector3		operator -		() const;
	//\===================================================
	//\ Overload Operators for Vector3 Addition
	//\===================================================
	const Vector3		operator +		(float a_fScalar) const;
	const Vector3		operator +		(const Vector3& a_v3) const;
	const Vector3&		operator +=		(float a_fScalar);
	const Vector3&		operator +=		(const Vector3& a_v3);
	//\===================================================
	//\ Overload Operators for Vector3 Subtraction
	//\===================================================
	const Vector3		operator -		(float a_fScalar) const;
	const Vector3		operator -		(const Vector3& a_v3) const;
	const Vector3&		operator -=		(float a_fScalar);
	const Vector3&		operator -=		(const Vector3& a_v3);
	//\===================================================
	//\ Overload Operators for Vector3 Multiplication
	//\===================================================
	const Vector3		operator *		(float a_fScalar) const;
	const Vector3		operator *		(const Vector3& a_v3) const;
	friend const Vector3 operator *		(float a_fScalar, const Vector3& a_v3);
	const Vector3&		operator *=		(float a_fScalar);
	const Vector3&		operator *=		(const Vector3& a_v3);
	//\===================================================
	//\ Overload Operators for Vector3 Division
	//\===================================================
	const Vector3		operator /		(float a_fScalar) const;
	const Vector3		operator /		(const Vector3& a_v3) const;
	const Vector3&		operator /=		(float a_fScalar);
	const Vector3&		operator /=		(const Vector3& a_v3);
	//\===================================================
	//\ Magnitude
	//\===================================================
	float				Length() const;
	float				Magnitude() const;
	float				LengthSquared() const;
	float				MagnitudeSquared() const;
	//\===================================================
	//\ A function to quickly shorten a vector to a desired
	//\ length. This function is good with camera controls
	//\===================================================
	void				Truncate(float a_fMaxLength);
	//\===================================================
	//\ Distance
	//\===================================================
	friend float		Distance(const Vector3& a_v3A, const Vector3& a_v3B);
	friend float		DistanceSquared(const Vector3& a_v3A, const Vector3& a_v3B);
	//\===================================================
	//\ Dot Product
	//\===================================================
	float				Dot(const Vector3& a_v3);
	friend float		Dot(const Vector3& a_v3A, const Vector3& a_v3B);
	//\===================================================
	//\ Normalisation
	//\===================================================
	bool				IsUnit() const;
	void				Normalise();
	const Vector3		GetUnit() const;
	//\===================================================
	//\ Cross Product
	//\===================================================
	const Vector3		Cross(const Vector3& a_v3) const;
	friend const Vector3	Cross(const Vector3& a_v3A, const Vector3& a_v3B);
	//\===================================================
	//\ Rotation Functions
	//\===================================================
	void				RotateX(float a_fAngle);
	void				RotateY(float a_fAngle);
	void				RotateZ(float a_fAngle);
	//\===================================================
	//\ Other Useful Functions
	//\===================================================
	void				Zero();
	void				One();
	float				Min() const;
	float				Max() const;

};

#endif //__VECTOR3_H__
