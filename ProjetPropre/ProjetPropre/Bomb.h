#ifndef Bomb_HEADER
#define Bomb_HEADER



#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Perso.h"

class Perso;

class Bomb
{
public:
	Bomb(int i,int j);
	Uint32 gettpsrest();

	bool getact();
	void amorce(int j, int i,int pui,bool det);
	void uppuiss();
	bool check();
	void desamorce();
	int geti();
	int getj();
	int getpuiss();
	Perso* getPerso();

	void setPerso(Perso* J1);

private:
	bool deto;
	int puiss;
	Uint32 tpsPos;
	Uint32 tpsRest;
	int Posi, Posj;
	bool active;
	Perso* J;
	
};

#endif