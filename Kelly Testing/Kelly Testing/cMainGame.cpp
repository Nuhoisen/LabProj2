//Kelly Honsinger
#include <iostream>
#include "cMainGame.h"
#include <SDL.h>

using std::cout;
using std::cin;

cMainGame::cMainGame() 
{
}

cMainGame::~cMainGame() 
{

}

void cMainGame::GameLoop( SDL_Texture * mainSurface[IMAGE_SIXTH],  cSpriteGameLoop * tempSprite, cImageTextures * tempImage)
{
	//bool checks if application is running
	bool quit = false;

	SDL_Texture * CurrentSurface; 
	
	//render sprites
	for (int i = 0; i < IMAGE_SIXTH; i++)
	{
		tempImage->Render(mainSurface[i], TIME);
	}
	
	
	tempSprite->SpriteRender( tempSprite->ReturnRect(), mainSurface[4], TIME);
	tempSprite->SpriteRender( tempSprite->ReturnRect1(), mainSurface[4],  TIME);
}
