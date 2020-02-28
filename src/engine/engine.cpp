#include "engine.hpp"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
int gAnimationRate = 10;
uint32_t gStartTime = 0;

/* init
 *  Initalise SDL2 stuff
 * 
 *  TODO: Add free() and exit/exception stack, in case it fails early to free stuff
 */
bool init() 
{
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (gWindow == NULL)
		RET_ERROR_MSG("Window could not be created! SDL Error: %s\n", SDL_GetError());

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == NULL)
		RET_ERROR_MSG("Renderer could not be created! SDL Error: %s\n", SDL_GetError());

    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    	RET_ERROR_MSG("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());

	gStartTime = SDL_GetTicks();
    return true; 
}

void close()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
	SDL_Quit();
}
