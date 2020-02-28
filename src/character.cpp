#include "engine/engine.hpp"
#include "character.hpp"

Character::Character(int posX, int posY) 
: LModel(posX, posY, CHARACTER_WIDTH, CHARACTER_HEIGHT, CHARACTER_SPEED, "sprites/mainChar/gfx/NPC_test.png") {

}

Character::~Character() {

}

void Character::render() {
    int frameToDraw = ((SDL_GetTicks() - gStartTime) * gAnimationRate / 1000) % CHAR_ANIMATION_FRAMES;
    SDL_Rect dstrect = { frameToDraw * CHARACTER_WIDTH , 0, getWidth(), getHeight() };
    getTexture().render(getPositionX(), getPositionY(), dstrect);
    printf("f %d\n", frameToDraw);
}