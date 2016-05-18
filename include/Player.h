#pragma once
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Entity.h"

class Player : public Entity
{
public:
	//\===================================================
	//\ Constructors
	//\===================================================
	Player(const char* a_textureFileName, float a_width, float a_height);

	//\===================================================
	//\ Destructor 
	//\===================================================
	virtual ~Player();

	virtual int GetSpriteID();

	

	void Update(float a_fDeltaTime);
	void Draw();
protected:




private:
	
	int iScreenWidth;
	int iScreenHeight;

};

#endif //__PLAYER_H__