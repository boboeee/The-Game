#include "engine.hpp"

LModel::LModel() : mPosX{0}, mPosY{0}, mWidth{0}, mHeight{0}, mVelY{0}, mVelX{0} {

}

LModel::LModel(int posX, int posY, int width, int height, std::string path) 
: mPosX{posX}, mPosY{posY}, mWidth{width}, mHeight{height}, mVelX{0}, mVelY{0}, texture{path} {

}

LModel::LModel(int posX, int posY, int width, int height, int _vel, std::string path) 
: mPosX{posX}, mPosY{posY}, mWidth{width}, mHeight{height}, mVelX{0}, mVelY{0}, vel{_vel}, texture{path} {

}

void LModel::operator=(const LModel &m) {
    mPosX = m.mPosX;
    mPosY = m.mPosY;
    mWidth = m.mWidth;
    mHeight = m.mHeight;
    mVelX = m.mVelX;
    mVelY = m.mVelY;
    texture = m.texture;
}

LModel::~LModel() {
    mWidth = 0;
    mHeight = 0;
}


void LModel::handleEvent(SDL_Event& e) {

    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= vel; break;
            case SDLK_DOWN: mVelY += vel; break;
            case SDLK_LEFT: mVelX -= vel; break;
            case SDLK_RIGHT: mVelX += vel; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += vel; break;
            case SDLK_DOWN: mVelY -= vel; break;
            case SDLK_LEFT: mVelX += vel; break;
            case SDLK_RIGHT: mVelX -= vel; break;
        }
    }
}

void LModel::move() {
    //Move the dot left or right
    mPosX += mVelX;
    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + mWidth > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }
    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + mHeight > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

void LModel::render() const {
    SDL_Rect dstrect = { 0, 0, mWidth, mHeight };
    texture.render(mPosX, mPosY, dstrect);
}

int LModel::getWidth() const {
	return mWidth;
}

int LModel::getHeight() const {
	return mHeight;
}

int LModel::getPositionX() const {
	return mPosX;
}

int LModel::getPositionY() const {
	return mPosY;
}

const LTexture& LModel::getTexture() const {
	return texture;
}