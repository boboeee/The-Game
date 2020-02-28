#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#define RET_ERROR_MSG(...)              \
    {                                   \
        printf(__VA_ARGS__);            \
        return false;                   \
    }
#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 700

//Texture wrapper class
//TODO: Right now we can't do an assignment, because it calls destructor on the pointer, and frees it first, making this SDL_texture to NULL
class LTexture
{
    public:
        //Initializes variables
        LTexture();
        LTexture(std::string path);
        void operator=(const LTexture &T) {
            mWidth = T.mWidth;
            mHeight = T.mHeight;
            mTexture = T.mTexture;
        }
        //Deallocates memory
        ~LTexture();

        //Loads image at specified path
        bool loadFromFile( std::string path );

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render(int x, int y) const;

        //Renders texture at given point and clip
        void render(int x, int y , SDL_Rect &clip) const;

        //Gets image dimensions
        int getWidth();
        int getHeight();

		const SDL_Texture* getTexture() const;

    private:
        //The actual hardware texture
        SDL_Texture* mTexture;

        //Image dimensions
        int mWidth;
        int mHeight;
};

//Model wrapper class
class LModel
{
    public:
        //Initializes variables
        LModel();
        LModel(int posX, int posY, int width, int height, std::string path);
        LModel(int posX, int posY, int width, int height, int vel, std::string path);
        void operator=(const LModel &m);

        //Deallocates memory
        ~LModel();

        //Takes key presses and adjusts the dot's velocity
        void handleEvent( SDL_Event& e );

        //Moves the dot
        virtual void move();

        //Renders texture at given point
        virtual void render() const;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
        //Gets image dimensions
        int getWidth() const;
        int getHeight() const;
        
        //Get position
        int getPositionX() const;
        int getPositionY() const;

		const LTexture& getTexture() const;

    private:

        //The actual hardware texture
        LTexture texture;

        //The X and Y offsets of the object
        int mPosX, mPosY;

        //The velocity of the object
        int mVelX, mVelY;

        //Dimensions of the object
        int mWidth, mHeight;

        //Maximum axis velocity
        int vel = 10;
};  

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
extern SDL_Window* gWindow;

//The window renderer
extern SDL_Renderer* gRenderer;

extern int gAnimationRate;
extern uint32_t gStartTime;
