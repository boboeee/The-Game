#include <SDL2/SDL.h>

#include "engine/engine.hpp"

class Character: public LModel {
    public:
        static const int CHARACTER_WIDTH = 16;
        static const int CHARACTER_HEIGHT = 30;
        static const int CHARACTER_SPEED = 2;
        static const int CHAR_ANIMATION_FRAMES = 4;
        //Initializes variables
        Character(int posX, int posY);

        ~Character();

        void render();
};