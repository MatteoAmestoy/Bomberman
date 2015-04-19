#include "Map.h"
#include "Bomb.h"
#include "Perso.h"

Map::Map(SDL_Renderer* *gRender, LTexture2 *ver, LTexture2 *hor, Perso* J11, Perso *J12, Perso* J13, Perso* J14)
{

	int x(0);
	int y(0);

	for (x = 0; x < 12; x++)
	{
		for (y =0; y <12; y++)
		{
			bcarte[x][y] = new Bomb(0, 0);
			carte[x][y] = new Wall (x, y, 0);
			
		}

	}
	(*(carte[0][0])).Destroy();
	(*(carte[0][11])).Destroy();
	(*(carte[11][11])).Destroy();
	(*(carte[11][0])).Destroy();

	(*(carte[1][0])).Destroy();
	(*(carte[0][1])).Destroy();
	(*(carte[11][10])).Destroy();
	(*(carte[10][0])).Destroy();

	(*(carte[11][1])).Destroy();
	(*(carte[0][10])).Destroy();
	(*(carte[10][11])).Destroy();
	(*(carte[1][11])).Destroy();

	for (int a = 1; a < 12; a=a+3)
	{
		for (int b = 1; b < 12; b = b + 3)
		{
			(*(carte[a][b])).pstwall();

		}

	}
	for (int a = 0; a < 12; a = a+3)
	{
		for (int b = 1; b < 12; b = b + 4)
		{
			if ((*(carte[a][b])).getdWall()){ (*(carte[a][b])).pObjet(1); (*(carte[b][a])).pObjet(3); }
		}

	}


	
	(*(carte[3][3])).pObjet(2);
	(*(carte[8][8])).pObjet(2);
	(*(carte[8][3])).pObjet(2);
	(*(carte[3][8])).pObjet(2);

	gRenderer = gRender;
	vert = ver;
	hori = hor;
	J1 = J11;
	J2 = J12;
	J3 = J13;
	J4 = J14;



}

Wall* Map::getij(int i, int j){ return carte[i][j]; };
Bomb* Map::getbij(int i, int j){ return bcarte[i][j]; };


//objet sous le mur (0=rien, 1=bombe,2= deto,3=puissance,10=bombe posée) 
void Map::render(LTexture2 *gWallTexture, LTexture2 *gBombPosTexture, LTexture2 *gBombTexture, LTexture2 *gDetoTexture, LTexture2 *gPuissTexture, LTexture2 *gStWallTexture)
{
	int x(0);
	int y(0);

	for (x = 0; x < 12; x++)
	{
		for (y = 0; y <12; y++)
		{
			if ((*(carte[x][y])).getdWall())
			{
				if ((*(carte[x][y])).getStWall())
				{
					(*gStWallTexture).render((*(carte[x][y])).getmPosX(), (*(carte[x][y])).getmPosY(), *gRenderer);
				}
				else
				{
					(*gWallTexture).render((*(carte[x][y])).getmPosX(), (*(carte[x][y])).getmPosY(), *gRenderer);
				}
			}
			else
			{
				switch ((*(carte[x][y])).getob())
				{
				case 0: break;
				case 1: (*gBombTexture).render((*(carte[x][y])).getmPosX(), (*(carte[x][y])).getmPosY(), *gRenderer); break;
				case 2: (*gDetoTexture).render((*(carte[x][y])).getmPosX(), (*(carte[x][y])).getmPosY(), *gRenderer); break;
				case 3: (*gPuissTexture).render((*(carte[x][y])).getmPosX(), (*(carte[x][y])).getmPosY(), *gRenderer); break;
				case 10:(*gBombPosTexture).render((*(carte[x][y])).getmPosX(), (*(carte[x][y])).getmPosY(), *gRenderer); break;
				}
			}
		}

	}
	
	if ((*J1).getID() != 0){ (*J1).render(gRenderer); }
	if ((*J2).getID() != 0){ (*J2).render(gRenderer); }
	if ((*J3).getID() != 0){ (*J3).render(gRenderer); }
	if ((*J4).getID() != 0){ (*J4).render(gRenderer); }


}





void Map::actiP(Perso* J)
{

	int x(0);
	int y(0);

	for (x = 0; x < 12; x++)
	{
		for (y = 0; y < 12; y++)
		{
			if ((*(bcarte[x][y])).getact())
			{
				if ((*((*(bcarte[x][y])).getPerso())).getID()==(*J).getID())
				{
					BBexp(x, y, (*(bcarte[x][y])).getpuiss());
					(*(bcarte[x][y])).desamorce();

				}

			}
		}

	}


}


void Map::acti()
{

	int x(0);
	int y(0);

	for (x = 0; x < 12; x++)
	{
		for (y = 0; y < 12; y++)
		{
			if ((*(bcarte[x][y])).getact())
			{
				if ((*(bcarte[x][y])).check())
				{
					
					BBexp(x, y, (*(bcarte[x][y])).getpuiss());
					(*(bcarte[x][y])).desamorce();
					
				}

			}
		}

	}


}











int maxi(int a, int b){ if (a < b){ return b; } else { return a; } }
int mini(int a, int b){ if (a > b){ return b; } else { return a; } }



void Map::BBexp(int i, int j, int puiss)
{
	int X(0);
	bool u;
	(*(carte[i][j])).pObjet(0);
	(*((*(bcarte[i][j])).getPerso())).bexp();
	if (((*J1).getID() != 0) && ((*J1).geti() == i) && ((*J1).getj() == j)){ (*J1).pervie(); }
	if (((*J2).getID() != 0) && ((*J2).geti() == i) && ((*J2).getj() == j)){ (*J2).pervie(); }
	if (((*J3).getID() != 0) && ((*J3).geti() == i) && ((*J3).getj() == j)){ (*J3).pervie(); }
	if (((*J4).getID() != 0) && ((*J4).geti() == i) && ((*J4).getj() == j)){ (*J4).pervie(); }
	u = true;
	X = i+1;
	while (u && (X < mini(12, (i + 1 + puiss))))
	{
		
		u = detruire(X, j);
		(*hori).render(X*45, j*45, *gRenderer);
		X += 1;
	}
	u = true;
	X = i-1;
	while (u && (X > maxi(-1, (i - puiss-1))))
	{
		u = detruire(X, j);
		(*hori).render(X * 45, j * 45, *gRenderer);
		X =X -1;
	}
	u = true;
	X = j+1;
	while (u && (X < mini(12, (j+ 1 + puiss))))
	{
		u = detruire(i, X);
		(*vert).render(i * 45, X * 45, *gRenderer);
		X += 1;
	}
	u = true;
	X = j-1;
	while (u && (X >maxi(-1, (j - puiss-1))))
	{
		u = detruire(i, X);
		(*vert).render(i * 45, X * 45, *gRenderer);
		X = X-1;
	}
	
	
}





bool Map::detruire(int i, int j)
{
	if ((*(carte[i][j])).getdWall()){ (*(carte[i][j])).Destroy(); return(false); }
	else
	{
		if (((*J1).getID()!=0)&&((*J1).geti() == i) && ((*J1).getj() == j)){ (*J1).pervie(); }
		if (((*J2).getID() != 0) && ((*J2).geti() == i) && ((*J2).getj() == j)){ (*J2).pervie(); }
		if (((*J3).getID() != 0) && ((*J3).geti() == i) && ((*J3).getj() == j)){ (*J3).pervie(); }
		if (((*J4).getID() != 0) && ((*J4).geti() == i) && ((*J4).getj() == j)){ (*J4).pervie(); }
		if ((*(carte[i][j])).getob() == 0){ return  true; }
		else{
			if ((*(carte[i][j])).getob() == 10){ BBexp(i, j, (*(bcarte[i][j])).getpuiss()); (*(bcarte[i][j])).desamorce(); return(true); }
			else
			{
				(*(carte[i][j])).pObjet(0); return false;
			}
		}
	}

}

