//
//  Empty.hpp
//  Snake_game
//
//  Created by Naren Sadhwani on 12.02.23.
//

#ifndef Empty_hpp
#define Empty_hpp
#include <ncurses.h>
#include <stdio.h>
#include "Drawable.hpp"

class Empty: public Drawable{
public:
    Empty(int y, int x){
        this -> y = y;
        this -> x = x;
        this -> icon = ' ';
    }
};
#endif /* Empty_hpp */
