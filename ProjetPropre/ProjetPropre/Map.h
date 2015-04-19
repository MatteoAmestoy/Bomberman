#ifndef Map_HEADER
#define Map_HEADER
#include "Bomb.h"
#include "Mur.h"
#include "Perso.h"
#include <vector>
#include <array>
#include <utility>
#include "LTexture2.h"

using namespace std;

class Perso;
class Bomb;
class Map
{
public:
	Map(SDL_Renderer* *gRender, LTexture2 *ver, LTexture2 *hor,  Perso* J11, Perso *J12, Perso* J13, Perso* J14);

	void render(LTexture2 *gWallTexture, LTexture2 *gBombPosTexture, LTexture2 *gBombTexture, LTexture2 *gDetoTexture, LTexture2 *gPuissTexture, LTexture2 *gStWallTexture);
	Wall* getij(int i, int j);
	Bomb* getbij(int i, int j);
	void BBexp(int i, int j, int puiss);
	bool detruire(int i, int j);
	
	void acti();
	void actiP(Perso* J);
private:

	SDL_Renderer* *gRenderer;
	LTexture2 *vert;
	LTexture2 *hori;
	// la carte sera une matrice de taille width*height avec mur
	array<array< Wall* , 12>, 12> carte;
	// carte des bombes posees
	array<array< Bomb*, 12>, 12> bcarte;
	Perso* J1;
	Perso *J2;
	Perso*J3;
	Perso* J4;
};
#endif