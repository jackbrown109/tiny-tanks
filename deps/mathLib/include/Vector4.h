#pragma once

#ifndef __VECTOR4_H__
#define __VECTOR4_H__

#include "mathLib.h"

class Vector4
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
			float t;
		};
		struct
		{
			float i[4];
		};
	};
	//\===================================================
	//\ Constant Vectors
	//\===================================================
	static const Vector4 ONE;
	static const Vector4 ZERO;
	static const Vector4 AXIS_X;
	static const Vector4 AXIS_Y;
	static const Vector4 AXIS_Z;
	//\===================================================
	//\ Constructors
	//\===================================================
	Vector4();
	Vector4(const Vector4& a_v4);
	Vector4(const float a_fVal);
	Vector4(float a_x, float a_y, float a_z, float a_t);
	//\===================================================
	//\ Destructor
	//\===================================================
	~Vector4();
	//\===================================================
	//\ Casting Operators
	//\===================================================
	operator float*		();
	operator const		float*		() const;
	//\===================================================
	//\ Accessor Operators
	//\===================================================
	void						Get(float& a_x, float& a_y, float& a_z, float& a_t) const;
	void						Set(const float& a_x, const float& a_y, const float& a_z, const float& a_t);
	//\===================================================
	//\ Equivalence Operators
	//\===================================================
	bool				operator ==		(const Vector4& a_v4) const;
	bool				operator !=		(const Vector4& a_v4) const;
	//\===================================================
	//\ Neg Operator
	//\===================================================
	const Vector4		operator -		() const;
	//\===================================================
	//\ Overload Operators for Vector4 Addition
	//\===================================================
	const Vector4		operator +		(float a_fScalar) const;
	const Vector4		operator +		(const Vector4& a_v4) const;
	const Vector4&		operator +=		(float a_fScalar);
	const Vector4&		operator +=		(const Vector4& a_v4);
	//\===================================================
	//\ Overload Operators for Vector4 Subtraction
	//\===================================================
	const Vector4		operator -		(float a_fScalar) const;
	const Vector4		operator -		(const Vector4& a_v4) const;
	const Vector4&		operator -=		(float a_fScalar);
	const Vector4&		operator -=		(const Vector4& a_v4);
	//\===================================================
	//\ Overload Operators for Vector4 Multiplication
	//\===================================================
	const Vector4		operator *		(float a_fScalar) const;
	const Vector4		operator *		(const Vector4& a_v4) const;
	friend const Vector4 operator *		(float a_fScalar, const Vector4& a_v4);
	const Vector4&		operator *=		(float a_fScalar);
	const Vector4&		operator *=		(const Vector4& a_v4);
	//\===================================================
	//\ Overload Operators for Vector4 Division
	//\===================================================
	const Vector4		operator /		(float a_fScalar) const;
	const Vector4		operator /		(const Vector4& a_v4) const;
	const Vector4&		operator /=		(float a_fScalar);
	const Vector4&		operator /=		(const Vector4& a_v4);
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
	friend float		Distance(const Vector4& a_v4A, const Vector4& a_v4B);
	friend float		DistanceSquared(const Vector4& a_v4A, const Vector4& a_v4B);
	//\===================================================
	//\ Dot Product
	//\===================================================
	float				Dot(const Vector4& a_v4);
	friend float		Dot(const Vector4& a_v4A, const Vector4& a_v4B);
	//\===================================================
	//\ Normalisation
	//\===================================================
	bool				IsUnit() const;
	void				Normalise();
	const Vector4		GetUnit() const;
	//\===================================================
	//\ Cross Product
	//\===================================================
	const Vector4		Cross(const Vector4& a_v4) const;
	friend const Vector4	Cross(const Vector4& a_v4A, const Vector4& a_v4B);
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
	
private:

};

#endif //__VECTOR4_H__