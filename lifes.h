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

/*The header of 'lifes.c'*/

#ifndef LIFES_H
#define LIFES_H

void ResetLifeCount();
void LoseLife();
int GetLifeCount();
void DrawLifeBar(SDL_Surface *target);
void LoadLifeImages();
void FreeLifeImages();

#endif //LIFES_H
