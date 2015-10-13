//Kelly Honsinger
#include <iostream>
using std::cout;
using std::cin;
#include "cMainGame.h"
#include "cKeyboard.h"
#include "cSurfMan.h"
#include <SDL.h>


int main(int argc, char * argv[])
{

	cSurfMan  manage;
	cKeyBoard board;
	cMainGame game;
	SDL_Surface * mainSurface[KEY_PRESS_SURFACE_TOTAL];
	bool again = false;
	//do loop triggers again when 'Retry()' function returns true
	do {
		//class object

		if (!manage.Init(argv))
		{
			cout << "failed to initialize...";
		}
		else
		{
			if (!manage.LoadMedia(mainSurface))
			{
				cout << "failed to load.";
			}
			else
			{
				game.cGameLoop(manage, board, mainSurface);
			}
		}
		manage.Close(mainSurface);
		again = manage.Retry();
	} while (again == true);

	return 0;
}