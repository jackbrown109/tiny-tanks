#pragma once
#ifndef __ANIMATION_MANAGER_H__
#define __ANIMATION_MANAGER_H__

#include <map>
#include <vector>
#include <string>

#include "Manager.h"
#include "Animation.h"
#include "mathLib.h"



class ResourceManager : public Manager<ResourceManager>
{
	friend class Manager<ResourceManager>;
protected:
	ResourceManager();
	virtual ~ResourceManager();
	
public:
	
	void LoadAnimationsFromFile(const char*		a_pFileName, std::map< unsigned int, Animation* >& a_animations);
	void RemoveAllAnimations();

private:
	//Animations are stored in a map accessed by a hash of the animation name
	//a hash is used as string comparisons are slow when searching for an animation
	std::map< unsigned int, std::map< unsigned int, Animation* > > m_animations;

};

#endif //__ANIMATION_MANAGER_H__