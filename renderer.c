#include "renderer.h"
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>



/** 
 * Converts polar coordinates centered at r to rectangular coordinates
 * 
*/
int* polar_to_rectangular(int x, int y, int r, double theta){
  int* res = malloc(sizeof(int) * 2);
  double x_disp;
  double y_disp;
  
  double rad = theta * (M_PI / 180.0);
  x_disp = r * cos(rad);
  y_disp = r * sin(rad);

  //x_disp = (theta > 90 && theta < 270) ? -x_disp : x_disp;
  //y_disp = (theta > 180 && theta < 360) ? -y_disp : y_disp;

  res[0] = x + (int)x_disp;
  res[1] = y + (int)y_disp;
  return res;
}

InternalRenderer* create_internal_renderer(int width, int height, char* title){
  InternalRenderer* res = malloc(sizeof(InternalRenderer));

  SDL_Window* window = SDL_CreateWindow("",0,0,0,0,SDL_WINDOW_HIDDEN);
  SDL_SetWindowSize(window,width,height);
  SDL_SetWindowTitle(window, title);

  SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,1);

  res->renderer = renderer;
  res->window = window;

  return res;
}

void destroy_internal_renderer(InternalRenderer* i){
  SDL_DestroyRenderer(i->renderer);
  SDL_DestroyWindow(i->window);
  SDL_Quit();
}

void clear_internal_renderer(InternalRenderer* i, SDL_Color color){
  SDL_SetRenderDrawColor(i->renderer,color.r,color.g,color.b,color.a);
  SDL_RenderClear(i->renderer);
}

void present_internal_renderer(InternalRenderer* i){
  SDL_RenderPresent(i->renderer);
}

void draw_rect_internal(InternalRenderer* i, int x, int y, int w, int h, SDL_Color color){
  SDL_SetRenderDrawColor(i->renderer,color.r,color.g,color.b,color.a);
  const SDL_Rect rect = {.x = x, .y = y, .w = w, .h = h};
  SDL_RenderDrawRect(i->renderer, &rect);
}

void draw_line_internal(InternalRenderer* i, int x1, int y1, int x2, int y2, SDL_Color color){
  SDL_SetRenderDrawColor(i->renderer,color.r,color.g,color.b,color.a);
  SDL_RenderDrawLine(i->renderer, x1, y1, x2, y2);
}

void draw_circle_internal(InternalRenderer* i, int x, int y, int r, SDL_Color color){
  SDL_SetRenderDrawColor(i->renderer,color.r,color.g,color.b,color.a);
  int increment = (int)(1/r * 180.0 / M_1_PI);
  for(double theta = 0; theta < 360; theta+=0.5){
    int* point = polar_to_rectangular(x,y,r,theta);
    SDL_RenderDrawPoint(i->renderer, point[0], point[1]);
    free(point);
  }
}
