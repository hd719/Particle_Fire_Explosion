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
    
    
    
    SDL_DestroyWindow(window); //Before we quit a program you have to call SDL_DestroyWindow(window)
    SDL_Quit();
    
    return 0;
}
