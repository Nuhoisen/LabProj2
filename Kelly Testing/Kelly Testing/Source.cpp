//Kelly Honsinger
#include <iostream>
using std::cout;
using std::cin;
#include "cMainGame.h"
#include <SDL.h>


int main(int argc, char * argv[])
{
	
	cMainGame * game= new cMainGame;
	SDL_Texture * mainSurface[KEY_PRESS_SURFACE_TOTAL];
	bool again = false;
	//do loop triggers again when 'Retry()' function returns true
	do {
		//class object

		if (!game->Init(argv))
		{
			cout << "failed to initialize...";
		}
		else
		{
			if (!game->LoadMedia(mainSurface, argv))
			{
				cout << "failed to load.";
			}
			else
			{
				game->cGameLoop(mainSurface);
			}
		}
		game->Close(mainSurface);
		again = game->Retry();
	} while (again == true);
	game = nullptr;
	return 0;
}