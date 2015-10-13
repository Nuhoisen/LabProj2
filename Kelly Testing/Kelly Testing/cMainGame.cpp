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

cMainGame::~cMainGame() {}

void cMainGame::cGameLoop(cSurfMan tempSurf, cKeyBoard tempKey, SDL_Surface * mainSurface[KEY_PRESS_SURFACE_TOTAL])
{
	//bool checks if application is running
	bool quit = false;

	//Event handler
	SDL_Event eHandle;
	//SDL_Surface that holds the image while the Event handler processes
	SDL_Surface * CurrentSurface=nullptr;
	
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
				CurrentSurface = tempKey.HandleInput(eHandle, quit, mainSurface);
			}

			//Apply the image stretched
			tempSurf.ConvertSurface(CurrentSurface);

			//Update the surface
			SDL_UpdateWindowSurface(tempSurf.WindowGetter());
		}

	}

}
