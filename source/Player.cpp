#include "Player.h"
#include "UGFW.h"
#include "Enumerations.h"
#include <math.h>


float SignF(float a_var)
{
	if (a_var > 0.f) return 1.f;
	if (a_var < 0.f) return -1.f;
	return 1;

}

Player::Player(const char* a_textureFileName, const char* a_turretTexture, const char* a_bulletTexture, float a_width, float a_height)
{
	m_pSprite = new Sprite(a_textureFileName, a_width, a_height, Vector2(0.5f, 0.5f), Vector4(0.f, 0.f, 1.f, 1.f));
	m_pSprite->SetLayer(1);
	
	m_pTurret = new Sprite(a_turretTexture, a_width, a_height, Vector2(0.5f, 0.46f), Vector4(0.f, 0.f, 1.f, 1.f));
	m_pTurret->SetLayer(2);
	m_pTurret->SetParent(m_pSprite);


	for (int i = 0; i < MAX_BULLETS; i++)
	{
		m_pBullet[i] = new Sprite(a_bulletTexture, a_width, a_height, Vector2(0.5f, 0.5f), Vector4(0.f, 0.f, 1.f, 1.f));
		m_pBullet[i]->SetLayer(1);
		m_pBullet[i]->SetParent(m_pTurret);

	}
	
	
}

Player::~Player()
{
	delete m_pSprite;
	delete m_pTurret;
	delete m_pBullet;

	
}


void Player::SetPosition(Vector2 a_v2)
{
	m_pSprite->SetPosition(a_v2);
	
}

void Player::SetBoundary(Vector2 a_v2)
{

}


void Player::Update(float a_fDeltaTime)
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

	

	

	if (UG::IsKeyDown(UG::KEY_UP))
	{
		fAcceleration += 50.f;
		fDrag = 0.f;
	}
	if (UG::IsKeyDown(UG::KEY_DOWN))
	{
		fAcceleration -= 40.f;
		fDrag = 0.f;
	}
	if (!UG::IsKeyDown(UG::KEY_UP) && !UG::IsKeyDown(UG::KEY_DOWN))
	{
		fDrag = 0.08f;
	}

	fCurrentVelocity += fAcceleration * a_fDeltaTime;
	fCurrentVelocity -= fCurrentVelocity * fDrag;
	if (fabsf(fCurrentVelocity) > fMaxVelocity)
	{
		fCurrentVelocity = fMaxVelocity * SignF(fCurrentVelocity);
	}
	if (fabsf(fCurrentVelocity) > 0.0000001f )
	{
		movementVector *= fCurrentVelocity;
		m_pSprite->MoveSprite(movementVector);
	}

	if (UG::IsKeyDown(UG::KEY_LEFT))
	{
		m_pSprite->RotateZ(0.05f);
	}
	if (UG::IsKeyDown(UG::KEY_RIGHT))
	{
		m_pSprite->RotateZ(-0.05f);
	}

	if (UG::IsKeyDown(UG::KEY_C))
	{
		m_pTurret->RotateZ(0.05f);
	}
	if (UG::IsKeyDown(UG::KEY_V))
	{
		m_pTurret->RotateZ(-0.05f);
	}

	if (UG::IsKeyDown(UG::KEY_SPACE));
	{
		isAlive = true;
		fAcceleration += 50.f;
		fDrag = 0.f;
	}

	if (isAlive == true)
	{
		fCurrentVelocity += fAcceleration * a_fDeltaTime;
		fCurrentVelocity -= fCurrentVelocity * fDrag;
		if (fabsf(fCurrentVelocity) > 0.0000001f)
		{
			movementVectorBullet *= fCurrentVelocity;
			for (int i = 0; i < MAX_BULLETS; i++)
			{
				m_pBullet[i]->MoveSprite(movementVectorBullet);
			}
		}



	}

	m_pSprite->Update(a_fDeltaTime);
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		m_pBullet[i]->Update(a_fDeltaTime);
	}
	m_pTurret->Update(a_fDeltaTime);
	


	
}

void Player::Draw()
{
	m_pSprite->MarkForDraw();
	m_pTurret->MarkForDraw();

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		m_pBullet[i]->MarkForDraw();
	}
	
}

