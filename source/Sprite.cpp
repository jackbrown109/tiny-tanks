#include "Sprite.h"
#include "UGFW.h"


Sprite::Sprite( const char* a_fileName, int a_width, int a_height, CVector2 a_origin, CVector4 a_UVCoords) 
{
	m_iSpriteID = UG::CreateSprite(a_fileName, CVector2(a_width, a_height), a_origin, a_UVCoords);
	float mat4x4[16];
	memset(mat4x4, 0, sizeof(float) * 16);
	UG::GetSpriteMatrix(m_iSpriteID, mat4x4);
	m_m4PosRot = CMatrix4(mat4x4);
}
//Destructor
Sprite::~Sprite() 
{
	UG::DestroySprite(m_iSpriteID);
}
//Set our sprite layer
void Sprite::SetLayer(unsigned int a_uiLayer)
{
	UG::SetSpriteLayer(m_iSpriteID, a_uiLayer);
}
//an update function to call each frame to update our sprites data
void Sprite::Update(float a_fdt)
{
	//OpenGL which is the underlying rendering pipeline that is being used by the framework
	//draws all components using a 4x4 matrix to represent their world coordinates, here I am constructing that matrix
	//from the 3x3 matrix that we are using internally
	//set the sprites matrix

	CMatrix4 worldTx = CMatrix4::IDENTITY;
	GetWorldTransform(worldTx);
	UG::SetSpriteMatrix(m_iSpriteID, worldTx);

}
//Function to move our sprite
// The movement vector argument is not guaranteed to be a unit vector as we may be moving scaled by a velocity
void Sprite::MoveSprite(CVector4 a_movementVec)
{
	CVector4 pos;
	m_m4PosRot.GetRow(3, pos);
	//Multiplying the movement vector by our local transform will put that vector in the local space of this object
	//if we were after moving this object along a world vector then we would need to multiply that vector by the inverse
	//of our worldspace matrix
	pos += a_movementVec * m_m4PosRot;
	m_m4PosRot.SetRow(3, pos);
}

void Sprite::MarkForDraw()
{
	UG::DrawSprite(m_iSpriteID);
}

void Sprite::StopDrawing()
{
	UG::StopDrawingSprite(m_iSpriteID);
}

void Sprite::SetPosition(CVector2 a_pos) {
	CVector4 np = CVector4(a_pos.x, a_pos.y, 0.f, 1.f);
	m_m4PosRot.SetRow(3, np);

}