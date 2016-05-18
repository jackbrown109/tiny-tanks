#include "Player2.h"
#include "UGFW.h"
#include "Enumerations.h"
#include <math.h>


float SignF2(float a_var)
{
	if (a_var > 0.f) return 1.f;
	if (a_var < 0.f) return -1.f;
	return 1;

}

Player2::Player2(const char* a_textureFileName, const char* a_turretTexture, const char* a_bulletTexture, float a_width, float a_height)
{
	m_pSprite = new Sprite(a_textureFileName, a_width, a_height, Vector2(0.5f, 0.5f), Vector4(0.f, 0.f, 1.f, 1.f));
	m_pSprite->SetLayer(1);

	m_pTurret = new Sprite(a_turretTexture, a_width, a_height, Vector2(0.5f, 0.46f), Vector4(0.f, 0.f, 1.f, 1.f));
	m_pTurret->SetLayer(2);
	m_pTurret->SetParent(m_pSprite);

	m_pBullet/*[MAX_BULLETS]*/ = new Sprite(a_bulletTexture, a_width, a_height, Vector2(0.5f, 0.5f), Vector4(0.f, 0.f, 1.f, 1.f));
	m_pBullet/*[MAX_BULLETS]*/->SetLayer(1);
	m_pBullet/*[MAX_BULLETS]*/->SetParent(m_pTurret);

}

Player2::~Player2()
{
	delete m_pSprite;
	delete m_pTurret;
	delete m_pBullet/*[MAX_BULLETS]*/;


}

void Player2::SetPosition(Vector2 a_v2)
{
	m_pSprite->SetPosition(a_v2);

}

void Player2::SetBoundary(Vector2 a_v2)
{

}



void Player2::Update(float a_fDeltaTime)
{

	

	//Create a vector to store our movement
	Vector3 movementVector = Vector3::AXIS_Y;

	Vector3 movementVectorBullet = Vector3::AXIS_Y;
	//We're going to be treating moving forward and backward as traversing along the sprite's Y axis
	//If our sprite was rotated 90 degrees on the sprite sheet then we would treat that direction as forward.
	float fAcceleration = 0.f;
	float fCurrentVelocity = 0.f;
	float fMaxVelocity = 10.f;
	float fDrag = 0.03f;



	if (UG::IsKeyDown(UG::KEY_W))
	{
		fAcceleration += 50.f;
		fDrag = 0.f;
	}
	if (UG::IsKeyDown(UG::KEY_S))
	{
		fAcceleration -= 40.f;
		fDrag = 0.f;
	}
	if (!UG::IsKeyDown(UG::KEY_W) && !UG::IsKeyDown(UG::KEY_S))
	{
		fDrag = 0.08f;
	}

	fCurrentVelocity += fAcceleration * a_fDeltaTime;
	fCurrentVelocity -= fCurrentVelocity * fDrag;
	if (fabsf(fCurrentVelocity) > fMaxVelocity)
	{
		fCurrentVelocity = fMaxVelocity * SignF2(fCurrentVelocity);
	}
	if (fabsf(fCurrentVelocity) > 0.0000001f)
	{
		movementVector *= fCurrentVelocity;
		m_pSprite->MoveSprite(movementVector);
	}

	if (UG::IsKeyDown(UG::KEY_A))
	{
		m_pSprite->RotateZ(0.05f);
	}
	if (UG::IsKeyDown(UG::KEY_D))
	{
		m_pSprite->RotateZ(-0.05f);
	}

	if (UG::IsKeyDown(UG::KEY_T))
	{
		m_pTurret->RotateZ(0.05f);
	}
	if (UG::IsKeyDown(UG::KEY_Y))
	{
		m_pTurret->RotateZ(-0.05f);
	}

	if (UG::IsKeyDown(UG::KEY_6));
	{
		isAlive = true;
		fAcceleration += 50.f;
		fDrag = 0.f;
	}

	/*if (isAlive == true)
	{
		fCurrentVelocity += fAcceleration * a_fDeltaTime;
		fCurrentVelocity -= fCurrentVelocity * fDrag;
		if (fabsf(fCurrentVelocity) > 0.0000001f)
		{
			movementVectorBullet *= fCurrentVelocity;
			for (int i = 0; i < MAX_BULLETS; i++)
			{*/
				m_pBullet/*[i]*/->MoveSprite(movementVectorBullet);
			//}
		//}



	//}


	m_pSprite->Update(a_fDeltaTime);
	m_pTurret->Update(a_fDeltaTime);
	//for (int i = 0; i < MAX_BULLETS; i++)
	//{
		m_pBullet/*[i]*/->Update(a_fDeltaTime);
	//}

}

void Player2::Draw()
{
	m_pSprite->MarkForDraw();
	m_pTurret->MarkForDraw();

	//for (int i = 0; i < MAX_BULLETS; i++)
	//{
		m_pBullet/*[i]*/->MarkForDraw();
	//}



}

