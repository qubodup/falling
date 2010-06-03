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

/*This file contains the obstacles stuff and the levels*/

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include "filehandler.h"
#include "player.h"

SDL_Surface* BlockImage = NULL;
SDL_Rect BlockRect;

int ActualLevelNumber;
int LevelYPosition;

enum ObstacleType{
BLOCK = 0
};

struct Obstacle{
enum ObstacleType Type;
int XPosition;
int YPosition;
};

struct Obstacle LoadedLevel[32];

struct Obstacle LevelOneObstacles [32] = {
	{0,64,32},
	{0,230,32},
	{0,128,64},
	{0,164,128},
	{0,160,232},
	{0,14,822},
	{0,64,932},
	{0,260,732},
	{0,128,432},
	{0,32,482},
	{0,240,532},
	{0,340,632},
	{0,126,355},
	{0,260,777},
	{0,133,832},
	{0,164,922},
	{0,24,266},
	{0,228,999}
};

void SetActualLevelNumber(int input){
	ActualLevelNumber = input;
}

int CollisionCheck(){//too bad it works only for the blocks,
	int Collide = 0;//so if you want to fork the game, you better rewrite it.
	int i;
	for (i=0; i<32; i++)
	{
		if (((GetPlayerX() > LoadedLevel[i].XPosition && GetPlayerX() < LoadedLevel[i].XPosition+32)||
		(GetPlayerX()+32 > LoadedLevel[i].XPosition && GetPlayerX()+32 < LoadedLevel[i].XPosition+32))
		&& GetPlayerY()+38 > LoadedLevel[i].YPosition+LevelYPosition && GetPlayerY() < LoadedLevel[i].YPosition+LevelYPosition+32 )
		{
			Collide = 1;
		}
	}
	if (Collide == 1)
	{
		return 1;	
	}else{
		return 0;
	}
	

}


//Getter and Setter for LevelYPosition
void SetLevelYPosition(int input){
	LevelYPosition = input;
}
int GetLevelYPosition(){
	return LevelYPosition;
}
//

void LoadLevel (){
	LevelYPosition = 1000;
	int i;
	for (i = 0; i < 32;i++){
		if (ActualLevelNumber==1 ){LoadedLevel[i] = LevelOneObstacles[i];}

	}
}

void ScrollLevel(){
LevelYPosition-=6;
}


void DrawObstacles(SDL_Surface *target){
	int i = 0;
	for (i = 0;i<32;i++)
	{
		BlockRect.x = LoadedLevel[i].XPosition;
		BlockRect.y = LoadedLevel[i].YPosition+LevelYPosition;
		if (LoadedLevel[i].YPosition+LevelYPosition>-256 && LoadedLevel[i].YPosition+LevelYPosition<480){
			if(LoadedLevel[i].Type == 0 )
			{
				SDL_BlitSurface(BlockImage,NULL,target,&BlockRect);
			}

			
		}
	}//for

}

void LoadObstacleImages(){
	BlockImage = LoadImage ("block.png");
	BlockRect.h =32;
	BlockRect.w =32; 
}

void FreeObstacleImages(){
	FreeImage(BlockImage);
}
