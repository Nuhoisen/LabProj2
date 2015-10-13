//Kelly Honsinger
#include <iostream>
using std::cout;
using std::cin;
#include "cKeyboard.h"
#include "cSurfMan.h"
#include "cMainGame.h"
#include <SDL.h>
#include <string>

cKeyBoard::cKeyBoard() {};

cKeyBoard::~cKeyBoard() {};

SDL_Surface * cKeyBoard::HandleInput(SDL_Event e, bool quit, SDL_Surface * KeySurfaces[KEY_PRESS_SURFACE_TOTAL])
{
	SDL_Surface* returnSurface = nullptr;
	switch (e.key.keysym.sym)
	{
	case SDLK_UP:
		returnSurface = KeySurfaces[KEY_PRESS_SURFACE_UP];
		break;

	case SDLK_DOWN:
		returnSurface = KeySurfaces[KEY_PRESS_SURFACE_DOWN];
		break;

	case SDLK_LEFT:
		returnSurface = KeySurfaces[KEY_PRESS_SURFACE_LEFT];
		break;

	case SDLK_RIGHT:
		returnSurface = KeySurfaces[KEY_PRESS_SURFACE_RIGHT];
		break;

	default:
		returnSurface = KeySurfaces[KEY_PRESS_SURFACE_DEFAULT];
		break;
	}
	return returnSurface;
}



