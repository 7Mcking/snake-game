//
//  Drawable.hpp
//  Snake_game
//
//  Created by Naren Sadhwani on 10.02.23.
//

#ifndef Drawable_hpp
#define Drawable_hpp
#pragma once
#include <curses.h>
#include <stdio.h>

class Drawable{
    
public:
    Drawable(){
        y=x=0;
        icon= ' ';
    }
    
    Drawable(int y, int x, chtype ch){
        this ->y = y;
        this ->x = x;
        this ->icon = ch;
    }
    
    int getY() {
        return y;
    }
    
    int getX() {
        return x;
    }
    
    int getIcon() {
        return icon;
    }
    
protected:
    int y, x;
    chtype icon;
};


#endif /* Drawable_hpp */
