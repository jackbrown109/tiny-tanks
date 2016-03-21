#include "UGFW.h"
#include "ResourceManager.h"
#include "tinyxml.h"
#include "tinyxmlHelper.h"

ResourceManager::ResourceManager() : Manager<ResourceManager>()
{
	
}

ResourceManager::~ResourceManager()
{
	RemoveAllAnimations();
}

void ResourceManager::RemoveAllAnimations()
{
	///////////////////////////////////////////////////////////////
	// Removes a animations from memory
	// 
	///////////////////////////////////////////////////////////////
	std::map< unsigned int, std::map< unsigned int, Animation* > >::iterator dictionaryIter = m_animations.begin();
	for (; dictionaryIter != m_animations.end(); ++dictionaryIter)
	{
		std::map< unsigned int, Animation* > pAnimation = static_cast<std::map< unsigned int, Animation* >>(dictionaryIter->second);
		std::map< unsigned int, Animation* >::iterator iter = pAnimation.begin();
		for (; iter != pAnimation.end(); ++iter)
		{
			Animation* pAnim = static_cast<Animation*>(iter->second);
			if (pAnim)
			{
				delete pAnim;
			}
		}
	}
}

void ResourceManager::LoadAnimationsFromFile(const char* a_pFilename, std::map< unsigned int, Animation* >& a_animations)
{
	//Test to see if animations have already been loaded
	unsigned int animationsHash = ELFHash(a_pFilename);
	auto iter = m_animations.find(animationsHash);
	if (iter != m_animations.end())
	{
		//animations have been loaded previously so set our a_animations to this reference and continue
		a_animations = static_cast<std::map< unsigned int, Animation* >>(iter->second);
	}
	else
	{
		TiXmlDocument doc(a_pFilename);
		if (doc.LoadFile())
		{
			//\===============================================================================================
			//\Load the Animations XML File
			//\===============================================================================================
			TiXmlNode *xmlNodeAnimations = doc.FirstChild("animations");
			if (xmlNodeAnimations)
			{
				//\===============================================================================================
				//\ Grab the name of the sprite sheet that is being used and load the sprite sheet if it has not already
				//\ been loaded. In effect caching the sprite texture.
				//\===============================================================================================
				TiXmlElement *xmlElementInfo = xmlNodeAnimations->ToElement();
				char pSpriteSheetName[128];
				memset(pSpriteSheetName, 0, 128);
				unsigned int textureID = 0;
				unsigned int textureWidth = 0;
				unsigned int textureHeight = 0;

				if (GetAttributeString(xmlElementInfo, "spritesheet", pSpriteSheetName, (unsigned int)(sizeof(char) * 128)))
				{
					//Load texture just ensures this texture is loaded for later use
					textureID = UG::LoadTexture(pSpriteSheetName);
					UG::GetTextureSize(pSpriteSheetName, textureWidth, textureHeight);
				}
				//\===============================================================================================
				//\Grab each animation node out of the file and load that specific animation components
				//\===============================================================================================
				TiXmlNode *xmlNodeAnimation = xmlNodeAnimations->FirstChild("animation");
				while (xmlNodeAnimation)
				{
					char pAnimName[64];
					memset(pAnimName, 0, 64);
					//We have a new animation so create a new Animation to hold this data
					Animation* currentAnim = new Animation();
					//get the animation Name
					TiXmlElement *xmlAnimationInfo = xmlNodeAnimation->ToElement();
					if (!GetAttributeString(xmlAnimationInfo, "name", pAnimName, (unsigned int)(sizeof(char) * 64)))
					{
						printf("Could not find 'name' element in XML!\n");
						continue;
					}
					currentAnim->name = std::string(pAnimName);
					currentAnim->textureName = std::string(pSpriteSheetName);
					//Get the speed
					if (!GetAttributeFloat(xmlAnimationInfo, "speed", currentAnim->framerate))
					{
						printf("Could not find 'speed' element in XML!\n");
						continue;
					}
					//See if this animation is flipped horizontally
					if (!GetAttributeInt(xmlAnimationInfo, "hflip", currentAnim->horizontalFilp))
					{
						printf("Could not find 'hflip' element in XML!\n");
						continue;
					}
					//See if this animation is flipped vertically
					if (!GetAttributeInt(xmlAnimationInfo, "vflip", currentAnim->verticalFlip))
					{
						printf("Could not find 'vflip' element in XML!\n");
						continue;
					}
					//get the number of frames 
					unsigned int frameCount = 0;
					if (GetAttributeInt(xmlAnimationInfo, "frames", frameCount))
					{
						//we have some frames to process now
						//Process frames
						TiXmlNode *xmlNodeFrame = xmlNodeAnimation->FirstChild("frame");
						while (xmlNodeFrame)
						{
							unsigned int x = 0, y = 0, w = 0, h = 0;
							AnimationFrame currentFrame;
							TiXmlElement *xmlFrameInfo = xmlNodeFrame->ToElement();
							//Get the raw pixel values from the animation xml
							GetAttributeInt(xmlFrameInfo, "x", x);
							GetAttributeInt(xmlFrameInfo, "y", y);
							GetAttributeInt(xmlFrameInfo, "width", w);
							GetAttributeInt(xmlFrameInfo, "height", h);
							//convert these values into UV coordinate space (0 -> 1 )
							currentFrame.uvCoordinates = CVector4(float(x) / float(textureWidth), float(y) / float(textureHeight),
								float(x + w) / float(textureWidth), float(y+h) / float(textureHeight));

							//Work out Origin if available otherwise 0.5f
							float oX = 0.5f, oY = 0.5f;
							GetAttributeFloat(xmlFrameInfo, "originX", oX);
							GetAttributeFloat(xmlFrameInfo, "originY", oY);
							currentFrame.v2Origin = CVector2(oX, oY);
							//Work out Origin if available otherwise 0.5f
							float sX = 1.f, sY = 1.f;
							GetAttributeFloat(xmlFrameInfo, "scaleX", sX);
							GetAttributeFloat(xmlFrameInfo, "scaleY", sY);
							currentFrame.v2Scale = CVector2(sX, sY);

							//move onto the next frame
							currentAnim->frames.push_back(currentFrame);

							xmlNodeFrame = xmlNodeFrame->NextSibling();

						}

					}
					//Put the animation into the Animation dictionary
					unsigned int animHash = ELFHash(pAnimName);
					a_animations[animHash] = currentAnim;

					xmlNodeAnimation = xmlNodeAnimation->NextSibling();
				}
			}
			m_animations[animationsHash] = a_animations;
		}
	}
}



