#include "Menu.h"


Menu::Menu(SDL_Renderer* *gRender)
{
	
}


void Menu::PageAcc(SDL_Renderer* *gRender)
{
	if (!loadMedia(gRender))
	{
		printf("Failed to load media!\n");
	}
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT: quit = true;
			case SDL_MOUSEBUTTONDOWN:
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					if ((80<e.button.x) && (e.button.x<310) && (100<e.button.y) && (e.button.y<148))
					{
						int a = NbrJoueurs(gRender);
						if (a != 0)
						{
							int b = ChoixMap(gRender);
							if (b != 0)
							{
								jeu(gRender, a, b);
							}
						}
					}
					if ((80<e.button.x) && (e.button.x<310) && (180<e.button.y) && (e.button.y<228))
					{
						PageRegles(gRender);
					}

					if ((80<e.button.x) && (e.button.x<310) && (260<e.button.y) && (e.button.y<308))
					{
						PageConfig(gRender);
					}
				}
			}
			//User requests quit
			
			//Clear screen
			SDL_SetRenderDrawColor(*gRender, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(*gRender);
			gBaseTexture.render(0, 0, *gRender);
			gBoutonJouerTexture.render(80, 100, *gRender);
			gBouton1Texture.render(80, 180, *gRender);
			gBouton3Texture.render(80, 260, *gRender);
			SDL_RenderPresent(*gRender);

		}
	}

}

int Menu::NbrJoueurs(SDL_Renderer* *gRender)
{

	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	int a = 0;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT: quit = true;
			case SDL_MOUSEBUTTONDOWN:
				if (e.button.button == SDL_BUTTON_LEFT)
				{

					if ((80<e.button.x) && (e.button.x<310) && (450<e.button.y) && (e.button.y<498))
					{
						quit = true;
					}
					if ((80<e.button.x) && (e.button.x<310) && (150<e.button.y) && (e.button.y<198))
					{
						a = 2;
						quit = true;

					}

					if ((80<e.button.x) && (e.button.x<310) && (230<e.button.y) && (e.button.y<278))
					{
						a = 3;
						quit = true;
					}
					if ((80<e.button.x) && (e.button.x<310) && (310<e.button.y) && (e.button.y<358))
					{
						a = 4;
						quit = true;
					}
				}
			}
			//User requests quit

			//Clear screen
			SDL_SetRenderDrawColor(*gRender, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(*gRender);
			gBaseJTexture.render(0, 0, *gRender);
			g1JTexture.render(80, 150, *gRender);
			g2JTexture.render(80, 230, *gRender);
			g3JTexture.render(80, 310, *gRender);
			gRetourTexture.render(80, 450, *gRender);
			
			SDL_RenderPresent(*gRender);

		}
	}
	return(a);
}
int Menu::ChoixMap(SDL_Renderer* *gRender)
{

	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	int a = 0;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT: quit = true;
			case SDL_MOUSEBUTTONDOWN:
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					if ((80<e.button.x) && (e.button.x<310) && (450<e.button.y) && (e.button.y<498))
					{
						quit = true;
					}
					if ((80<e.button.x) && (e.button.x<310) && (150<e.button.y) && (e.button.y<198))
					{
						a = 1;
						quit = true;

					}

					if ((80<e.button.x) && (e.button.x<310) && (230<e.button.y) && (e.button.y<278))
					{
						a = 2;
						quit = true;
					}
				
				}
			}
			//User requests quit

			//Clear screen
			SDL_SetRenderDrawColor(*gRender, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(*gRender);
			gBaseCTexture.render(0, 0, *gRender);
			gClassTexture.render(80, 150, *gRender);
			gRushTexture.render(80, 230, *gRender);
			gRetourTexture.render(80, 450, *gRender);
			SDL_RenderPresent(*gRender);

		}
	}
	return(a);
}

void Menu::gain(SDL_Renderer* *gRender, int j)
{
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			SDL_SetRenderDrawColor(*gRender, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(*gRender);
			switch (j)
			{
			case 0:ggain0Texture.render(0, 0, *gRender); break;
			case 1:ggain1Texture.render(0, 0, *gRender); break;
			case 2:ggain2Texture.render(0, 0, *gRender); break;
			case 3:ggain3Texture.render(0, 0, *gRender); break;
			case 4:ggain4Texture.render(0, 0, *gRender); break;
			}
			SDL_RenderPresent(*gRender);
		}
	}
}
void Menu::PageRegles(SDL_Renderer* *gRender)
{
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT: quit = true;
			case SDL_MOUSEBUTTONDOWN:
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					if ((80 < e.button.x) && (e.button.x < 310) && (490 < e.button.y) && (e.button.y < 538))
					{
						quit = true;
					}
				}
			}

			SDL_SetRenderDrawColor(*gRender, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(*gRender);
			
			gRulesTexture.render(0, 0, *gRender);
			gRetourTexture.render(80, 490, *gRender);
			SDL_RenderPresent(*gRender);
		}
	}



}
void Menu::PageConfig(SDL_Renderer* *gRender)
{
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT: quit = true;
			case SDL_MOUSEBUTTONDOWN:
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					if ((80 < e.button.x) && (e.button.x < 310) && (490 < e.button.y) && (e.button.y < 538))
					{
						quit = true;
					}
				}
			}

			SDL_SetRenderDrawColor(*gRender, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(*gRender);

			gControlesTexture.render(0, 0, *gRender);
			gRetourTexture.render(80, 490, *gRender);
			SDL_RenderPresent(*gRender);
		}
	}



}



bool Menu::loadMedia(SDL_Renderer* *gRender)
{
	//Loading success flag
	bool success = true;

	//Load dot texture

	if (!(gBombPosTexture).loadFromFile("image/bombe.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gWallTexture).loadFromFile("image/wall.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gBombTexture).loadFromFile("image/BombRa.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDetoTexture).loadFromFile("image/Deto.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gPuissTexture).loadFromFile("image/Puiss.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gExpVTexture).loadFromFile("image/expvert.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gExpHTexture).loadFromFile("image/exphori.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDotP1V1Texture).loadFromFile("image/1vies1.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDotP1V2Texture).loadFromFile("image/2vies1.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDotP1V3Texture).loadFromFile("image/3vies1.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDotP2V1Texture).loadFromFile("image/1vies2.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDotP2V2Texture).loadFromFile("image/2vies2.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gDotP2V3Texture).loadFromFile("image/3vies2.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gStWallTexture).loadFromFile("image/StWall.bmp", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}

	if (!(gRulesTexture).loadFromFile("image/Rules.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}


	if (!(ggain1Texture).loadFromFile("image/gain1.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(ggain0Texture).loadFromFile("image/gain0.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(ggain2Texture).loadFromFile("image/gain2.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(ggain3Texture).loadFromFile("image/gain3.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(ggain4Texture).loadFromFile("image/gain4.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gBaseTexture).loadFromFile("image/Base.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gBaseJTexture).loadFromFile("image/BaseJ.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gBaseCTexture).loadFromFile("image/BaseC.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gBouton1Texture).loadFromFile("image/Bouton1.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gBoutonJouerTexture).loadFromFile("image/BoutonJouer.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gBouton3Texture).loadFromFile("image/Bouton3.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(g1JTexture).loadFromFile("image/1J.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(g2JTexture).loadFromFile("image/2J.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(g3JTexture).loadFromFile("image/3J.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gRushTexture).loadFromFile("image/Rush.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gClassTexture).loadFromFile("image/Class.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gControlesTexture).loadFromFile("image/Controles.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	if (!(gRetourTexture).loadFromFile("image/Retour.png", *gRender))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}
	


	return success;
}


void Menu::close(SDL_Renderer* *gRender)
{
	SDL_DestroyRenderer(*gRender);
	gWallTexture.free();
	gBombPosTexture.free();
	gBombTexture.free();
	gDetoTexture.free();
	gPuissTexture.free();
	gStWallTexture.free();
	gDotP1V2Texture.free();
	gDotP1V1Texture.free();
	gDotP1V3Texture.free();
	gDotP2V2Texture.free();
	gDotP2V1Texture.free();
	gDotP2V3Texture.free();
	gRulesTexture.free();
	ggain0Texture.free();
	ggain1Texture.free();
	ggain2Texture.free();
	ggain3Texture.free();
	ggain4Texture.free();
	gBaseTexture.free();
	gBaseJTexture.free();
	gBouton1Texture.free();
	gBouton3Texture.free();
	g1JTexture.free();
	g2JTexture.free();
	g3JTexture.free();
	gBoutonJouerTexture.free();
	gControlesTexture.free();
	gRetourTexture.free();
	*gRender = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Menu::jeu(SDL_Renderer* *gRende,int a,int b)
{
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	int u = 0;
	int f = 0;
	//The dot that will be moving around on the screen
	if (a == 0){ quit = true; }
	if (a > 2){ u = 3; };
	if (a > 3){ f = 4; };
	Perso dot1(1, &gDotP1V1Texture, &gDotP1V2Texture, &gDotP1V3Texture, 0, 0);
	Perso dot2(2, &gDotP2V1Texture, &gDotP2V2Texture, &gDotP2V3Texture, 495, 495);
	Perso dot3(u, &gDotP2V1Texture, &gDotP2V2Texture, &gDotP2V3Texture, 0, 495);
	Perso dot4(f, &gDotP2V1Texture, &gDotP2V2Texture, &gDotP2V3Texture, 495, 0);
	//Wall mur(10,10,0);
	Map carte(gRende, &gExpVTexture, &gExpHTexture, &dot1, &dot2, &dot3, &dot4,b);
	//While application is running
	while (!quit)
	{
		switch (dot1.getID() + 2 * dot2.getID() + 3 * dot3.getID() + 4 * dot4.getID())
		{
		case 0:gain(gRende, 0); quit = true; break;
		case 1: gain(gRende, 1); quit = true; break;
		case 4: gain(gRende, 2); quit = true; break;
		case 9: gain(gRende, 3); quit = true; break;
		case 16: gain(gRende, 4); quit = true; break;
		}
		//Handle events on queue
		while ((SDL_PollEvent(&e) != 0))
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
		SDL_SetRenderDrawColor(*gRende, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(*gRende);

		//Move the dot
		if (dot1.getID() != 0)
		{
			dot1.move(&carte);
			dot1.action(&carte);
		}
		if (dot2.getID() != 0)
		{
			dot2.move(&carte);
			dot2.action(&carte);
		}
		if (dot3.getID() != 0)
		{
			dot3.move(&carte);
			dot3.action(&carte);
		}
		if (dot4.getID() != 0)
		{
			dot4.move(&carte);
			dot4.action(&carte);
		}
		carte.acti();


		//Render objects
		carte.render(&gWallTexture, &gBombPosTexture, &gBombTexture, &gDetoTexture, &gPuissTexture, &gStWallTexture);


		//Update screen
		SDL_RenderPresent(*gRende);

		
	}
}