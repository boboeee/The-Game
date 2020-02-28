#include "engine.hpp"

LTexture::LTexture() : mTexture{NULL}, mWidth{0}, mHeight{0} {

}

LTexture::LTexture(std::string path) {
	mTexture = NULL;
    if (!loadFromFile(path))
        free();
}

LTexture::~LTexture() {
	free();
}

bool LTexture::loadFromFile(std::string path) {
    if (mTexture)
        RET_ERROR_MSG("Texture should not hold anything to call this!\n");

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
        RET_ERROR_MSG("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), SDL_GetError());

	mTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	if (mTexture == NULL)
        RET_ERROR_MSG("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());

	mWidth = loadedSurface->w;
	mHeight = loadedSurface->h;
	SDL_FreeSurface(loadedSurface);
	
	return (mTexture != NULL);
}

void LTexture::free() {
    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

void LTexture::render(int x, int y, SDL_Rect& clip) const {
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    renderQuad.w = clip.w;
    renderQuad.h = clip.h;
	
	SDL_RenderCopy(gRenderer, mTexture, &clip, &renderQuad);
}

void LTexture::render(int x, int y) const {
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
}

int LTexture::getWidth() {
	return mWidth;
}

int LTexture::getHeight() {
	return mHeight;
}

const SDL_Texture* LTexture::getTexture() const {
	return mTexture;
}