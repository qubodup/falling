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
//Global variables to improve performance
SDL_Surface* SelectedEggImage;
SDL_Surface* Egg1Image = NULL;
SDL_Surface* Egg2Image = NULL;
SDL_Surface* Egg3Image = NULL;
SDL_Surface* Egg4Image = NULL;

SDL_Rect EGame;//The player position
/*Setter and getter*/
void SetPlayerX (int x){
EGame.x = x;
}

void SetPlayerY (int y){
EGame.y = y;
}

int GetPlayerX(){
return EGame.x; 
}

int GetPlayerY(){
return EGame.y;
}

SDL_Rect E1,E2,E3,E4;//The selection positions



void LoadPlayerImages(){
	Egg1Image = LoadImage ("egg.png");
	Egg2Image = LoadImage ("egg2.png");
	Egg3Image = LoadImage ("egg3.png");
	Egg4Image = LoadImage ("egg4.png");
	EGame.h = 42; EGame.w = 32;//Also preparing the positions
	E1.x = 110; E1.y = 110; E1.h = 42; E1.w = 32;
	E2.x = 178; E2.y = 110; E2.h = 42; E2.w = 32;
	E3.x = 110; E3.y = 168; E3.h = 42; E3.w = 32;
	E4.x = 178; E4.y = 168; E4.h = 42; E4.w = 32;
}

void FreePlayerImages(){
	FreeImage(Egg1Image);
	FreeImage(Egg2Image);
	FreeImage(Egg3Image);
	FreeImage(Egg4Image);
}

int ChoosePlayerImage (int x, int y){
	if (x > 110 && x < 142 && y > 110 && y < 152){
		EGame.x = E1.x;
		EGame.y = E1.y;
		SelectedEggImage = Egg1Image;
		return 1;
	} else if (x > 178 && x < 210 && y > 110 && y < 152){
		EGame.x = E2.x;
		EGame.y = E2.y;
		SelectedEggImage = Egg2Image;
		return 1;
	} else if(x > 110 && x < 142 && y > 168 && y < 200){
		EGame.x = E3.x;
		EGame.y = E3.y;
		SelectedEggImage = Egg3Image;
		return 1;
	} else if(x > 178 && x < 210 && y > 168 && y < 200){
		EGame.x = E4.x;
		EGame.y = E4.y;
		SelectedEggImage = Egg4Image;
		return 1;
	} else {return 0;} 
}

void DrawSelection (SDL_Surface *target){//Draws the four eggs
	SDL_BlitSurface(Egg1Image,NULL,target,&E1);
	SDL_BlitSurface(Egg2Image,NULL,target,&E2);
	SDL_BlitSurface(Egg3Image,NULL,target,&E3);
	SDL_BlitSurface(Egg4Image,NULL,target,&E4);

}
void DrawPlayer (SDL_Surface *target){
	SDL_BlitSurface(SelectedEggImage,NULL,target,&EGame);
	
}
