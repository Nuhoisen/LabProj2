#ifndef CSPRITEGAMELOOP_H
#define CSPRITEGAMELOOP_H
#include "cSurfMan.h"
class cSpriteGameLoop :	public cSurfMan
{
public:
	cSpriteGameLoop();
	cSpriteGameLoop(cSpriteGameLoop & cpy);
	cSpriteGameLoop & operator=(cSpriteGameLoop & opCopy);
	virtual ~cSpriteGameLoop();
	
	void SpriteRender(SDL_Rect* clip, SDL_Texture * tempTexture,  const int tim);

	SDL_Rect *ReturnRect();
	SDL_Rect *ReturnRect1();

	virtual void out();
private:
	SDL_Rect mSpriteClips[2];
	

	int hWidth = 750;
	int hHeight = 586;
	

};
#endif
