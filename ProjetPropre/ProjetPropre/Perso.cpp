#include "Perso.h"
#include "Bomb.h"
#include "Map.h"


Perso::Perso(int IDo, LTexture2* gDot11Texture, LTexture2* gDot21Texture, LTexture2* gDot31Texture, int xr, int y)
{
	//Initialize the offsets
	mPosX = xr;
	mPosY =y;

	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;
	act = 0;
	Bd = 1;
	Bp = 1;
	pllib = 0;
	puiss = 1;
	int x(0);
	det = false;
	ID = IDo;
	vies = 2;
	gDot1Texture = gDot11Texture;
	gDot2Texture = gDot21Texture;
	gDot3Texture = gDot31Texture;
	
}



void Perso::handleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (ID == 1)
	{
		if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: mVelY -= PERSO_VEL; break;
			case SDLK_DOWN: mVelY += PERSO_VEL; break;
			case SDLK_LEFT: mVelX -= PERSO_VEL; break;
			case SDLK_RIGHT: mVelX += PERSO_VEL; break;
			}
		}
		//If a key was released
		else if (e.type == SDL_KEYUP && e.key.repeat == 0)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: mVelY += PERSO_VEL; break;
			case SDLK_DOWN: mVelY -= PERSO_VEL; break;
			case SDLK_LEFT: mVelX += PERSO_VEL; break;
			case SDLK_RIGHT: mVelX -= PERSO_VEL; break;
			case SDLK_m: act = 1; break;
			case SDLK_COMMA: act = 2; break;

			}
		}
	}
	if (ID == 2)
	{
		if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
			case SDLK_w: mVelY -= PERSO_VEL; break;
			case SDLK_s: mVelY += PERSO_VEL; break;
			case SDLK_a: mVelX -= PERSO_VEL; break;
			case SDLK_d: mVelX += PERSO_VEL; break;
			}
		}
		//If a key was released
		else if (e.type == SDL_KEYUP && e.key.repeat == 0)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
			case SDLK_w: mVelY += PERSO_VEL; break;
			case SDLK_s: mVelY -= PERSO_VEL; break;
			case SDLK_a: mVelX += PERSO_VEL; break;
			case SDLK_d: mVelX -= PERSO_VEL; break;
			case SDLK_1: act = 1; break;
			case SDLK_2: act = 2; break;

			}
		}
	}
	if (ID == 3)
	{
		if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: mVelY -= PERSO_VEL; break;
			case SDLK_DOWN: mVelY += PERSO_VEL; break;
			case SDLK_LEFT: mVelX -= PERSO_VEL; break;
			case SDLK_RIGHT: mVelX += PERSO_VEL; break;
			}
		}
		//If a key was released
		else if (e.type == SDL_KEYUP && e.key.repeat == 0)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: mVelY += PERSO_VEL; break;
			case SDLK_DOWN: mVelY -= PERSO_VEL; break;
			case SDLK_LEFT: mVelX += PERSO_VEL; break;
			case SDLK_RIGHT: mVelX -= PERSO_VEL; break;
			case SDLK_a: act = 1; break;
			case SDLK_z: act = 2; break;

			}
		}
	}
	if (ID == 4)
	{
		if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: mVelY -= PERSO_VEL; break;
			case SDLK_DOWN: mVelY += PERSO_VEL; break;
			case SDLK_LEFT: mVelX -= PERSO_VEL; break;
			case SDLK_RIGHT: mVelX += PERSO_VEL; break;
			}
		}
		//If a key was released
		else if (e.type == SDL_KEYUP && e.key.repeat == 0)
		{
			//Adjust the velocity
			switch (e.key.keysym.sym)
			{
			case SDLK_UP: mVelY += PERSO_VEL; break;
			case SDLK_DOWN: mVelY -= PERSO_VEL; break;
			case SDLK_LEFT: mVelX += PERSO_VEL; break;
			case SDLK_RIGHT: mVelX -= PERSO_VEL; break;
			case SDLK_a: act = 1; break;
			case SDLK_z: act = 2; break;

			}
		}
	}
}

void Perso::move(Map *carte)
{
	//Move the dot left or right
	mPosX += mVelX;

	//If the dot went too far to the left or right
	if (mPosX < 0 || mPosX >SCREEN_WIDTH)
	{
		//Move back
		mPosX -= mVelX;
	}
	else {  if (!xCheckCollision(carte)) { mPosX -= mVelX; } }
	//Move the dot up or down
	mPosY += mVelY;

	//If the dot went too far up or down
	if (mPosY<0 || mPosY >SCREEN_HEIGHT)
	{
		//Move back
		mPosY -= mVelY;
	}
	else { if (!yCheckCollision(carte)) { mPosY -= mVelY; } }
}

void Perso::render(SDL_Renderer* *gRenderer)
{
	(*gDot1Texture).setAlpha(190);
	(*gDot2Texture).setAlpha(199);
	(*gDot3Texture).setAlpha(210);
	//Show the dot
	switch (vies)
	{
	case 1:(*gDot1Texture).render(mPosX, mPosY, *gRenderer); break;
	case 2:(*gDot2Texture).render(mPosX, mPosY, *gRenderer); break;
	case 3:(*gDot3Texture).render(mPosX, mPosY, *gRenderer); break;
	}
	
}



int Perso :: getID(){ return ID; }
bool Perso::xCheckCollision(Map *carte)
{ 
	int j = mPosY / 45;
	int i = mPosX / 45;

	
		if ((mPosX % 45) == 0)
		{
			return(true);
		}
		else
		{
			if (i == 11){ return false; }
			else{
			if (mVelX == 0){ return true; }
			else
			{
			
				if ((mPosY % 45) == 0)
				{
					if (mVelX > 0){ return((!(*((*carte).getij(i + 1, j))).getdWall())); }
					else { return((!(*((*carte).getij(i, j))).getdWall())); }
				}
				else
				{
					if (mVelX > 0){ return((!(*((*carte).getij(i + 1, j))).getdWall()) && (!(*((*carte).getij(i + 1, j + 1))).getdWall())); }
					else { return((!(*((*carte).getij(i, j))).getdWall()) && (!(*((*carte).getij(i, j + 1))).getdWall())); }
				}
			}
		}
	}
};



bool Perso::yCheckCollision(Map *carte)
{
	int j = mPosY / 45;
	int i = mPosX / 45;

	
		if ((mPosY % 45) == 0)
		{
			return(true);
		}
		else
		{
			if (j == 11){ return false; }
			else{
			if (mVelY == 0){ return true; }
			else
			{
				if ((mPosX % 45) == 0)
				{
					if (mVelY > 0){ return((!(*((*carte).getij(i, j + 1))).getdWall())); }
					else { return((!(*((*carte).getij(i, j))).getdWall())); }
				}
				else
				{
					if (mVelY > 0){ return((!(*((*carte).getij(i, j + 1))).getdWall()) && (!(*((*carte).getij(i + 1, j + 1))).getdWall())); }
					else { return((!(*((*carte).getij(i, j))).getdWall()) && (!(*((*carte).getij(i + 1, j))).getdWall())); }
				}
			}
		}
	}
}
//objet sous le mur (0=rien, 1=bombe,2= deto,3=puissance,10=bombe posée) 
void Perso::action(Map *carte)
{
	int j = (mPosY + 22) / 45;
	int i = (mPosX + 22) / 45;

	switch (act)
	{
	case 0: break;
	case 1: poseBombe(carte);  break;
	case 2: actdeto(carte); break;
	}
	switch ((*((*carte).getij(i, j))).getob())
	{
	case 0:break;
	case 1: ramBomb(); break;
	case 2:ramDeto(); break;
	case 3:ramPuiss(); break;
	}
	if ((*((*carte).getij(i, j))).getob() != 10)
	{
		(*((*carte).getij(i, j))).pObjet(0);
	}
}

void Perso::poseBombe(Map *carte)
{
	
	int j = (mPosY + 22) / 45;
	int i = (mPosX + 22) / 45;
	if (Bd > 0)
	{
		(*((*carte).getij(i, j))).pObjet(10);
		(*((*carte).getbij(i, j))).amorce(i,j,puiss,det);
		(*((*carte).getbij(i, j))).setPerso(this);
		Bd -= 1;
		
		

	}
	act = 0;
	

}

void Perso::ramBomb(){ Bd += 1; Bp += 1; }

void Perso::ramDeto(){ det = true; }

void Perso::ramPuiss(){ puiss += 1; }


void Perso::actdeto(Map* carte)
{
	(*carte).actiP(this);

}
void Perso::bexp(){ Bd += 1; }
int Perso::geti(){	return 	((mPosX + 22) / 45);}
int Perso::getj(){ return 	((mPosY + 22) / 45); }
int Perso::getvie(){ return vies; }
void Perso::pervie()
{
	if (vies == 1)
	{
		ID = 0;
	}
	else{ vies = vies - 1; }
}
