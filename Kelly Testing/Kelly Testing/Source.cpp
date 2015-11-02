//Kelly Honsinger
#include <iostream>
#include "cMainGame.h"
#include "mRandArray.h"
#include <SDL.h>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main(int argc, char * argv[])
{
	mRandArray hello;
	string * cmdArgs = hello.RandNumGen(argc, argv);
	cMainGame * game= new cMainGame;
	SDL_Texture * mainSurface[KEY_PRESS_SURFACE_TOTAL];
	bool again = false;
	//do loop triggers again when 'Retry()' function returns true
	do {
		//class object
		 
		if (!game->Init(cmdArgs))
		{
			cout << "failed to initialize...";
		}
		else
		{
			if (!game->LoadMedia(mainSurface, cmdArgs))
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


