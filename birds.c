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

/*This file contains all procedures of the birds*/

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include "filehandler.h"

int GlobalTicker;

enum BirdType{
NORMAL = 0,
BIG
};

struct Bird{
enum BirdType Type;
int LocalTicker; //For animation
int XPosition;
int YPosition;
};

struct Bird BirdArray[4] = {
{0,0,20,42},
{1,0,100,150},
{0,0,320,300},
{1,0,45,450}
};

SDL_Surface* BirdA1Image;
SDL_Surface* BirdA2Image;
SDL_Surface* BirdB1Image;
SDL_Surface* BirdB2Image;

void LoadBirdImages(){
	BirdA1Image = LoadImage ("bird_a_1.png");
	BirdA2Image = LoadImage ("bird_a_2.png");
	BirdB1Image = LoadImage ("bird_b_1.png");
	BirdB2Image = LoadImage ("bird_b_2.png");
}

void FreeBirdImages(){
	FreeImage (BirdA1Image);
	FreeImage (BirdA2Image);
	FreeImage (BirdB1Image);
	FreeImage (BirdB2Image);
}

void MoveBirds(){
	GlobalTicker++;
	BirdArray[0].XPosition ++;
	BirdArray[1].XPosition --;
	BirdArray[2].XPosition --;
	BirdArray[3].XPosition ++;
	if (GlobalTicker == 4000){GlobalTicker = 0;}
	if (GlobalTicker == 800){BirdArray[0].XPosition = -26;
	} else if (GlobalTicker == 1600){BirdArray[1].XPosition = 320;
	} else if (GlobalTicker == 2400){BirdArray[2].XPosition = 320;
	} else if (GlobalTicker == 3200){BirdArray[3].XPosition = -26;}
	int i;
	for (i = 0; i < 4;i++){
		if (BirdArray[i].LocalTicker == 20){BirdArray[i].LocalTicker =0;}
		BirdArray[i].LocalTicker++;
	}
}

void DrawBirds(SDL_Surface *target){
	SDL_Rect Dest;
	int i;
	for (i = 0; i < 4;i++){
		Dest.x = BirdArray[i].XPosition;
		Dest.y = BirdArray[i].YPosition;
		Dest.w = Dest.x + 26;
		Dest.h = Dest.y + 8;
		if (BirdArray[i].Type == 0){
			if (BirdArray[i].LocalTicker < 10){
				SDL_BlitSurface(BirdB1Image, NULL,target, &Dest);
			} else {
				SDL_BlitSurface(BirdB2Image, NULL,target, &Dest);
			}
		} else if (BirdArray[i].Type == 1){
			if (BirdArray[i].LocalTicker < 10){
				SDL_BlitSurface(BirdA1Image, NULL,target, &Dest);
			} else {
				SDL_BlitSurface(BirdA2Image, NULL,target, &Dest);
			}
		}
	}
}
