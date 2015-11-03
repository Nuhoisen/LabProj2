//Kelly Honsinger
#include <iostream>
using std::cout;
using std::cin;
#include "cKeyboard.h"
#include <SDL.h>
#include <string>

cKeyBoard::cKeyBoard() {};

cKeyBoard::~cKeyBoard() {};



SDL_Texture * cKeyBoard::HandleInput(SDL_Event e, bool quit, SDL_Texture * KeySurfaces[IMAGE_SIXTH])
{
	SDL_Texture* returnSurface = nullptr;
	switch (e.key.keysym.sym)
	{
	case SDLK_UP:
		returnSurface = KeySurfaces[IMAGE_SECOND];
		break;

	case SDLK_DOWN:
		returnSurface = KeySurfaces[IMAGE_SECOND];
		break;

	case SDLK_LEFT:
		returnSurface = KeySurfaces[IMAGE_THIRD];
		break;

	case SDLK_RIGHT:
		returnSurface = KeySurfaces[IMAGE_FOURTH];
		break;

	default:
		returnSurface = KeySurfaces[IMAGE_FIRST];
		break;
	}
	return returnSurface;
}



