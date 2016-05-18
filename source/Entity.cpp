#include "Entity.h"
#include "UGFW.h"
#include "mathLib.h"


//\===================================================
//\ Constructors
//\===================================================
Entity::Entity(const char* a_textureFileName, float a_width, float a_height)
{
	m_iSpriteID = UG::CreateSprite(a_textureFileName, a_width, a_height);
	m_fWidth = a_width;
	m_fHeight = a_height;
}

//\===================================================
//\ Copy Constructor
//\===================================================
Entity::Entity(const Entity& a_Entity)
{
	m_iSpriteID = UG::DuplicateSprite(a_Entity.m_iSpriteID);
	m_fWidth = a_Entity.m_fWidth;
	m_fHeight = a_Entity.m_fHeight;
}
//\===================================================
//\ Destructor (Virtual so child classes will call it upon destruction)
//\===================================================
Entity::~Entity()
{
	UG::DestroySprite(m_iSpriteID);
}

//\===================================================
//\ Set position and movement for child classes to inherit
//\===================================================
void Entity::SetPosition(float a_x, float a_y)
{
	m_xPos = a_x;
	m_yPos = a_y;

	//m_v2Pos.Set(a_x, a_y);

	UG::MoveSprite(m_iSpriteID, m_xPos, m_yPos);

	
}
//ACCESS SET POSITION FROM MATH LIBRARY
/*void Entity::SetPosition(Vector2 a_pos)
{
	m_v2Pos = a_pos;
	m_xPos = a_pos.x;
	m_yPos = a_pos.y;
}*/
void Entity::GetPosition(float& a_x, float& a_y)
{
	a_x = m_xPos;
	a_y = m_yPos;
}
//ACCESS GET POSITION FROM MATH LIBRARY
/*void Entity::GetPosition(Vector2& a_pos)
{
	a_pos = m_v2Pos;
	a_pos.x = m_xPos;
	a_pos.y = m_yPos;
}
/*void Entity::Rotate(Vector2& a_rot)
{
	m_v2Rot = a_rot;

}*/
void Entity::GetSize(float& a_Width, float& a_Height) const
{

}

/*
Vector2 Entity::getRotateVector()
{
	Vector2pos;
	getPosition(pos);
	radAngle = radAngle * PI / 180;

	Vector2 pos = a_v2;

	pos.Rotate(radAngle);
	return pos;
}
*/

int Entity::GetSpriteID()
{
	return m_iSpriteID;
}

void Entity::SetVelocity(int a_x, int a_y)
{
	m_velX = a_x;
	m_velY = a_y;
}
void Entity::SetBoundary(const float& a_x, const float& a_y)
{
	
	UG::GetScreenSize(iScreenWidth, iScreenHeight);
}






void Entity::Update(float a_fDeltaTime)
{

}

void Entity::Draw()
{
	UG::DrawSprite(m_iSpriteID);
}
