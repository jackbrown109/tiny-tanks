

#ifndef __VECTOR2_H__
#define __VECTOR2_H__



class Vector2
{
public:
//#pragma region Member Variables Union
	union
	{
		struct
		{
			float x;
			float y;
		};		
		struct
		{
			float u;
			float v;
		};
		struct
		{
			float i[2];
		};
	};

//	#pragma endregion
	#pragma region Constant Vectors

	//\===================================================
	//\ Constant Vectors
	//\===================================================
	static const Vector2 ONE;
	static const Vector2 ZERO;
	static const Vector2 AXIS_X;
	static const Vector2 AXIS_Y;
	#pragma endregion
	#pragma region Constructors/Destructors
	//\===================================================
	//\ Constructors
	//\===================================================
	Vector2();
	Vector2(const float a_x, const float a_y);
	explicit Vector2(const float* a_i);
	Vector2(const Vector2& a_v2);
	//\===================================================
	//\ Destructor
	//\===================================================
	~Vector2();
	#pragma endregion
	#pragma region Casting Operators
	//\===================================================
	//\ Casting Operators
	//\===================================================
	operator					float* ();
	operator const				float*() const;
	#pragma endregion
	//\===================================================
	//\ Accessor Operators
	//\===================================================
	void						Get(float& a_x, float& a_y) const;
	void						Set(const float& a_x, const float& a_y);
	//\===================================================
	//\ Equivalence Operators
	//\===================================================
	bool						operator == (const Vector2& a_v2) const;
	bool						operator !=(const Vector2 a_v2) const;
	//\===================================================
	//\ Neg Operator
	//\===================================================
	const Vector2				operator -() const;
	//\===================================================
	//\ Overload Operators for Vector2 Addition
	//\===================================================
	const Vector2		operator +		(float a_fScalar) const;
	const Vector2		operator +		(const Vector2& a_v2) const;
	const Vector2&		operator +=		(float a_fScalar);
	const Vector2&		operator +=		(const Vector2& a_v2);
	//\===================================================
	//\ Overload Operators for Vector2 Subtraction
	//\===================================================
	const Vector2		operator -		(float a_fScalar) const;
	const Vector2		operator -		(const Vector2& a_v2) const;
	const Vector2&		operator -=		(float a_fScalar);
	const Vector2&		operator -=		(const Vector2& a_v2);
	//\===================================================
	//\ Overload Operators for Vector2 Multiplication
	//\===================================================
	const Vector2		operator *		(float a_fScalar) const;
	const Vector2		operator *		(const Vector2& a_v2) const;
	friend const Vector2 operator *		(float a_fScalar, const Vector2& a_v2);
	const Vector2&		operator *=		(float a_fScalar);
	const Vector2&		operator *=		(const Vector2& a_v2);
	//\===================================================
	//\ Overload Operators for Vector2 Division
	//\===================================================
	const Vector2		operator /		(float a_fScalar) const;
	const Vector2		operator /		(const Vector2& a_v2) const;
	const Vector2&		operator /=		(float a_fScalar);
	const Vector2&		operator /=		(const Vector2& a_v2);
	//\===================================================
	//\ Magnitude
	//\===================================================
	float				Length() const;
	float				Magnitude() const;
	float				LengthSquared() const;
	float				MagnitudeSquared() const;
	//\===================================================
	//\ Distance
	//\===================================================
	friend float					Distance(const Vector2& a_v2A, const Vector2& a_v2B);
	friend float					DistanceSquared(const Vector2& a_v2A, const Vector2& a_v2B);
	//\===================================================
	//\ Dot Product
	//\===================================================
	float				Dot(const Vector2& a_v2A, const Vector2& a_v2B);
	friend float		Dot(const Vector2& a_v2A, const Vector2& a_v2B);
	//\===================================================
	//\ Normalisation
	//\===================================================
	bool				IsUnit() const;
	Vector2				Normalise();
	const Vector2		GetUnit() const;
	//\===================================================
	//\ Get Perpendicular
	//\===================================================
	Vector2			GetPerpendicular() const;
	//\===================================================
	//\ Transformation Functions
	//\===================================================
	void				Rotate(float fAngle);
	void				Project(float fAngle, float fDistance);
	//\===================================================
	//\ Linear Interpolation and Bilinear Interpolation
	//\===================================================
	friend Vector2			Lerp(const Vector2& vecA, const Vector2& vecB, float t);

	//friend Vector2			biLerp(const Vector2 vec[4], float fU, float fV);

	friend Vector2			QuadBezier(Vector2 vecA, Vector2 vecB, Vector2 vecC, float t);
	friend Vector2			HermiteSpline(Vector2 point0, Vector2 point1, Vector2 tangent0, Vector2 tangent1, float t);
	friend Vector2			CardinalSpline(Vector2 point0, Vector2 point1, Vector2 point2, float a, float t);
	//\===================================================
	//\ Other useful functions
	//\===================================================
	void				Zero();
	void				One();
	float				Min() const;
	float				Max() const;

private:

};


#endif //__VECTOR2_H__
