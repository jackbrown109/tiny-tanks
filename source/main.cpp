#include "UGFW.h"
#include "Enumerations.h"

#include <iostream>
/*#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>
*/

int main(int argv, char* argc[])
{
	if (UG::Create( 1024, 768, false, "Framework Test", 100, 100 ))
	{
		UG::SetBackgroundColor(UG::SColour(0x00, 0x00, 0x00, 0xFF));
		UG::AddFont("./fonts/invaders.fnt");
		//\Now lets create the sprite for our players cannon. That's right in space invaders we control a cannon
		//\So lets create that with an appropriate variable name and move it to a suitable location (say the middle of our screen)
		int iPlayerSprite = UG::CreateSprite("./images/cannon.png", 64, 32, true);

		int iScreenWidth = 0, iScreenHeight = 0;
		UG::GetScreenSize(iScreenWidth, iScreenHeight);
		UG::MoveSprite(iPlayerSprite, iScreenWidth * 0.5f, iScreenHeight * 0.5f);

		do 
		{
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

			UG::ClearScreen();

			UG::DrawSprite(iPlayerSprite);

			UG::SetFont("./fonts/invaders.fnt");
			UG::DrawString("HI-SCORE", (int)(iScreenWidth * 0.4f), iScreenHeight - 2, 1.f);
			UG::DrawString("CREDIT", (int)(iScreenWidth * 0.65f), 38);

			UG::DrawLine(0, 40, iScreenWidth, 40, UG::SColour(0x00, 0xFC, 0x00, 0xFF));
			UG::SetFont(nullptr);

		} while (UG::Process());

		UG::DestroySprite(iPlayerSprite);
		
		UG::Dispose();


	}
	return 0;
}
