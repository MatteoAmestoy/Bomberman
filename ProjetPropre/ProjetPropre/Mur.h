#ifndef Mur_HEADER
#define Mur_HEADER


#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "LTexture2.h"


//Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

class Wall
{
public:
	//The dimensions of the perso
	const int WALL_WIDTH = 45;
	const int WAll_HEIGHT = 45;

	//Initializes the variables
	Wall(int xpos,int ypos, int ob);

	//Destroy wall
	void Destroy();
	//mettre un objet sous le mur (creation de carte)
	void pObjet(int ob);

	//Shows the wall on the screen
	void render(SDL_Renderer** gRenderer, LTexture2* gWallTexture);

	//getter
	int getmPosX();
	int getmPosY();
	bool getdWall();
	int getob();
	bool getStWall();
	void pstwall();

private:
	//The X and Y offsets of the perso
	int mPosX, mPosY;
	//Position i,j du mur
	int mPosi, mPosj;

	bool Strongwall;
	// if wall is still here
	bool dWall;
	//if there is an object
	bool dobject;

	//objet sous le mur (0=rien, 1=bombe,2= deto,3=puissance) 
	int objet;
};


#endif
