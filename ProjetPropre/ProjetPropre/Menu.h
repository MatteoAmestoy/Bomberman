#ifndef Menu_HEADER
#define Menu_HEADER
#include "Bomb.h"
#include "Mur.h"
#include "Perso.h"
#include <vector>
#include <array>
#include <utility>
#include "LTexture2.h"

using namespace std;
class Menu
{
public:
	Menu(SDL_Renderer* *gRender);
	
	void PageAcc(SDL_Renderer* *gRender);
	void PageRegles(SDL_Renderer* *gRender);
	void PageConfig(SDL_Renderer* *gRender);


	void close(SDL_Renderer* *gRender);
	bool loadMedia(SDL_Renderer* *gRender);

	int NbrJoueurs(SDL_Renderer* *gRender);
	int ChoixMap(SDL_Renderer* *gRender);
	void jeu(SDL_Renderer* *gRende,int a,int b);
	void gain(SDL_Renderer* *gRender,int j);
private:

	//Menu texture
	
	LTexture2 gRulesTexture;
	LTexture2 ggain0Texture;
	LTexture2 ggain1Texture;
	LTexture2 ggain2Texture;
	LTexture2 ggain3Texture;
	LTexture2 ggain4Texture;

	//Game Texture
	LTexture2 gDotP1V1Texture;
	LTexture2 gDotP1V2Texture;
	LTexture2 gDotP1V3Texture;
	LTexture2 gDotP2V1Texture;
	LTexture2 gDotP2V2Texture;
	LTexture2 gDotP2V3Texture;
	LTexture2 gWallTexture;
	LTexture2 gBombPosTexture;
	LTexture2 gBombTexture;
	LTexture2 gDetoTexture;
	LTexture2 gPuissTexture;
	LTexture2 gExpVTexture;
	LTexture2 gExpHTexture;
	LTexture2 gStWallTexture;
	LTexture2 gBaseTexture;
	LTexture2 gBaseJTexture;
	LTexture2 gBaseCTexture;
	LTexture2 gControlesTexture;
	LTexture2 gBouton1Texture;
	LTexture2 gBoutonJouerTexture;
	LTexture2 gBouton3Texture;
	LTexture2 g1JTexture;
	LTexture2 g2JTexture;
	LTexture2 g3JTexture;
	LTexture2 gRushTexture;
	LTexture2 gClassTexture;
	LTexture2 gRetourTexture;
	

};

#endif