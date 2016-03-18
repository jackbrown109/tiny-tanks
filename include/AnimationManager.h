#pragma once
#ifndef __ANIMATION_MANAGER_H__
#define __ANIMATION_MANAGER_H__

#include <map>
#include <vector>
#include <string>

#include "Manager.h"
#include "mathLib.h"

struct AnimationFrame
{
	CVector4 uvCoordinates;
	CVector2 v2Origin;
	CVector2 v2Scale;

};

struct Animation
{
	Animation() {
		name.reserve(32);
		textureName.reserve(32);
		frames.resize(1);
		framerate = 0;
		horizontalFilp = 0;
		verticalFlip = 0;
	}
	std::string name;
	std::string textureName;
	std::vector<AnimationFrame> frames;
	float framerate;
	bool horizontalFilp;
	bool verticalFlip;
	
	
};

class AnimationManager : public Manager<AnimationManager>
{
	friend class Manager<AnimationManager>;
protected:
	AnimationManager();
	virtual ~AnimationManager();
	
public:
	
	bool LoadAnimationsFromFile(const char*		a_pFileName);
	const Animation* GetAnimation(const char*	a_animName);


private:
	//Animations are stored in a map accessed by a hash of the animation name
	//a hash is used as string comparisons are slow when searching for an animation
	std::map< unsigned int, Animation* > m_animations;

};

#endif //__ANIMATION_MANAGER_H__