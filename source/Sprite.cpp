#include "UGFW.h"

#include "Sprite.h"

Sprite::Sprite(const char* a_fileName, int a_width, int a_height, Vector2 a_origin, Vector4 a_UVCoords) 
{
	m_iSpriteID = UG::CreateSprite(a_fileName, Vector2(a_width, a_height), a_origin, a_UVCoords);
	float mat4x4[16];
	memset(mat4x4, 0, sizeof(float) * 16);
	UG::GetSpriteMatrix(m_iSpriteID, mat4x4);
	m3PosRot = Matrix3(mat4x4[0], mat4x4[1], mat4x4[2], mat4x4[4], mat4x4[5], mat4x4[6], mat4x4[12], mat4x4[13], 1.f);

}

Sprite::~Sprite() 
{
	UG::StopDrawingSprite(m_iSpriteID);
	UG::DestroySprite(m_iSpriteID);
}

void Sprite::SetLayer(unsigned int a_uiLayer)
{
	UG::SetSpriteLayer(m_iSpriteID, a_uiLayer);
}

void Sprite::Update(float a_fdt)
{
	//OpenGL which is the underlying rendering pipeline that is being used by the framework
	//draws all components using a 4x4 matrix to represent their world coordinates, here I am constructing that matrix
	//from the 3x3 matrix that we are using internally
	//set the sprites matrix

	Matrix3 worldTx = Matrix3::IDENTITY;
	GetWorldTransform(worldTx);
	Matrix4 m4x4 = Matrix4(worldTx.m_11, worldTx.m_12, worldTx.m_13, 0.f,
		worldTx.m_21, worldTx.m_22, worldTx.m_23, 0.f,
		0.f, 0.f, 1.f, 0.f,
		worldTx.m_31, worldTx.m_32, 0.f, 1.f);
	UG::SetSpriteMatrix(m_iSpriteID, m4x4);

}

void Sprite::MoveSprite(Vector3 a_movementVec)
{
	Vector3 pos;
	m3PosRot.GetRow(2, pos);
	//Multiplying the movement vector by our local transform will put that vector in the local space of this object
	//if we were after moving this object along a world vector then we would need to multiply that vector by the inverse
	//of our worldspace matrix
	Vector3 v3 = a_movementVec * m3PosRot;
	pos += a_movementVec * m3PosRot;

	m3PosRot.SetRow(2, pos);
}

void Sprite::MarkForDraw()
{
	UG::DrawSprite(m_iSpriteID);
}

void Sprite::StopDrawing()
{
	UG::StopDrawingSprite(m_iSpriteID);
}

void Sprite::SetPosition(Vector2 a_pos)
{
	Vector3 np = Vector3(a_pos.x, a_pos.y, 1.f);
	m3PosRot.SetRow(2, np);

}







