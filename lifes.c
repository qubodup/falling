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

/*This file contains the lifes stuff*/

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include "filehandler.h"

SDL_Surface* LifeImage = NULL;
SDL_Surface* BarImage = NULL;
SDL_Rect BarRect;
SDL_Rect LifeRect;
int LifeCount = 0;

void RecreateBar(){
	SDL_FillRect(BarImage,NULL,SDL_MapRGB(BarImage->format, 100, 152, 235));
	LifeRect.x = 0;
	int l = 0;
	for (l = 0; l < LifeCount; l++)
	{
		SDL_BlitSurface(LifeImage,NULL,BarImage,&LifeRect);
		LifeRect.x += 16;		
	}
}

void ResetLifeCount(){
LifeCount = 3;
RecreateBar();
}

void LoseLife(){
LifeCount--;
RecreateBar();
}

int GetLifeCount(){
return LifeCount;
}




void DrawLifeBar(SDL_Surface* target){
	SDL_BlitSurface(BarImage,NULL,target,&BarRect);
}

void LoadLifeImages(){
	LifeImage = LoadImage ("life.png");
	BarImage=SDL_CreateRGBSurface(SDL_SWSURFACE,320,16,32,0,0,0,0);
	BarRect.h = 16;
	BarRect.w = 320;
	BarRect.x = 0;
	BarRect.y = 0;
	LifeRect.h = 15;
	LifeRect.w = 15;
	LifeRect.y = 0;
}

void FreeLifeImages(){
	FreeImage(LifeImage);
	FreeImage(BarImage);
}
