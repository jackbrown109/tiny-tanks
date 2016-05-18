#pragma once

#ifndef __MATRIX3_H__
#define __MATRIX3_H__

#include "mathLib.h"

class Vector3;

class Matrix3
{
public:

	//\===================================================
	//\ Member Variables held in unnamed union for accessibility
	//\===================================================
	union
	{
		float m[3][3];
		struct
		{
			float m_11, m_12, m_13;
			float m_21, m_22, m_23;
			float m_31, m_32, m_33;
		};
	};
	//\===================================================
	//\ Constants
	//\===================================================
	static const Matrix3 ONE;
	static const Matrix3 ZERO;
	static const Matrix3 IDENTITY;
	//\===================================================
	//\ Constructors
	//\===================================================
	Matrix3();
	Matrix3(const float* mat);
	Matrix3(	float m_11, float m_12, float m_13,
				float m_21, float m_22, float m_23,
				float m_31, float m_32, float m_33);
	Matrix3(Matrix3& a_m3);
	//\===================================================
	//\ Destructor
	//\===================================================
	~Matrix3();
	//\===================================================
	//\ Casting Operators
	//\===================================================
	operator float*();
	operator const float*() const;
	//\===================================================
	//\ Component Access Operators
	//\===================================================
	float&				operator () (int iRow, int iCol);
	float				operator () (int iRow, int iCol) const;
	//\===================================================
	//\ Cols and Rows Access
	//\===================================================
	void				SetCol(int iCol, const Vector3 vCol);
	void				SetRow(int iRow, const Vector3& vRow);
	Vector3				GetCol(int iCol) const;
	Vector3				GetRow(int iRow) const;
	void				GetCol(int iCol, Vector3& vCol) const;
	void				GetRow(int iRow, Vector3& vRow) const;
	//\===================================================
	//\ Equivalence Operators
	//\===================================================
	bool				operator == (const Matrix3& a_m3) const;
	bool				operator != (const Matrix3& a_m3) const;
	//\===================================================
	//\ Operator Overloads for Addition
	//\===================================================
	const Matrix3		operator + (const Matrix3& a_m3) const;
	const Matrix3		operator += (const Matrix3& a_m3);
	//\===================================================
	//\ Operator Overloads for Subtraction
	//\===================================================
	const Matrix3		operator - (const Matrix3& a_m3) const;
	const Matrix3		operator -= (const Matrix3& a_m3);
	//\===================================================
	//\ Operator Overloads for Multiplication
	//\===================================================
	const Matrix3		operator * (const float a_fScalar) const;
	friend const Matrix3 operator * (const float a_fScalar, const Matrix3& a_m3);
	const Matrix3&		operator *= (const float a_fScalar);
	const Vector3		operator * (const Vector3& a_v3) const;
	friend const Vector3 operator * (const Vector3& a_v3, const Matrix3& a_m3);

	const Matrix3		operator * (const Matrix3& a_m3) const;
	const Matrix3&		operator *= (const Matrix3& a_m3);
	//\===================================================
	//\ Transpose Matrix- Transform from Row to Column
	//\===================================================
	void				Transpose();
	void				GetTranspose(Matrix3 &a_m3);
	//\===================================================
	//\ Inverse- Get Inverse of the Matrix
	//\===================================================
	float				Determinant() const;
	bool				Inverse();
	bool				GetInverse(Matrix3 &a_m3) const;
	//\===================================================
	//\ Rotation Functions
	//\===================================================
	void				RotateX(float fAngle);
	void				RotateY(float fAngle);
	void				RotateZ(float fAngle);
	//\===================================================
	//\ Orthonormalisation Functions
	//\===================================================
	void				OrthoNormalise();
	void				GramSchmidtOrtho();
	//\===================================================
	//\ Scale Functionality
	//\===================================================
	void				Scale(const Vector3& a_v3);
	void				Scale(float a_fScalar);
	//\===================================================
	//\ General Matrix Functions
	//\===================================================
	void				Identity();
	void				Zero();

};

#endif //__MATRIX3_H__