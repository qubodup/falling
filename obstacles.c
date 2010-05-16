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

/*This file contains the obstacles stuff*/

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include "filehandler.h"

SDL_Surface* BlockImage = NULL;

enum ObstacleType{
BLOCK = 0
};

struct Obstacle{
enum ObstacleType Type;
int XPosition;
int YPosition;
};

struct Obstacle Level1Obstacles [] = {
	{0,160,32},
	{0,240,32},
	{0,128,128}
};

void LoadObstacleImages(){
	BlockImage = LoadImage ("block.png");
}

void FreeObstacleImages(){
	FreeImage(BlockImage);
}
