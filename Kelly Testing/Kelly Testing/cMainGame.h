/*Author:		Kelly Honsinger
Date Created:	10/1/15
Last Mod Date:	10/12/15
Lab Number:		2
File Name:		CST136L1

Overview:
The purpose of this program is to display a .bmp image to the screen for a few seconds.
It does this using a Simple Directmedia Layer(SDL) library. First, SDL generates
the window for the image, followed by the generation of a screen surface.  Finally, the
image is extracted from its directory and brought to screen.  It appears briefly on screen
for 3 seconds before being cleared away. This is followed by an emerging game loop method
that prompts the user to go again.

Input:
Input includes the command line arguments which take the name of the file and pass it to
the SDL library functions.

Output:
Output includes the SDL window, the SDL surface, and the image.  The first two are generated
using SDL library functions while the last one is extracted from its directory and placed onto the
newly created plane.
...................................................................
DECLARATIONS
------------
cMainGame()

Purpose:Class contructor; Initialize the class' private data members.

Entry: None

Exit: Set it all to NULL

...................................................................
~cMainGame()

Purpose:Class destructor.

Entry: None

Exit: None

...................................................................
void cGameLoop(cSurfMan y, cKeyBoard x, SDL_Surface * mainSurface[KEY_PRESS_SURFACE_TOTAL])

Purpose: Creates an SDL_Event counter which processes input until the user exits out of the prog.

Entry: cSurfMan tempSurf: class object that invokes functions windowConverter and windowGetter.
cKeyBoard tempKey: class object that invokes function handleOutput.

Exit: Function returns nothing
*/

#ifndef CMAINGAME_H
#define CMAINGAME_H

#include <SDL.h>
#include <iostream>
#include "cKeyboard.h"
#include "cSurfMan.h"


/* Class:cMainGame

Constructors:
cTime(): Window, ScreenSurface, and Image are initialized to null.

Methods: */

class cMainGame
{
public:
	
	cMainGame();								//Constructor Declaration
	~cMainGame();								//Destructor Declaration

	void cGameLoop(cSurfMan tempSurf, cKeyBoard tempKey, SDL_Surface * mainSurface[KEY_PRESS_SURFACE_TOTAL]);

private:
	//Current displayed image
	SDL_Surface * mainSurface[KEY_PRESS_SURFACE_TOTAL]; //Pointer to SDL_Surface array that holds Images
			
};
#endif
