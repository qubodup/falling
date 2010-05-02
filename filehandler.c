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

/*This file contains the loader and the "remote destructor" for files like images, sounds, etc.*/

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>


void FreeImage (SDL_Surface* surface){
	if ( surface ) { 
		SDL_FreeSurface( surface );
	}
}




SDL_Surface* LoadImage(char* file) {
	SDL_Surface* tmp,* tmp2;
	tmp = IMG_Load(file);
	if (!tmp) {
		fprintf(stderr, "Error: '%s' could not be opened: %s\n", file, IMG_GetError());
		exit(1);
		return NULL;
	}else{
		tmp2 = SDL_DisplayFormatAlpha(tmp);
		return tmp2;
	}

}

