#ifndef GRAPHICS_H 
#define GRAPHICS_H

#include "renderer.h"
#include <SDL2/SDL.h>
#include "object.h"


void init_graphics(int width, int height, char* title);
void set_background_color(SDL_Color c);
void draw_rectangle(int x, int y, int w, int h, SDL_Color c);
void draw_line(int x1, int y1, int x2, int y2, SDL_Color c);
void draw_circle(int x, int y, int r,SDL_Color c);
void present_screen();
void shutdown_graphics();

#endif 
