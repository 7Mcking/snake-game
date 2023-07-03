//
//  Snake.hpp
//  Snake_game
//
//  Created by Naren Sadhwani on 12.02.23.
//

#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>
#include "Drawable.hpp"
#include <ncurses.h>
#include <queue>

enum Direction{
    up = -1,
    down = 1,
    left = -2,
    right = 2
};

class SnakePiece :public Drawable{
public:
    SnakePiece(){
        this ->x = x;
        this ->y = y;
        this ->icon = '=';
    }
    
    SnakePiece(int y, int x){
        this ->x = x;
        this ->y = y;
        this ->icon = '=';
    }
};

class Snake{
    std::queue<SnakePiece> prev_pieces;
    Direction cur_direction;
public:
    Snake(){
        cur_direction = down;
    }
    
    void addPiece(SnakePiece piece){
        prev_pieces.push(piece);
    }
    
    void removePiece(){
        prev_pieces.pop();
    }
    
    SnakePiece tail(){
        return prev_pieces.front();
    }
    
    SnakePiece head(){
        return prev_pieces.back();
    }
    
    Direction getDirection(){
        return cur_direction;
    }
    
    void setDirection(Direction d){
        if (cur_direction + d != 0){
            cur_direction = d;
        }
    }
    
    SnakePiece nextHead(){
        int row = head().getY();
        int col = head().getX();
        
        switch (cur_direction) {
            case down:
                row++;
                break;
            case up:
                row--;
                break;
            case left:
                col--;
                break;
            case right:
                col++;
                break;
            }
        return SnakePiece(row, col);
    }
};

#endif /* Snake_hpp */
