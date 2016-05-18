#include "Turret.h"
#include "UGFW.h"
#include "Enumerations.h"
#include "Entity.h"
#include "Player.h"


//\===================================================
//\ Constructors
//\===================================================
Turret::Turret(const char* a_textureFileName, float a_width, float a_height) : Entity(a_textureFileName, a_width, a_height)
{

}
//\===================================================
//\ Destructor
//\===================================================
Turret::~Turret()
{

}

int Turret::GetSpriteID()
{
	return Entity::GetSpriteID();
}




void Turret::Update(float a_fDeltaTime)
{	
	if (UG::IsKeyDown(UG::KEY_Q))
	{
		UG::RotateSprite(m_iSpriteID, 5.f);
	}
	if (UG::IsKeyDown(UG::KEY_E))
	{
		UG::RotateSprite(m_iSpriteID, -5.f);
	}
}