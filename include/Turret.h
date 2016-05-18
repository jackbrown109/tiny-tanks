#pragma once
#ifndef __TURRET_H__
#define __TURRET_H__

#include "Entity.h"


class Turret : public Entity 
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
	
	virtual int GetSpriteID();


	void Update(float a_fDeltaTime);

protected:

	


private:


};

#endif //__TURRET_H__

