
#include <cstdio>

#include "engine/engine.hpp"
#include "character.hpp"

int main( int argc, char* args[] )
{
    bool quit = false;
    SDL_Event e;

    //Start up SDL and create window
    if(!init()) {
        printf( "Failed to initialize!\n" );
        return -1;
    }

    Character c{0, 0};

    //While application is running
    while(!quit) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }

            //Handle input for the dot
            c.handleEvent( e );
        }

        //Move the dot
        c.move();

        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );

        //Render objects
        c.render();

        //Update screen
        SDL_RenderPresent( gRenderer );
    }

    //Free resources and close SDL
    close();

    return 0;
}