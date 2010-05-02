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




/*This file contains various constants, structure type definitions and global variables needed by the game, such as the basic stone/coin/whatever structures*/

#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

int const TRUE = 1; 
int const FALSE = 0;
/*The size is noticed here, in case of porting this game to bigger/smaller resolution devices*/
int const BLOCK_WIDTH = 32;
int const BLOCK_HEIGHT = 32;
int const COIN_WIDTH = 32;
int const COIN_HEIGHT = 32;
int const PLAYER_WIDTH = 26;
int const PLAYER_HEIGHT = 32;

enum CloudType{
SMALL = 0,
MEDIUM,
BIG
};

struct Cloud{
enum CloudType Type; 
int XPosition;
int YPosition;
};

/*The 12 clouds in the background*/
struct Cloud CloudArray[12] = {
{0,20,42},
{2,100,200},
{1,320,240},
{0,211,420},
{2,188,35},
{1,3,66},
{0,188,166},
{2,13,11},
{1,222,311},
{0,99,455},
{2,122,150},
{1,45,280}
};

enum GameObjectType{
BLOCK = 0,
COIN,
SPRING
};

struct GameObject{
enum GameObjectType Type; 
int XPosition; 
int RelYPosition; /*The vertical position related to the level*/
};






#endif //MISCELLANEOUS_H
