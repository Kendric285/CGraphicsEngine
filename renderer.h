#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

typedef struct {
  SDL_Window* window;
  SDL_Renderer* renderer;
} InternalRenderer;

// typedef struct {
//   Uint8 r;
//   Uint8 g;
//   Uint8 b;
//   Uint8 a;
// } SDL_Color;

/** 
 * Creates the empty internal renderer
 * @param width Width of the window
 * @param height Height of the window
 * @param title Title of the window
 * 
 * @returns Pointer to empty internal renderer
*/
InternalRenderer* create_internal_renderer(int width, int height, char* title);

/**
 * Frees the Internal Renderer and quits the window
 * @param i Interal Renderer
 */
void destroy_internal_renderer(InternalRenderer* i);

/**
 * Clears the entire window to the specified RGBA color
 * @param i Internal Renderer
 * @param r Red
 * @param g Green
 * @param b Blue
 * @param a Alpha
*/
void clear_internal_renderer(InternalRenderer* i, SDL_Color color);

/**
 * Presents the current contents of the renderer to the window
 * Presents the off-screen buffer to the display the frame
 * @param i Internal Renderer
*/
void present_internal_renderer(InternalRenderer* i);

/*adds rectangle to off-screen buffer*/
void draw_rect_internal(InternalRenderer* i, int x, int y, int w, int h, SDL_Color color);

/*add line to off-screen buffer*/
void draw_line_internal(InternalRenderer* i, int x1, int y1, int x2, int y2, SDL_Color color);

/*adds circle to off-screen buffer*/
void draw_circle_internal(InternalRenderer* i, int x, int y, int r, SDL_Color color);

#endif