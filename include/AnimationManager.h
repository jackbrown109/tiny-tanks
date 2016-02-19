#pragma once
#ifndef __ANIMATION_MANAGER_H__
#define __ANIMATION_MANAGER_H__

#include <map>
#include <vector>
#include <string>

#include "mathLib.h"

struct AnimationFrame
{
	CVector4 uvCoordinates;
	CVector2 v2Origin;
	CVector2 v2Scale;

};

struct Animation
{
	std::string name;
	std::vector<AnimationFrame> frames;
	float framerate;
	bool horizontalFilp;
	bool verticalFlip;
};

class AnimationManager
{
public:
	AnimationManager();
	~AnimationManager();

	bool LoadAnimationsFromFile(const char*		a_pFileName);
	const Animation* GetAnimation(const char*	a_animName);
private:
	//Animations are stored in a map accessed by a hash of the animation name
	//a hash is used as string comparisons are slow when searching for an animation
	std::map< unsigned int, Animation > m_animations;
};

#endif //__ANIMATION_MANAGER_H__