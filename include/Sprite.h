#pragma once

#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "Node.h"
#include "Animation.h"
#include <map>

//A very simple sprite class that extends from node allowing us to have a sprite hierarchy tree in our game
class Sprite : public CNode {
public:
	//Constructor -- makes a UG Sprite object for us to use
	Sprite(const char* a_fileName, int a_width, int a_height, CVector2 a_origin, CVector4 a_UVCoords);
	//Destructor
	virtual ~Sprite();
	//Set our sprite layer
	void SetLayer(unsigned int a_uiLayer);
	//an update function to call each frame to update our sprites data
	void Update(float a_fdt);
	//Function to move our sprite
	// The movement vector argument is not guaranteed to be a unit vector as we may be moving scaled by a velocity
	void MoveSprite(CVector4 a_movementVec);

	void MarkForDraw();
	void StopDrawing();

	void SetPosition(CVector2 a_pos);

	void LoadAnimations(const char* a_animationFilename);
	void SetAnimation(const char* a_animName);
	
	Animation* GetAnimation(const char* a_pAnimName);

private:
	int m_iSpriteID;
	int m_iWidth;
	int m_iHeight;
	CVector2 m_v2Origin;
	Animation* m_CurrentAnimation;
	std::map< unsigned int, Animation* > m_animations;

};

#endif //__SPRITE_H__