#include "mathLib.h"
#include "Node.h"

#ifndef __SPRITE_H__
#define __SPRITE_H__

//A very simple sprite class that extends from node allowing us to have a sprite hierarchy tree in our game
class Sprite : public Node 
{
public:
	//Constructor -- makes a UG Sprite object for us to use
	Sprite(const char* a_fileName, int a_width, int a_height, Vector2 a_origin, Vector4 a_UVCoords);
	//Destructor
	virtual ~Sprite();
	//Set our sprite layer
	void SetLayer(unsigned int a_uiLayer);
	//an update function to call each frame to update our sprites data
	void Update(float a_fdt);
	//Function to move our sprite
	// The movement vector argument is not guaranteed to be a unit vector as we may be moving scaled by a velocity
	void MoveSprite(Vector3 a_movementVec);

	void MarkForDraw();

	void StopDrawing();

	void SetPosition(Vector2 a_pos);

private:
	int m_iSpriteID;
	int m_iWidth;
	int m_iHeight;
	Vector2 m_v2Origin;

};

#endif //__SPRITE_H__