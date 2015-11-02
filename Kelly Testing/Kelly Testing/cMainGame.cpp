//Kelly Honsinger
#include <iostream>
#include "cMainGame.h"
/*
#include "cSurfMan.h"
#include "cKeyboard.h"
*/
#include <SDL.h>

using std::cout;
using std::cin;

cMainGame::cMainGame() 
{
}

cMainGame::~cMainGame() 
{

}

void cMainGame::cGameLoop( SDL_Texture * mainSurface[KEY_PRESS_SURFACE_TOTAL])
{
	//bool checks if application is running
	bool quit = false;

	//Event handler
	SDL_Event eHandle;
	//SDL_Surface that holds the image while the Event handler processes
	SDL_Texture * CurrentSurface = mainSurface[KEY_PRESS_SURFACE_DEFAULT];
	
	while (!quit)
	{
		//Once the Event Handler reads a NULL in queue it stops processing
		while (SDL_PollEvent(&eHandle) != 0)
		{
			//User requests quit
			if (eHandle.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (eHandle.type == SDL_KEYDOWN)
			{
				CurrentSurface = this->HandleInput(eHandle, quit, mainSurface);
		
			}

		
			//Clear screen	
			SDL_RenderClear(mRenderer);
			//copy texture to screen
			SDL_RenderCopy(mRenderer, CurrentSurface, nullptr, nullptr);
			SDL_RenderPresent(mRenderer);
		}

	}

}


void cMainGame::out()
{
	
}