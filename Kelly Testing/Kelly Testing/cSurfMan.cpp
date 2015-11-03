//Kelly Honsinger
#include "cSurfMan.h"
cSurfMan::cSurfMan()
{
	mWindow = nullptr;
	mScreenSurface = nullptr;
	mStretchedSurface = nullptr;
	mRenderer = nullptr;
	int mWidth = 0;
	int mHeight = 0;
}

cSurfMan::~cSurfMan() 
{
}
bool cSurfMan::Init(char * argv[])
{
	bool pass = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Initialization failure. ERROR: ", SDL_GetError();
		pass = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			cout << "Linear Texture Filtering not enabled!";
		}
		 
		mWindow = SDL_CreateWindow(argv[1], SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (mWindow == nullptr)
		{
			cout << "Can't Create Window! SDL ERROR: " << SDL_GetError();
			pass = false;
		}
		else
		{
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
			if (mRenderer == nullptr)
			{
				cout << "Renderer Failed to be created!";
				pass = false;
			}
			else
			{	
				SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);  //RGB Opacity

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					cout << "SDL_Image couldn't initialize!";
					pass = false;
				}
			}
		}
	}
	return pass;
}

bool cSurfMan::LoadMedia(SDL_Texture *KeySurfaces[IMAGE_SIXTH], char * vArg[])
{
	bool success = true;
	//load sprite texture here 
	
	
	KeySurfaces[IMAGE_FIRST] = LoadSurface(vArg[1]); //Default Key
	if (KeySurfaces[IMAGE_FIRST] == nullptr)							  //Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	KeySurfaces[IMAGE_SECOND] = LoadSurface(vArg[2]);	//Up Key
	if (KeySurfaces[IMAGE_SECOND] == nullptr)							//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	KeySurfaces[IMAGE_THIRD] = LoadSurface(vArg[3]); //Down Key
	if (KeySurfaces[IMAGE_THIRD] == nullptr)							  //Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	KeySurfaces[IMAGE_FOURTH] = LoadSurface(vArg[4]);//Left Key
	if (KeySurfaces[IMAGE_FOURTH] == nullptr)							//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";	
		success = false;
	}

	KeySurfaces[IMAGE_FIFTH] = Loadtexture(vArg[5]);	//Right Key
	if (KeySurfaces[IMAGE_FIFTH] == nullptr)							//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	
	//bool returns successful 
	return success;
}

SDL_Texture * cSurfMan::Loadtexture(string path)
{
	SDL_Texture * tempTexture = nullptr;

	SDL_Surface* tempSurface = IMG_Load(path.c_str());
	if (tempSurface == nullptr)
	{
		cout << "unable to load image! SDL Error:" << IMG_GetError();
	}
	else
	{
		SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 0, 0xFF, 0xFF));  //(format, Red,Green,Blue)

		tempTexture = SDL_CreateTextureFromSurface(mRenderer, tempSurface);
		if (tempTexture == nullptr)
		{
			cout << "Unable to Create Texture! SDL Error:" << SDL_GetError();
		}
		
	}
	return tempTexture;
}


SDL_Texture* cSurfMan::LoadSurface(std::string path)
{	
	//Texture 
	SDL_Texture *tempTexture= nullptr;
	//create cSurfMan object to access getter from the class

	

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		cout << "Unable to load image, SDL Error: %s\n" << SDL_GetError();
	}
	else
	{
			//Convert surface to texture
			tempTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
			if (tempTexture == nullptr)
			{
				cout << "Unable to create texture from image! SDL Error:" << SDL_GetError();
			}

			//Get rid of old loaded surfaces
			SDL_FreeSurface(loadedSurface);
			loadedSurface = nullptr;
	}
	return tempTexture;
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

void cSurfMan::Close(SDL_Texture * KeyPresses[IMAGE_SIXTH])
{
	for (int i = 0; i < IMAGE_SIXTH; i++)
	{
		SDL_DestroyTexture(KeyPresses[i]);
		KeyPresses[i] = nullptr;
	}
	//destroy window and renderer
	SDL_DestroyRenderer(mRenderer);
	mRenderer = nullptr;
	SDL_FreeSurface(mStretchedSurface);
	mStretchedSurface = nullptr;

	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;

	SDL_Quit();
}