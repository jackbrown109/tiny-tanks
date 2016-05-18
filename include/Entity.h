#pragma once
#include "mathLib.h"
#include <set>
#include <iostream>

#ifndef __ENTITY_H__
#define __ENTITY_H__


class Entity
{
public:
	//\===================================================
	//\ Constructors
	//\===================================================
	Entity(const char* a_textureFileName, float a_width, float a_height);

	//\===================================================
	//\ Copy Constructor
	//\===================================================
	Entity(const Entity& a_Entity);
	//\===================================================
	//\ Destructor (Virtual so child classes will call it upon destruction)
	//\===================================================
	virtual ~Entity();

	//\===================================================
	//\ Set position and movement for child classes to inherit
	//\===================================================
	void SetPosition(float a_x, float a_y);
	//void SetPosition(Vector2 a_pos);
	void GetPosition(float& a_x, float& a_y);
	//void GetPosition(Vector2& a_pos);
	//void Rotate(Vector2& a_rot);
	void GetSize(float& a_Width, float& a_Height) const;
	//Vector2 getRotateVector();
	int  GetSpriteID();
	void SetVelocity(int a_x, int a_y);
	void SetBoundary(const float& a_x, const float& a_y);




	virtual void Update(float a_fDeltaTime);
	void Draw();
protected:

	unsigned int m_iSpriteID;

	float m_fWidth;
	float m_fHeight;
	//Vector2 m_v2Size;

	
	int iScreenWidth = 0, iScreenHeight = 0;

	float m_xPos;
	float m_yPos;
	//Vector2 m_v2Pos;
	//Vector2 m_v2Rot;
	int Vector2pos;
	int m_velX;
	int m_velY;

	float Vector2pos;
	float PI = 3.14159265359;

	float fCurrentVelocity = 0.f;
	float fMaxVelocity = 10.f;
	float fDrag = 0.03f;
	



private:


};






//=================================================================================================================================

#endif //__ENTITY_H__

