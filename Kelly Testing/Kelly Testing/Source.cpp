//Kelly Honsinger
#include <iostream>
#include "cMainGame.h"
#include "cRandArray.h"
#include "cSpriteGameLoop.h"
#include "cImageTextures.h"
#include <SDL.h>
#include <string>
using std::cout;
using std::cin;
using std::string;
const int argCount = 10;	//allocate enough memory for objects
int main(int argc, char * argv[])
{
	//cKeyboard is abc that dynamically allocates either traditional images or sprites
	cSpriteGameLoop * Sprites= new cSpriteGameLoop();
	cImageTextures * Images= new cImageTextures();
	cMainGame * Loop= new cMainGame();
	SDL_Texture * mainSurface[IMAGE_SIXTH];
	//initializes the first few objects of array; it doesnt allocate the last one
		bool again = false;
		//do loop triggers again when 'Retry()' function returns true
		do{
			//class object

			if (!Images->Init(argv))
			{
				cout << "failed to initialize...";
			}
			else
			{
				if (!Images->LoadMedia(mainSurface, argv))
				{
					cout << "failed to load.";
				}
				else
				{
					Loop->GameLoop(mainSurface, Sprites, Images);
				}
			}
			Images->Close(mainSurface);
			again = Images->Retry();
		} while (again == true);	
	return 0;
}


