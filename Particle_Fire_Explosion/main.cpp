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
    
    cout << "Hello World" << endl;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL init failed." << endl;
        return 1;
    }
    
    cout << "SDL Init succeeded." << endl;
    
    SDL_Quit();
    
    return 0;
}
