#include <SDL2/SDL.h>
#include <stdio.h>

int main(){

	SDL_Surface *test = SDL_LoadBMP("testimg.bmp");

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);

	SDL_Surface *window_surface = SDL_GetWindowSurface(window);

	SDL_Event event;

	int running = 1;
	while(running){
		SDL_PumpEvents();
		while(SDL_PollEvent(&event) != 0){
			if(event.type == SDL_QUIT){
				running = 0;
			}
		}
		SDL_BlitSurface(test, NULL, window_surface, NULL);
		SDL_UpdateWindowSurface(window);
	}
	SDL_Quit();
	return 0;
}
