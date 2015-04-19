#ifndef Perso_HEADER
#define Perso_HEADER

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include"LTexture2.h"
#include"Map.h"
#include <array>
using namespace std;
class Map;
class Bomb;
//Screen dimension constants
const int SCREEN_WIDTH = 540;
const int SCREEN_HEIGHT = 540;

class Perso
{
public:
	//The dimensions of the perso
	const int PERSO_WIDTH = 40;
	const int PERSO_HEIGHT = 40;

	//Maximum axis velocity of the perso
	const int PERSO_VEL = 5;

	//Initializes the variables
	Perso(int IDo, LTexture2* gDot11Texture, LTexture2* gDot21Texture, LTexture2* gDot31Texture, int xr, int y);

	//Takes key presses and adjusts the perso's velocity
	void handleEvent(SDL_Event& e);

	//Moves the perso
	void move(Map *carte);

	void bexp();

	//realise une action
	void action(Map *carte);
	//pose bombeet renvoie le temps
	void poseBombe(Map *carte);
	//active les bombes
	void actdeto(Map *carte);


	//Shows the perso on the screen
	void render(SDL_Renderer** gRenderer);




	//check if movement is possible
	bool xCheckCollision(Map *carte);
	bool yCheckCollision(Map *carte);

	//ramasser des objets
	void ramBomb();
	void ramPuiss();
	void ramDeto();

	int getID();
	int geti();
	int getj();
	int getvie();
	void pervie();

private:
	//The X and Y offsets of the perso
	int mPosX, mPosY;
	int ID;
	//possede le deto
	bool det;
	int puiss;
	//The velocity of the perso
	int mVelX, mVelY;
	//action du perso 0si pas d'action 1 si pose bombe 2 si deto
	int act;
	//Bombes dispos
	int Bd;
	//bombes possedees
	int Bp;
	//pl libre
	int pllib;
	int vies;
	LTexture2* gDot1Texture;
	LTexture2* gDot2Texture;
	LTexture2* gDot3Texture;
	
};

#endif
