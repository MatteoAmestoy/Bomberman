//Using SDL, SDL_image, standard IO, and strings
#include "Mur.h"
#include "Perso.h"
#include "LTexture2.h"
#include "Map.h"



//The application time based timer
class LTimer
{
public:
	//Initializes variables
	LTimer();

	//The various clock actions
	void start();
	void stop();
	void pause();
	void unpause();

	//Gets the timer's time
	Uint32 getTicks();

	//Checks the status of the timer
	bool isStarted();
	bool isPaused();

private:
	//The clock time when the timer started
	Uint32 mStartTicks;

	//The ticks stored when the timer was paused
	Uint32 mPausedTicks;

	//The timer status
	bool mPaused;
	bool mStarted;
};

//The dot that will move around on the screen

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

LTexture2 gDotTexture;
LTexture2 gDotP1V1Texture;
LTexture2 gDotP1V2Texture;
LTexture2 gDotP1V3Texture;
LTexture2 gWallTexture;
LTexture2 gBombPosTexture;
LTexture2 gBombTexture;
LTexture2 gDetoTexture;
LTexture2 gPuissTexture;
LTexture2 gExpVTexture;
LTexture2 gExpHTexture;
LTexture2 gStWallTexture;



bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;
	
	//Load dot texture
	if (!(gDotTexture).loadFromFile("image/Droite.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gBombPosTexture).loadFromFile("image/bombe.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gWallTexture).loadFromFile("image/wall.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gBombTexture).loadFromFile("image/BombRa.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDetoTexture).loadFromFile("image/Deto.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gPuissTexture).loadFromFile("image/Puiss.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gExpVTexture).loadFromFile("image/expvert.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gExpHTexture).loadFromFile("image/exphori.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDotP1V1Texture).loadFromFile("image/1vies1.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDotP1V2Texture).loadFromFile("image/2vies1.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDotP1V3Texture).loadFromFile("image/3vies1.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gStWallTexture).loadFromFile("image/StWall.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}

	
	return success;
}

void close()
{
	//Free loaded images
	(gDotTexture).free();

	//Destroy window   
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	gDotTexture.free();
	gWallTexture.free();
	gBombPosTexture.free();
	gBombTexture.free();
	gDetoTexture.free();
	gPuissTexture.free();
	gStWallTexture.free();
	gDotP1V2Texture.free();
	gDotP1V1Texture.free();
	gDotP1V3Texture.free();
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		
		else
		{
			//Main loop flag
			bool quit = false;
			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Perso dot1(1, &gDotP1V1Texture, &gDotP1V2Texture, &gDotP1V3Texture,0,0);
			Perso dot2(2, &gDotP1V1Texture, &gDotP1V2Texture, &gDotP1V3Texture, 495, 495);
			Perso dot3(0, NULL, NULL, NULL,0,0);
			Perso dot4(0, NULL, NULL, NULL,0,0);
			//Wall mur(10,10,0);
			Map carte(&gRenderer, &gExpVTexture, &gExpHTexture, &dot1,&dot2, &dot3, &dot4);
			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					//Handle input for the dot
					dot1.handleEvent(e); 
					dot2.handleEvent(e);
					dot3.handleEvent(e);
					dot4.handleEvent(e);
				}
				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Move the dot
				if (dot1.getID()!=0)
				{dot1.move(&carte);
				dot1.action(&carte);
				}
				if (dot2.getID() != 0)
				{dot2.move(&carte);
				dot2.action(&carte);
				}
				if (dot3.getID() != 0)
				{dot3.move(&carte);
				dot3.action(&carte);
				}
				if (dot4.getID() != 0)
				{dot4.move(&carte);
				dot4.action(&carte);
				}
				carte.acti();
				
	
				//Render objects
				carte.render(&gWallTexture, &gBombPosTexture, &gBombTexture, &gDetoTexture, &gPuissTexture, &gStWallTexture);
				
				
				//Update screen
				SDL_RenderPresent(gRenderer);
				
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}