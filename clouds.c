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

/*This file contains the cloud stuff*/

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include "filehandler.h"


enum CloudType{
NORMAL = 0,
BIG
};

struct Cloud{
enum CloudType Type; 
int XPosition;
int YPosition;
};

/*The 16 clouds in the background*/
struct Cloud CloudArray[16] = {
{0,20,42},
{1,100,200},
{1,320,240},
{0,211,420},
{0,188,35},
{1,3,66},
{0,188,166},
{1,13,350},
{1,222,311},
{0,99,455},
{0,122,150},
{1,220,240},
{0,211,320},
{0,122,315},
{1,35,43},
{1,45,280}
};

SDL_Surface* CloudBigImage;
SDL_Surface* CloudImage;
SDL_Surface* CloudBigLineImage;
SDL_Surface* CloudLineImage;
int CloudTicker;



void LoadCloudImages(){
	CloudBigImage = LoadImage ("cloud_big.png");
	CloudImage = LoadImage ("cloud.png");
	CloudBigLineImage = LoadImage ("cloud_big_line.png");
	CloudLineImage = LoadImage ("cloud_line.png");
}

void DrawClouds(SDL_Surface* target){
	SDL_Rect Dest;
	int i = 0;
	for (i = 0; i < 16;i++)//Shapes...
	{
		
		Dest.x = CloudArray[i].XPosition;
		Dest.y = CloudArray[i].YPosition;
		if (CloudArray[i].Type == 1)
		{
			Dest.w = CloudArray[i].XPosition + 63;
			Dest.h = CloudArray[i].YPosition + 32;
			SDL_BlitSurface(CloudBigLineImage, NULL,target, &Dest);
		} else if (CloudArray[i].Type == 0) {
			Dest.w = CloudArray[i].XPosition + 45;
			Dest.h = CloudArray[i].YPosition + 23;
			SDL_BlitSurface(CloudLineImage, NULL,target, &Dest);
		}
	}
	for (i = 0; i < 16;i++)//...and Bodies.
	{
		Dest.x = CloudArray[i].XPosition+2;
		Dest.y = CloudArray[i].YPosition+2;
		if (CloudArray[i].Type == 1)
		{
			Dest.w = CloudArray[i].XPosition + 59;
			Dest.h = CloudArray[i].YPosition + 28;
			SDL_BlitSurface(CloudBigImage, NULL,target, &Dest);
		} else if (CloudArray[i].Type == 0) {
			Dest.w = CloudArray[i].XPosition + 41;
			Dest.h = CloudArray[i].YPosition + 19;
			SDL_BlitSurface(CloudImage, NULL,target, &Dest);
		}
	}

}

void MoveClouds(){
	int i = 0;
	if (CloudTicker == 0) {
		CloudTicker = 1;
		for (i = 0;i<16;i++){
			if (i < 8){
				if (CloudArray[i].XPosition > 320){CloudArray[i].XPosition = -63;}
				CloudArray[i].XPosition++;
			}else if (i >= 8){
				if (CloudArray[i].XPosition < -63){CloudArray[i].XPosition = 320;}
				CloudArray[i].XPosition--;
			}
			if (CloudArray[i].YPosition < -32){CloudArray[i].YPosition =480;}
			CloudArray[i].YPosition--;
		}
	}else{
		CloudTicker = 0;
	}
}

void FreeCloudImages(){
	FreeImage(CloudBigLineImage);
	FreeImage(CloudLineImage);
	FreeImage(CloudBigImage);
	FreeImage(CloudImage);
}


