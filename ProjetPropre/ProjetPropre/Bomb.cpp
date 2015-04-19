#include "Bomb.h"
#include "Perso.h"

Bomb::Bomb(int i,int j)
{
	tpsPos = 0;
	tpsRest = 0;
	Posi = i;
	Posj = j;
	puiss = 1;
	active = false;
	deto = false;
	J = new Perso(0,NULL,NULL,NULL,0,0);
}

void Bomb::uppuiss(){ puiss += 1; }
bool Bomb::check(){ return((SDL_GetTicks() > tpsRest)&&(!deto)); }
Uint32 Bomb::gettpsrest(){ return tpsRest; }
bool Bomb::getact(){ return active; }
int Bomb::getpuiss(){ return puiss; }

void Bomb::amorce(int i,int j,int pui,bool det){
	active = true; 
	Posi = i;
	Posj = j;
	puiss = pui;
	tpsPos = SDL_GetTicks();
	tpsRest = 2000 + tpsPos;
	deto = det;
}

void Bomb::desamorce()
{
	tpsPos = 0;
	tpsRest = 0;
	active = false;
}
int Bomb::geti() {return Posi;}
int Bomb::getj(){ return Posj; }
Perso* Bomb::getPerso(){  return J; }
void Bomb::setPerso(Perso *J1){  J=J1 ; }