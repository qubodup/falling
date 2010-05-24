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

int GlobalTicker;//Made for the order of the birds

enum BirdType{
LEFT = 0,
RIGHT
};

struct Bird{
enum BirdType Type;
int LocalTicker; //For animation
int XPosition;
int YPosition;
};

struct Bird BirdArray[4] = {
{0,0,420,42},
{1,0,-200,150},
{0,0,420,300},
{1,0,-145,450}
};

SDL_Surface* BirdR1Image = NULL;
SDL_Surface* BirdR2Image = NULL;
SDL_Surface* BirdR3Image = NULL;
SDL_Surface* BirdL1Image = NULL;
SDL_Surface* BirdL2Image = NULL;
SDL_Surface* BirdL3Image = NULL;
SDL_Rect Dest;//the position the birds are rendered


void LoadBirdImages(){
	BirdR1Image = LoadImage ("cutebird_right_1.png");
	BirdR2Image = LoadImage ("cutebird_right_2.png");
	BirdR3Image = LoadImage ("cutebird_right_3.png");
	BirdL1Image = LoadImage ("cutebird_left_1.png");
	BirdL2Image = LoadImage ("cutebird_left_2.png");
	BirdL3Image = LoadImage ("cutebird_left_3.png");

}

void FreeBirdImages(){
	FreeImage (BirdR1Image);
	FreeImage (BirdR2Image);
	FreeImage (BirdR3Image);
	FreeImage (BirdL1Image);
	FreeImage (BirdL2Image);
	FreeImage (BirdL3Image);

}

void MoveBirds(int time){
	GlobalTicker++;//Hehehe, less work than a for loop ;)
	BirdArray[0].XPosition = BirdArray[0].XPosition -(1*time);
	BirdArray[1].XPosition = BirdArray[1].XPosition +(1*time);
	BirdArray[2].XPosition = BirdArray[2].XPosition -(1*time);
	BirdArray[3].XPosition = BirdArray[3].XPosition +(1*time);
	if (GlobalTicker == 4000){GlobalTicker = 0;}
	if (GlobalTicker == 800){BirdArray[0].XPosition = 320;
	} else if (GlobalTicker == 1600){BirdArray[1].XPosition = -82;
	} else if (GlobalTicker == 2400){BirdArray[2].XPosition = 320;
	} else if (GlobalTicker == 3200){BirdArray[3].XPosition = -82;}
	int i;
	for (i = 0; i < 4;i++){
		if (BirdArray[i].LocalTicker == 20){BirdArray[i].LocalTicker =0;}
		BirdArray[i].LocalTicker++;
	}
}

void DrawBirds(SDL_Surface *target){
	int i;
	for (i = 0; i < 4;i++){
		Dest.x = BirdArray[i].XPosition;
		Dest.y = BirdArray[i].YPosition;
		Dest.w = Dest.x + 82;
		Dest.h = Dest.y + 49;
		if (BirdArray[i].Type == 0){//Left-type
			if (BirdArray[i].LocalTicker < 5){
				SDL_BlitSurface(BirdL1Image, NULL,target, &Dest);
			} else if (BirdArray[i].LocalTicker >= 5 && BirdArray[i].LocalTicker < 10 ) {
				SDL_BlitSurface(BirdL2Image, NULL,target, &Dest);
			} else if (BirdArray[i].LocalTicker >= 10 && BirdArray[i].LocalTicker < 15) {
				SDL_BlitSurface(BirdL3Image, NULL,target, &Dest);
			} else if (BirdArray[i].LocalTicker >= 15) {
				SDL_BlitSurface(BirdL2Image, NULL,target, &Dest);
			}
		} else if (BirdArray[i].Type == 1){//Right-type
			if (BirdArray[i].LocalTicker < 5){
				SDL_BlitSurface(BirdR1Image, NULL,target, &Dest);
			} else if (BirdArray[i].LocalTicker >= 5 && BirdArray[i].LocalTicker < 10 ) {
				SDL_BlitSurface(BirdR2Image, NULL,target, &Dest);
			} else if (BirdArray[i].LocalTicker >= 10 && BirdArray[i].LocalTicker < 15) {
				SDL_BlitSurface(BirdR3Image, NULL,target, &Dest);
			} else if (BirdArray[i].LocalTicker >= 15) {
				SDL_BlitSurface(BirdR2Image, NULL,target, &Dest);
			}
		}
	}
}
