/*

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
                    Version 2, December 2004

 Copyright (C) 2010 Sauer2 

 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO. 

*/

/*This file contains the main structure of this game*/


#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include "filehandler.h"
#include "clouds.h"
#include "birds.h"
#include "player.h"
#include "obstacles.h"
#include "lifes.h"

void DrawBackground (SDL_Surface *target)//draws the blue background
{
	SDL_FillRect(target,NULL,SDL_MapRGB(target->format, 200, 222, 255));
}



/*The main procedure*/

int main(){
	SDL_Surface *screen;
	/*Creates the canvas*/
	atexit(SDL_Quit);
	/*Starting SDL*/
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}
	else
	{
		printf("SDL initialized!\n");
	}

	screen = SDL_SetVideoMode(320, 480, 16, SDL_SWSURFACE);
	if (screen == NULL) {
		fprintf(stderr, "Unable to set video mode: %s\n", SDL_GetError());
		exit(1);
	}

	/*All the initialization stuff*/
	SDL_WM_SetCaption("Falling - An anti-gravity game","Falling Pre-Alpha");
	/*Loading all Images follows...*/
	LoadPlayerImages();
	LoadObstacleImages();
	LoadLifeImages();
	LoadCloudImages();
	LoadBirdImages();
	printf("Images loaded!\n");
	/*Loading finished*/
	/*The main loop variables*/
	int running = 1;
	int klicked = 0;
	int scene = 1; 
	SDL_Event event;
	/*Time and Stuff*/ 
	int LastTick = SDL_GetTicks();
	long DeltaTicks;
	/*The main loop*/
	while (running == 1)
	{
		DeltaTicks = SDL_GetTicks() - LastTick;
		SDL_Delay(10);
		LastTick = SDL_GetTicks();
		while (SDL_PollEvent (&event))
		{
			klicked = 0;
			switch (event.type)
			{
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_q)
					{
						running = 0;
					}
				break;

				case SDL_QUIT:
					running = 0;
				break;
				case SDL_MOUSEBUTTONDOWN:
					klicked = 1;
				break;

				default:
				break;
			}//end switch
		}//end event polling
		switch (scene)
		{
			case 1://The selection screen
				DrawBackground(screen);
				DrawSelection(screen);
				if (klicked == 1){
					if (ChoosePlayerImage(event.motion.x,event.motion.y) == 1){
						scene = 2;
					}
				}
				SDL_Flip(screen);
			break;
			case 2://The fading in scene
				DrawBackground(screen);
				DrawPlayer(screen);
				if (GetPlayerX() <144){SetPlayerX ( GetPlayerX()+1);}
				if (GetPlayerX() >144){SetPlayerX ( GetPlayerX()-1);}
				if (GetPlayerY() <139){SetPlayerY ( GetPlayerY()+1);}
				if (GetPlayerY() >139){SetPlayerY ( GetPlayerY()-1);}
				if (GetPlayerY() == 139 && GetPlayerX() == 144){
					scene = 3;
					SDL_WarpMouse(144,139);
				}
				SDL_Flip(screen);
			break;
			case 3://The game itself
				MoveClouds(DeltaTicks);
				MoveBirds(DeltaTicks);
				DrawBackground(screen);
				DrawClouds(screen);
				DrawBirds(screen);
				DrawPlayer(screen);
				SDL_Flip(screen);
			break;
		}//end switch (scene)
		
		
	}
	/*Ending of main loop*/
	/*Freeing all data*/


	FreePlayerImages();
	FreeObstacleImages();
	FreeLifeImages();
	FreeCloudImages();
	FreeBirdImages();
	printf("Bye-bye!\n");
	exit(0);
}




