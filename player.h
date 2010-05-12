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

/*The header of 'player.c'*/

#ifndef PLAYER_H
#define PLAYER_H
int ChoosePlayerImage(int x, int y);//Sets the pointer to the choosen player image
void DrawSelection(SDL_Surface *target);//Draws all 4 eggs
void DrawPlayer(SDL_Surface *target);
void LoadPlayerImages();
void FreePlayerImages();
int GetPlayerX();
int GetPlayerY();
void SetPlayerX(int x);
void SetPlayerY(int y);

#endif //PLAYER_H
