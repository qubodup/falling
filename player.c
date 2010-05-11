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

/*This file contains the player stuff*/

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include "filehandler.h"

SDL_Surface* Egg1Image;
SDL_Surface* Egg2Image;
SDL_Surface* Egg3Image;
SDL_Surface* Egg4Image;

void LoadPlayerImages(){
	Egg1Image = LoadImage ("egg.png");
	Egg2Image = LoadImage ("egg2.png");
	Egg3Image = LoadImage ("egg3.png");
	Egg4Image = LoadImage ("egg4.png");
}

void FreePlayerImages(){
	FreeImage(Egg1Image);
	FreeImage(Egg2Image);
	FreeImage(Egg3Image);
	FreeImage(Egg4Image);
}
