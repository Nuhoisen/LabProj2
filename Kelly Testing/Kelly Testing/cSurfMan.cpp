//Kelly Honsinger

#include "cSurfMan.h"


const int WIDTH = 640;
const int HEIGHT = 480;
cSurfMan::cSurfMan()
{
	mWindow = nullptr;
	mScreenSurface = nullptr;
	mStretchedSurface = nullptr;

}

cSurfMan::~cSurfMan() {}
bool cSurfMan::Init(string * header)
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
		 
		mWindow = SDL_CreateWindow(header[1].c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
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
				SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

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

bool cSurfMan::LoadMedia(SDL_Texture *KeySurfaces[KEY_PRESS_SURFACE_TOTAL], string * files)
{
	bool success = true;

	KeySurfaces[KEY_PRESS_SURFACE_DEFAULT] = LoadSurface(files[1].c_str()); //Default Key
	if (KeySurfaces[KEY_PRESS_SURFACE_DEFAULT] == nullptr)							  //Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	KeySurfaces[KEY_PRESS_SURFACE_UP] = LoadSurface(files[2].c_str());	//Up Key
	if (KeySurfaces[KEY_PRESS_SURFACE_UP] == nullptr)							//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	KeySurfaces[KEY_PRESS_SURFACE_DOWN] = LoadSurface(files[3].c_str()); //Down Key
	if (KeySurfaces[KEY_PRESS_SURFACE_DOWN] == nullptr)							  //Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}

	KeySurfaces[KEY_PRESS_SURFACE_LEFT] = LoadSurface(files[4].c_str());//Left Key
	if (KeySurfaces[KEY_PRESS_SURFACE_LEFT] == nullptr)							//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";	
		success = false;
	}

	KeySurfaces[KEY_PRESS_SURFACE_RIGHT] = LoadSurface(files[5].c_str());	//Right Key
	if (KeySurfaces[KEY_PRESS_SURFACE_RIGHT] == nullptr)							//Checks that the image successfully opened
	{
		cout << "Failed to load default image!\n";
		success = false;
	}
	//bool returns successful 
	return success;
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

void cSurfMan::Close(SDL_Texture * KeyPresses[KEY_PRESS_SURFACE_TOTAL])
{
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
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