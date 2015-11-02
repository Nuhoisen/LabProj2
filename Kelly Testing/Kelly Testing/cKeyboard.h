/*Author:		Kelly Honsinger
Date Created:	10/10/15
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
cKeyBoard()

Purpose:Class contructor; Initialize the class' private data members.

Entry: None

Exit: Set it all to NULL

...................................................................
~cKeyBoard()

Purpose:Class destructor.

Entry: None

Exit: None

...................................................................

SDL_Surface * HandleInput(SDL_Event e, bool quit, SDL_Surface * KeySurfaces[KEY_PRESS_SURFACE_TOTAL]);

Purpose: Reads the event handler for user actions and returns the image that the user is prompting 
with the keyboard.

Entry: SDL_Event e: Event handler
bool quit: Bool that checks if the user has x'd out
SDL_Surface * KeySurfaces[KEY_PRESS_SURFACE_TOTAL]: Pointer to SDL_Surface array that holds bmp files

Exit: Returns a pointer to SDL_Surface that holds the users requested image.
*/

#ifndef CKEYBOARD_H
#define CKEYBOARD_H
//Enum holds ints that will be processed by a switch-case body of code
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

#include <SDL.h>
#include "cGameParent.h"

class cKeyBoard :public cGameParent
{
public:

	SDL_Texture * HandleInput(SDL_Event e, bool quit, SDL_Texture * KeySurfaces[KEY_PRESS_SURFACE_TOTAL]);


	//getter for elements of SDL_SURFACE *gKeyPressSurfaces
	//setters

	cKeyBoard();

	virtual ~cKeyBoard();
	virtual void out() = 0;

protected:
	SDL_Texture* mKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
};
#endif