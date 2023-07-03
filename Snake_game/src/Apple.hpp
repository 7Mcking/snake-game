//
//  Apple.hpp
//  Snake_game
//
//  Created by Naren Sadhwani on 12.02.23.
//

#ifndef Apple_hpp
#define Apple_hpp

#pragma once
#include <ncurses.h>
#include "Drawable.hpp"


class Apple :public Drawable{
public:
    Apple(int y , int x){
        this -> y = y;
        this -> x = x;
        this -> icon = 'A';
    }
};
#endif /* Apple_hpp */
