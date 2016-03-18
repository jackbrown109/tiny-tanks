#include "UGFW.h"
#include "Enumerations.h"

#include <iostream>
#include "mathLib.h"
#include "Sprite.h"
#include "AnimationManager.h"

int main(int argv, char* argc[])
{
	if (UG::Create( 1400, 985, false, "Framework Test", 100, 100 ))
	{

		AnimationManager::CreateInstance();

		
		int iScreenWidth = 0, iScreenHeight = 0;
		UG::GetScreenSize(iScreenWidth, iScreenHeight);

		UG::SetBackgroundColor(UG::SColour(0x00, 0x00, 0x00, 0xFF));
		UG::AddFont("./fonts/invaders.fnt");
		//\Now lets create the sprite for our players cannon. That's right in space invaders we control a cannon
		//\So lets create that with an appropriate variable name and move it to a suitable location (say the middle of our screen)
		int iPlayerSprite = UG::CreateSprite("./images/cannon.png", 64, 32, true);
		Sprite* pBackground = new Sprite("./images/background.png", iScreenWidth, iScreenHeight, CVector2(0.5f, 0.5f), CVector4(0.f, 0.f, 1.f, 1.f));
		pBackground->MarkForDraw();
		pBackground->SetPosition(CVector2(iScreenWidth * 0.5f, iScreenHeight * 0.5f));
		pBackground->Update(0.f);
		

		AnimationManager::GetInstance()->LoadAnimationsFromFile("./animations/animations.xml");

		do 
		{
			float fDt = UG::GetDeltaTime();
			

			float xPos = 0; float yPos = 0;
			UG::GetSpritePosition(iPlayerSprite, xPos, yPos);

			if (UG::IsKeyDown(UG::KEY_RIGHT))
			{
				UG::MoveSprite(iPlayerSprite, xPos + 1.f, yPos);
			}
			if (UG::IsKeyDown(UG::KEY_LEFT))
			{
				UG::MoveSprite(iPlayerSprite, xPos - 1.f, yPos);
			}
			// quit our application when escape is pressed
			if (UG::IsKeyDown(UG::KEY_ESCAPE))
				UG::Close();

			//Draw code for Text and lines follows
			UG::ClearScreen();

			UG::SetFont("./fonts/invaders.fnt");
			UG::DrawString("HI-SCORE", (int)(iScreenWidth * 0.4f), iScreenHeight - 2, 1.f);
			UG::DrawString("CREDIT", (int)(iScreenWidth * 0.65f), 38);

			UG::DrawLine(0, 40, iScreenWidth, 40, UG::SColour(0x00, 0xFC, 0x00, 0xFF));
			UG::SetFont(nullptr);

		} while (UG::Process());
		UG::StopDrawingSprite(iPlayerSprite);
		UG::DestroySprite(iPlayerSprite);
		
		UG::Dispose();


	}
	return 0;
}
