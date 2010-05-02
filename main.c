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

/*This file contains about everything of this game*/


#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include "misc.h"
#include <stdlib.h>

/*Part 1: Loading and freeing stuff*/
void FreeImage (SDL_Surface* surface){
	if ( surface ) { 
		SDL_FreeSurface( surface );
	}
}

SDL_Surface* LoadImage(char* file) {
	SDL_Surface* tmp,* tmp2;
	tmp = IMG_Load(file);
	if (!tmp) {
		fprintf(stderr, "Error: '%s' could not be opened: %s\n", file, IMG_GetError());
		exit(1);
		return NULL;
	}else{
		tmp2 = SDL_DisplayFormatAlpha(tmp);
		return tmp2;
	}

}
/*Ending of part 1*/

/*--------------------*/

/*Part 2: Drawing procedures*/
void DrawBackground (SDL_Surface *target,SDL_Surface *small,SDL_Surface *medium,SDL_Surface *big)
{
	SDL_FillRect(target,NULL,SDL_MapRGB(target->format, 200, 222, 255));
	int i=0;
	for (i=0; i<12; i++){
		SDL_Rect dstrect;
		dstrect.x = CloudArray[i].XPosition;
		dstrect.y = CloudArray[i].YPosition;
		dstrect.h = dstrect.y + 32;
		dstrect.w = dstrect.y + 63;
		if (CloudArray[i].Type == 0)
		{
			SDL_BlitSurface(small,NULL,target, &dstrect);
		}else if (CloudArray[i].Type == 1) {
			SDL_BlitSurface(medium,NULL, target, &dstrect);
		}else if (CloudArray[i].Type == 2) {
			SDL_BlitSurface(big,NULL, target, &dstrect);
		}
	}
}
/*Ending of part 2*/


/*---------------*/


/*Part 3: logic*/

void MoveClouds(){
	int i = 0;
	for (i = 0; i<12;i++)
	{
		if (i < 6){
			if (CloudArray[i].XPosition > 320) {CloudArray[i].XPosition = -63;}
			CloudArray[i].XPosition++;
			if (CloudArray[i].Type == 0) {CloudArray[i].XPosition++;}
		}else{
			if (CloudArray[i].XPosition < -63) {CloudArray[i].XPosition = 320;}
			CloudArray[i].XPosition--;
			if (CloudArray[i].Type == 0) {CloudArray[i].XPosition--;}
		} 
		if (CloudArray[i].YPosition < -32) {CloudArray[i].YPosition = 480;}
		CloudArray[i].YPosition--;
	}


}




/*Ending of part 3*/


/*----------------*/


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
	/*Loading all Images follow...*/
	SDL_Surface* playerImage = LoadImage("player.png");
	SDL_Surface* blockImage = LoadImage("block.png");
	SDL_Surface* coinImage = LoadImage("coin.png");
	SDL_Surface* lifeImage = LoadImage("life.png");
	SDL_Surface* cloudBigImage = LoadImage("cloud_big.png");
	SDL_Surface* cloudMediumImage = LoadImage("cloud_medium.png");
	SDL_Surface* cloudSmallImage = LoadImage("cloud_small.png");
	printf("Images loaded!\n");
	/*Loading finished*/
	/*The main loop variables*/
	int running = TRUE;
	SDL_Event event; 
	/*The main loop*/
	while (running == TRUE)
	{
		while (SDL_PollEvent (&event))
		{
			switch (event.type)
			{
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_q)
					{
						running = FALSE;
					}
				break;
				case SDL_QUIT:
				printf ("quit\n");
				exit (0);
				break;
				default:
				break;
			}
		}
		MoveClouds();
		DrawBackground(screen,cloudSmallImage,cloudMediumImage,cloudBigImage);
		SDL_Flip(screen);
		SDL_Delay(10);
	}
	/*Ending of main loop*/
	/*Freeing all data*/
	FreeImage(playerImage);
	FreeImage(blockImage);
	FreeImage(coinImage);
	FreeImage(lifeImage);
	FreeImage(cloudBigImage);
	FreeImage(cloudMediumImage);
	FreeImage(cloudSmallImage);
	printf("Bye-bye!\n");
	exit(0);
}




