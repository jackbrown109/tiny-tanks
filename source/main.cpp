#include "UGFW.h"
#include "Enumerations.h"

#include "mathLib.h"

#include <iostream>
#include <set>
/*#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>
*/

#include "Player.h"
#include "Turret.h"
#include "Bullet.h"
#include "Player2.h"


int main(int argv, char* argc[])
{
	if (UG::Create( 1024, 768, false, "Framework Test", 100, 100 ))
	{
		UG::SetBackgroundColor(UG::SColour(0x00, 0x00, 0x00, 0xFF));
		UG::AddFont("./fonts/invaders.fnt");
		//\Now lets create the sprite for our players cannon. That's right in space invaders we control a cannon
		//\So lets create that with an appropriate variable name and move it to a suitable location (say the middle of our screen)

		int iScreenWidth = 0, iScreenHeight = 0;
		UG::GetScreenSize(iScreenWidth, iScreenHeight);

		int m_iBackgroundImage = UG::CreateSprite("./images/SandTerrain.png", iScreenWidth, iScreenHeight, true);
		UG::MoveSprite(m_iBackgroundImage, iScreenWidth * 0.5f, iScreenHeight * 0.5f);
		UG::SetSpriteLayer(m_iBackgroundImage, 0);

		UG::DrawSprite(m_iBackgroundImage);

	

		
		Player* pl1 = new Player("./images/BlueTank.png", "./images/BlueTurret.png", "./images/Bullet.png", 64, 64);
		pl1->SetPosition(Vector2(iScreenWidth * 0.75f, iScreenHeight * 0.75f));
	
		Player2* pl2 = new Player2("./images/RedTank.png", "./images/RedTurret.png", "./images/Bullet.png", 64, 64);
		pl2->SetPosition(Vector2(iScreenWidth * 0.25f, iScreenHeight * 0.25f));

	    //Bullet* bullet = new Bullet("./images/Bullet.png", 32, 32);

		

		//Turret* turret = new Turret("./images/BlueTurret.png", 64, 64);

		pl1->Draw();
		pl2->Draw();
		
	
	
		//turret->Draw();
		//bullet->Draw();
		//Turret cannon("./images/BlueTurret.png", 64, 64);
		//Bullet bullet("./images/Bullet.png", 12, 12);

		

		//=================================================================================================================================
		//ATTEMPT AT NODE STUFF
		//=================================================================================================================================
		//Sprite* pTank = new Sprite("./images/BlueTank.png", 66, 72, Vector2(0.5f, 0.5f), Vector4(0.058f, 0.536f, 0.442f, 0.964f));
		//pTank->SetPosition(Vector2(iScreenWidth * 0.5f, iScreenHeight * 0.5f));
		//pTank->MarkForDraw();
		//pTank->SetLayer(0);

		//Create a sprite for our tank's turret
		//Sprite* pTurret = new Sprite("./images/BlueTurret.png", 38, 64, Vector2(0.5f, 0.29f), Vector4(0.622f, 0.607f, 0.843f, 0.988f));
		//pTurret->SetParent(pTank);
		//pTurret->MarkForDraw();
		//pTurret->SetLayer(1);
		//=================================================================================================================================
		do 
		{
			float fDeltaTime = UG::GetDeltaTime();

			pl1->Update(fDeltaTime);
			pl2->Update(fDeltaTime);
			
			
			//turret->Update(fDeltaTime);
			//bullet->Update(fDeltaTime);

			// quit our application when escape is pressed
			if (UG::IsKeyDown(UG::KEY_ESCAPE))
				UG::Close();

			//Draw code for Text and lines follows
			UG::ClearScreen();

			UG::SetFont("./fonts/invaders.fnt");
			UG::DrawString("TINY TANKS", (int)(iScreenWidth * 0.4f), iScreenHeight - 2, 1.f);
			//UG::DrawString("CREDIT", (int)(iScreenWidth * 0.65f), 38);

			UG::DrawLine(0, 40, iScreenWidth, 40, UG::SColour(0x00, 0xFC, 0x00, 0xFF));
			UG::SetFont(nullptr);

		} while (UG::Process());
		
		delete pl1;
		delete pl2;
		
		
		

		UG::Dispose();


	}
	return 0;
}
