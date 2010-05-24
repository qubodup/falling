#!/bin/bash
cd ~/falling
gcc $(sdl-config --cflags --libs) -lSDL_image -o falling main.c clouds.c filehandler.c birds.c player.c lifes.c obstacles.c -O2
