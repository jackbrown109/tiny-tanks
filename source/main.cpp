#include "UGFW.h"
#include "Enumerations.h"

#include "mathLib.h"

#include <iostream>
/*#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>
*/

#include "Player.h"
#include "Entity.h"
#include "Turret.h"
#include "Bullet.h"


int main(int argv, char* argc[])
{
	if (UG::Create( 1024, 768, false, "Framework Test", 100, 100 ))
	{
		UG::SetBackgroundColor(UG::SColour(0x00, 0x00, 0x00, 0xFF));
		UG::AddFont("./fonts/invaders.fnt");
		//\Now lets create the sprite for our players cannon. That's right in space invaders we control a cannon
		//\So lets create that with an appropriate variable name and move it to a suitable location (say the middle of our screen)

		/*int iPlayerSprite = UG::CreateSprite("./images/BlueTank.png", 64, 64, true);*/
		int iScreenWidth = 0, iScreenHeight = 0;
		UG::GetScreenSize(iScreenWidth, iScreenHeight);

		int m_iBackgroundImage = UG::CreateSprite("./images/SandTerrain.png", iScreenWidth, iScreenHeight, true);
		UG::MoveSprite(m_iBackgroundImage, iScreenWidth * 0.5f, iScreenHeight * 0.5f);
		UG::DrawSprite(m_iBackgroundImage);

		Player tank("./images/BlueTank.png", 64, 64);
		Turret cannon("./images/BlueTurret.png", 64, 64);
		Bullet bullet("./images/Bullet.png", 12, 12);
		

		

		
		float x; float y;
		tank.SetPosition(iScreenWidth*0.5f, iScreenHeight*0.5f);
		tank.GetPosition(x, y);
		cannon.SetPosition(x, y + 5.f);
		UG::MoveSprite(tank.GetSpriteID(), x, y);
		UG::DrawSprite(tank.GetSpriteID());
		
		
		cannon.GetPosition(x, y);

		UG::MoveSprite(cannon.GetSpriteID(), x, y);
		UG::DrawSprite(cannon.GetSpriteID());


		bullet.SetPosition(iScreenWidth*0.5f, iScreenHeight*0.5f);
		bullet.GetPosition(x, y);
		UG::MoveSprite(bullet.GetSpriteID(), x, y);
		UG::DrawSprite(bullet.GetSpriteID());


		
		do 
		{
			float fDeltaTime = UG::GetDeltaTime();

			tank.Update(fDeltaTime);
			cannon.Update(fDeltaTime);

			float x; float y;

			tank.GetPosition(x, y);
			UG::MoveSprite(tank.GetSpriteID(), x, y);
			
			cannon.GetPosition(x, y);
			UG::MoveSprite(cannon.GetSpriteID(), x, y);

			bullet.GetPosition(x, y);
			UG::MoveSprite(bullet.GetSpriteID(), x, y);

			std::cout << x << "" << y << std::endl;
			
		

			// quit our application when escape is pressed
			if (UG::IsKeyDown(UG::KEY_ESCAPE))
				UG::Close();

			//Draw code for Text and lines follows
			UG::ClearScreen();

			UG::SetFont("./fonts/invaders.fnt");
			UG::DrawString("TINY TANKS", (int)(iScreenWidth * 0.4f), iScreenHeight - 2, 1.f);
			UG::DrawString("CREDIT", (int)(iScreenWidth * 0.65f), 38);

			UG::DrawLine(0, 40, iScreenWidth, 40, UG::SColour(0x00, 0xFC, 0x00, 0xFF));
			UG::SetFont(nullptr);

		} while (UG::Process());


		UG::StopDrawingSprite(tank.GetSpriteID());
		UG::DestroySprite(tank.GetSpriteID());

	

		UG::Dispose();


	}
	return 0;
}
