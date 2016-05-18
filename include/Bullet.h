#pragma once
#ifndef __BULLET_H__
#define __BULLET_H__

#include "Sprite.h"
#include "mathLib.h"



class Bullet
{
public:
	//\===================================================
	//\ Constructors
	//\===================================================
	Bullet(const char* a_textureFileName, float a_width, float a_height);


	//\===================================================
	//\ Destructor
	//\===================================================
	~Bullet();




	void Update(float a_fDeltaTime);
	void Draw();



	bool isAlive;


protected:




private:
	


};

#endif //__BULLET_H__
