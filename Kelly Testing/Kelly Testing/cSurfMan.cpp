//Kelly Honsinger
#include <iostream>
using std::cout;
using std::cin;
#include "cSurfMan.h"
#include "cKeyboard.h"
#include "cMainGame.h"
#include <SDL.h>

const int WIDTH = 640;
const int HEIGHT = 300;
cSurfMan::cSurfMan()
{
	mWindow = NULL;
	mScreenSurface = NULL;
	mStretchedSurface = NULL;
}

cSurfMan::~cSurfMan() {}
bool cSurfMan::Init(char * headerName[])
{
	bool pass = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Initialization failure. ERROR: ", SDL_GetError();
		pass = false;
	}
	else
	{
		mWindow = SDL_CreateWindow(headerName[1], SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (mWindow == nullptr)
		{
			cout << "Can't Create Window! SDL ERROR: " << SDL_GetError();
			pass = false;
		}
		else
		{
			mScreenSurface = SDL_GetWindowSurface(mWindow);
		}
	}
	return pass;
}

bool cSurfMan::LoadMedia(SDL_Surface *KeySurfaces[KEY_PRESS_SURFACE_TOTAL])
{
	bool success = true;

	KeySurfaces[KEY_PRESS_SURFACE_DEFAULT] = LoadSurface("04_key_presses/press.bmp"); //Default Key
	if (KeySurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr)							  //Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	KeySurfaces[KEY_PRESS_SURFACE_UP] = LoadSurface("04_key_presses/up.bmp");	//Up Key
	if (KeySurfaces[KEY_PRESS_SURFACE_UP] == nullptr)							//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	KeySurfaces[KEY_PRESS_SURFACE_DOWN] = LoadSurface("04_key_presses/down.bmp"); //Down Key
	if (KeySurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr)							  //Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	KeySurfaces[KEY_PRESS_SURFACE_LEFT] = LoadSurface("04_key_presses/left.bmp");//Left Key
	if (KeySurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr)							//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";	
		success = false;
	}

	KeySurfaces[KEY_PRESS_SURFACE_RIGHT] = LoadSurface("04_key_presses/right.bmp");	//Right Key
	if (KeySurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr)							//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}
	//bool returns successful 
	return success;
}

SDL_Surface* cSurfMan::LoadSurface(std::string path)
{
	//create cSurfMan object to access getter from the class

	//The final optimized image
	SDL_Surface* optimizedSurface = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == nullptr)
	{
		cout << "Unable to load image, SDL Error: %s\n" << SDL_GetError();
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, mScreenSurface->format, NULL);
		if (optimizedSurface == nullptr)
		{
			cout << "Unable to optimize image! SDL Error:" << SDL_GetError();
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
		loadedSurface = nullptr;
	}

	return optimizedSurface;
}

void cSurfMan::ConvertSurface(SDL_Surface * CurrentSurface)
{
	SDL_Rect rectMod;
	rectMod.x = 0;
	rectMod.y = 0;
	rectMod.w = WIDTH;
	rectMod.h = HEIGHT;
	SDL_BlitScaled(CurrentSurface, nullptr, mScreenSurface, &rectMod);
	SDL_UpdateWindowSurface(mWindow);
}

bool cSurfMan::Retry()
{
	bool again = true;
	char answer = 'x';
	while (answer != 'N')
	{
		while (answer != 'Y')
		{
			cout << "would you like to go again(y/n)?";
			cin >> answer;
			answer = toupper(answer);
			if (answer == 'N')
			{
				again = false;
				return again;
			}
			else if (answer == 'Y')
			{
				return again;
			}
		}
	}
}

void cSurfMan::Close(SDL_Surface * KeyPresses[KEY_PRESS_SURFACE_TOTAL])
{
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		SDL_FreeSurface(KeyPresses[i]);
		KeyPresses[i] = nullptr;
	}

	SDL_FreeSurface(mStretchedSurface);
	mStretchedSurface = nullptr;

	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;

	SDL_Quit();
}