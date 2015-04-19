#include "Mur.h"





Wall::Wall(int xpos, int ypos, int ob)
{
	//Initialize the offsets
	mPosi = xpos;
	mPosj = ypos;
	mPosX = WALL_WIDTH*mPosi;
	mPosY = WALL_WIDTH*mPosj;

	dWall=true;
	Strongwall = false;
	//objet sous le mur (0=rien, 1=bombe,2= deto,3=puissance,10=bombe posée) 
	objet=ob;
}


void Wall::Destroy(){ if (!Strongwall){ dWall = false; } }
void Wall::pObjet(int ob){ objet = ob; }
int Wall::getmPosY(){ return mPosY; }
int Wall::getmPosX(){ return mPosX; }
bool Wall::getdWall(){ return dWall; }
bool Wall::getStWall(){ return Strongwall; }
int Wall::getob(){ return objet; }
void Wall::pstwall(){ Strongwall = true; }
void Wall::render(SDL_Renderer* *gRenderer, LTexture2 *gWallTexture)
{
	//Show the dot
	(*gWallTexture).render(mPosX, mPosY, *gRenderer);
}


