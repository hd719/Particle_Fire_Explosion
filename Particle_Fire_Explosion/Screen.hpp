//
//  Screen.hpp
//  Particle_Fire_Explosion
//
//  Created by Hamel Desai on 4/10/17.
//  Copyright © 2017 HND. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include <stdio.h>
#include <SDL2/SDL.h>


namespace caveofprogramming {
    
    class Screen {
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
        
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_buffer;
        
    public:
        Screen();
        bool init();
        bool processEvents();
        void close();
    };
    
}


#endif /* Screen_hpp */
