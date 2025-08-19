#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "renderer.h"

SDL_Window *Window;
SDL_Renderer *Renderer;

int main(int argc, char* argv[]){

	(void)argc;
	(void)argv;


	SDL_Init(SDL_INIT_VIDEO);

	Window = SDL_CreateWindow("", 0, 0, 0, 0, SDL_WINDOW_HIDDEN);
	SDL_SetWindowSize(Window,200,200);
	SDL_SetWindowTitle(Window, "Window");
	SDL_ShowWindow(Window);
	SDL_SetWindowPosition(Window, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED);

	
	Renderer = SDL_CreateRenderer(Window,-1,1);
	InternalRenderer* i = malloc(sizeof(InternalRenderer));
	i->renderer = Renderer;
	i->window = Window;


	SDL_Event event;
	bool running = true;

	while(running){
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT) running = false;
		}
		SDL_SetRenderDrawColor(Renderer,255,255,255,1);
		SDL_RenderClear(Renderer); //clears everything from the buffer, and sets the background to the last draw color

		SDL_SetRenderDrawColor(Renderer,0,0,0,1);
		SDL_RenderDrawLine(Renderer,0,0,199,199);

		draw_circle_internal(i,100,100,10,(SDL_Color){0,0,0,1});

		SDL_RenderPresent(Renderer);

		SDL_Delay(16);
	}

	SDL_DestroyWindow(Window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
