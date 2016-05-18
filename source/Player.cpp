#include "Player.h"
#include "UGFW.h"
#include "Enumerations.h"
#include "Turret.h"
#include "Bullet.h"


Player::Player(const char* a_textureFileName, float a_width, float a_height) : Entity(a_textureFileName, a_width, a_height)
{


}



Player::~Player()
{

}

int Player::GetSpriteID()
{
	return Entity::GetSpriteID();
}

void Player::Update(float a_fTimeStep)
{

	float posy;
	float posx;

	int iScreenWidth = 0, iScreenHeight = 0;
	UG::GetScreenSize(iScreenWidth, iScreenHeight);

	float topBoundary = (iScreenHeight * 1.f);
	float bottomBoundary = (iScreenHeight * 0.f);
	float leftBoundary = (iScreenWidth * 0.f);
	float rightBoundary = (iScreenWidth * 1.f);
	float tankWidth = 26.f;
	GetPosition(posx, posy);

	if (UG::IsKeyDown(UG::KEY_RIGHT) && posx + tankWidth < rightBoundary)
	{
		GetPosition(posx, posy);
		//UG::MoveSprite(iPlayerSprite, posx + 2.f, posy);
		SetPosition(posx + 2.f, posy);      //change to alter speed to the right
	}
	if (UG::IsKeyDown(UG::KEY_LEFT) && posx - tankWidth > leftBoundary)
	{
		GetPosition(posx, posy);
		//UG::MoveSprite(iPlayerSprite, posx - 2.f, posy);
		SetPosition(posx - 2.f, posy);     //change to alter speed to the left
	}
	if (UG::IsKeyDown(UG::KEY_UP) && posy + tankWidth < topBoundary)
	{
		GetPosition(posx, posy);
		//UG::MoveSprite(iPlayerSprite, posx, posy + 2.f);
		SetPosition(posx,posy + 2.f);
	}
	if (UG::IsKeyDown(UG::KEY_DOWN) && posy - tankWidth > bottomBoundary)
	{
		GetPosition(posx, posy);
		//UG::MoveSprite(iPlayerSprite, posx, posy - 2.f);
		SetPosition(posx,posy - 2.f);
	}



	/*if (UG::IsKeyDown(UG::KEY_SPACE))
	{
		bool isAlive = true;
	}*/




}

// && (posy >69)
//&& (posx < 1003)
//&& (posx > 23)
// && (posy < 745)

void Player::Draw()
{
	UG::DrawSprite(m_iSpriteID);
}

