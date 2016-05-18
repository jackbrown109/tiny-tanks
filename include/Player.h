#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Sprite.h"
#include "mathLib.h"

#define MAX_BULLETS 8

class Player 
{
public:
	//\===================================================
	//\ Constructors
	//\===================================================
	Player(const char* a_textureFileName, const char* a_turretTexture, const char* a_bulletTexture, float a_width, float a_height);
	
	//\===================================================
	//\ Destructor 
	//\===================================================
	virtual ~Player();

	bool isAlive;
	void SetPosition(Vector2 a_v2 );
	void SetBoundary(Vector2 a_v2);
	
	void Update(float a_fDeltaTime);
	void Draw();

protected:

private:
	Sprite* m_pSprite;
	Sprite* m_pTurret;
	Sprite* m_pBullet[MAX_BULLETS];

	int iScreenWidth;
	int iScreenHeight;
	
};

#endif //__PLAYER_H__