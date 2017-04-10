//
//  main.cpp
//  Particle_Fire_Explosion
//
//  Created by Hamel Desai on 4/8/17.
//  Copyright © 2017 HND. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main() {
    
    // Over here we are defining our window height and width
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    
    cout << "Hello World" << endl;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed." << endl;
        return 1;
    }
    
    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN); //This initializes an empty window
    
    if(window == NULL) {
        SDL_Quit();
        return 2;
    }
    
    //Something we use to draw on the window and texture is like a bitmap so basically creating a renderer doing stuff with the texture and then passing the texture to the renderer so we display in the window
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    if(renderer == NULL) {
        cout << "Could not create renderer" << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }
    
    if(texture == NULL) {
        cout << "Could not create Texture" << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }
    
    //Area of memory to hold the info of the pixels on the screen and update the texture with this info
    //Type declared by SDL == int(usually 32 bits, but for some systems int might be not be 32 bits)
    //Allocate enough of these to display on the screen
    //For every pixel is 4 bites(RGBA) (4 times 8 == 32)
    //buffer is place holder for some amount of memory
    Uint32 *buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    
    //Write some pixel info in the buffer so we something in our window
    //Another way to represent 255 = 0xFF (Hexidecimal), FF: Is the maximum value we can store in a single bite in Hexidecimal
    memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    
    //Setting color to an individual pixel
    //Each pixel occupies 1 byte
    //0xFFFFFFFF: Setting all 4 bites to max.
    buffer[30000] = 0xFFFFFFFF;
    
    for(int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++){
        buffer[i] = 0xFFFFFFFF;
    }
    
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    
    //Game Loop: Loop that will run as long as the game is running, update the state of particles, draw our particles, check for events(messages, for example clicks a button on a window and will call a DS and check to see what has happened)
    //Will execute 30 times a second
    bool quit = false;
    
    SDL_Event event;
    
    while(quit == false) {
        
        //Fetches the latest event
        //Need to supply the address so it can fill in the event information into the 'event' variable
        //This loop is going to keep iterating as long event returns true and as long as there is an event waiting to be proccessed
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                //SDL_QUIT is called when someone hits the X on the window
                quit = true;
            }
        }
    }
    
    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window); //Before we quit a program you have to call SDL_DestroyWindow(window)
    SDL_Quit();
    
    return 0;
}
