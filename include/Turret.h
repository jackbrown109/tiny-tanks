#pragma once
#ifndef __TURRET_H__
#define __TURRET_H__

#include "Sprite.h"
#include "mathLib.h"


class Turret
{
public:
	//\===================================================
	//\ Constructors
	//\===================================================
	Turret(const char* a_textureFileName, float a_width, float a_height);


	//\===================================================
	//\ Destructor
	//\===================================================
	virtual ~Turret();
	


	void Update(float a_fDeltaTime);
	void Draw();
protected:

	


private:
	

};

#endif //__TURRET_H__

