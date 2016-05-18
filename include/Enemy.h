#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Entity.h"

class Enemy : public Entity
{
public:
	//\===================================================
	//\ Constructors
	//\===================================================

	//\===================================================
	//\ Destructor
	//\===================================================
	~Enemy();




	void Update(float a_fDeltaTime);
	void Draw();
protected:




private:


};

#endif //__ENEMY_H__