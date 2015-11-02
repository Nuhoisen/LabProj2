/*Author:			Kelly Honsinger
Date Created:		10//10/15
Last Mod Date:		10/12/15
Lab Number:		2
File Name:		CST136L1

Overview:
The purpose of this program is to display a series of .bmp images and make them interact 
with the keyboard.  If the up key is pressed a certain image appears on screen.  Same with 
the down, right, and left keys. They do this by using a SDL event counter which keeps 
processing until the window is closed.

Input:
Input includes the command line arguments which take the name of the files and pass it to
the SDL library functions.

Output:
Output includes images on the screen that correspond to certain keys.  
.........................................................................................
DECLARATIONS
.........................................................................................
cSurfMan()

Purpose:(class constructor.  Initialize the class' private data members.

Entry: None. Sets all to null.

Exit: None.
.........................................................................................

~cSurfMan()

Purpose: Class Destructor.

Entry:None

Exit:None
..........................................................................................

bool Init()

Purpose:Initializes the program by checking for the SDL Library files and then
constructing a window that will hold the image.

Entry: char * headerName[]: is a pointer to a char array.  It holds the command line
arguments, and in this case the image file's directory and name.

Exit: bool pass: is a variable that returns true if everything succeeds in the method.
...........................................................................................

bool LoadMedia()

Purpose:Loads the appropriate Bmp file to correspond with the correct key. Uses an enum to 
simplify the data.

Entry: Takes input from an pointer to enum array.

Exit: Returns a bool to check that all the files were opened properly
...........................................................................................

SDL_Surface* LoadSurface(std::string)

Purpose: Function executed within LoadMedia function that takes the file directory and
assigns it to the right pointer enum array.

Entry: Takes the image directory in the form of a string.

Exit: Returns the image in the SDL_Surface pointer.
..........................................................................................
bool Retry()

Purpose:Prompts the user if they want to go again(emerging game loop).

Entry: char answer: single character that the user enters.  'y' will execute the loop again, while
'n' will end it.

Exit:bool again: checks whether the user wants to go again or not.  If so
it will trigger the main's while loop to execute again. 
..........................................................................................
void Close(SDL_Surface * KeyPresses[KEY_PRESS_SURFACE_TOTAL])

Purpose: Clears the memory of all data that was initialized during the program run.

Entry: none

Exit: none
...........................................................................................
SDL_Window* WindowGetter()

Purpose: Getter that retrieves the window data member

Entry: None

Exit: Returns the data member
*/


#ifndef CSURFMAN_H
#define CSURFMAN_H

#include <SDL.h>
#include <iostream>
#include "cKeyboard.h"
/*Class:cSurfMan

Constructors*/
class cSurfMan  : public cKeyBoard
{
public:
	
	bool Init(char * headerName[]);
	bool LoadMedia(SDL_Texture* KeySurfaces[KEY_PRESS_SURFACE_TOTAL], char * fileNames[]);
	SDL_Texture* LoadSurface(std::string);
	bool Retry();
	void Close(SDL_Texture * KeyPresses[KEY_PRESS_SURFACE_TOTAL]);
	void ConvertSurface(SDL_Surface * mCurrentSurface);
	SDL_Window* WindowGetter() { return mWindow; };

	//constructor
	cSurfMan();
	
	//destructor
	virtual ~cSurfMan();
	virtual void out() = 0;
private:
	//window to render to
	
	//surface containing window
	SDL_Surface* mScreenSurface;
	//current surface displaying window
	SDL_Surface* mStretchedSurface;

protected:
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
};
#endif // !CSURFMAN_H