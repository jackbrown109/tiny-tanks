#include "AnimationManager.h"

AnimationManager::AnimationManager()
{
	
}

AnimationManager::~AnimationManager()
{

}

bool AnimationManager::LoadAnimationsFromFile(const char* a_pFilename)
{
	return true;
}

const Animation* AnimationManager::GetAnimation(const char* a_pAnimName)
{
	unsigned int animHash = ELFHash(a_pAnimName);
	auto iter = m_animations.find(animHash);
	if (iter != m_animations.end())
	{
	}
	return nullptr;
}

