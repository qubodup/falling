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

/*The header of 'obstacles.c'*/

#ifndef OBSTACLES_H
#define OBSTACLES_H

void ScrollLevel();
void LoadObstacleImages();
void FreeObstacleImages();
void DrawObstacles(SDL_Surface *target);
void LoadLevel();
void SetActualLevelNumber(int input);
int CollisionCheck();
void SetLevelYPosition(int input);
int GetLevelYPosition();

#endif //OBSTACLES_H
