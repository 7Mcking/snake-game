//
//  SnakeGame.hpp
//  Snake_game
//
//  Created by Naren Sadhwani on 10.02.23.
//

#ifndef SnakeGame_hpp
#define SnakeGame_hpp

#pragma once
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <ncurses.h>
#include "board.hpp"
#include "Apple.hpp"
#include "Empty.hpp"
#include "Snake.hpp"
#include "Scoreboard.hpp"
class SnakeGame{
    
    
private:
    Board board;
    bool game_over;
    Apple *apple = NULL;
    Snake snake;
    Scoreboard scoreboard;
    int score;
    
    //Create Apple
    void createApple(){
        int y , x;
        board.getEmptyCoordinates(y, x);
        apple = new Apple(y,x);
        board.add(*apple);
        }
    
    //Destroy Apple
    void destroyApple(){
        delete apple;
        apple = NULL;
        score += 1;
        scoreboard.updateScore(score);
        
    }
    
    //Handle next peice
    void handleNextPiece (SnakePiece next){
        
        if(apple != NULL){
            switch (board.getCharAT(next.getY(), next.getX())) {
                case 'A':
                    destroyApple();
                    break;
                case ' ':
                {
                    int emptyRow = snake.tail().getY();
                    int emptyCol = snake.tail().getX();
                    board.add(Empty(emptyRow, emptyCol));
                    snake.removePiece();
                    break;
                }
                default:
                    game_over=true;
                    break;
            }
        }
        board.add(next);
        snake.addPiece(next);
    }
    
    
public:
    SnakeGame(int height, int width){
        board = Board(height, width);
        int sb_row = board.getStartRow() + height;
        int sb_col= board.getStartCol();
        scoreboard = Scoreboard(width, sb_row, sb_col);
        initialize();
        
        
    }
    
    ~SnakeGame(){
        delete apple;
    }
    //Process input from user
    void processInput(){
        chtype input = board.getInput();
        
        switch (input) {
            case KEY_UP:
            case 'w':
                snake.setDirection(up);
                break;
                
            case KEY_DOWN:
            case 's':
                
                snake.setDirection(down);
                break;
                
            case KEY_RIGHT:
            case 'd':
                
                snake.setDirection(right);
                break;
                
            case KEY_LEFT:
            case 'a':
                
                snake.setDirection(left);
                break;
                
            case 'p':
                board.setTimeout(-1);
                while(board.getInput() != 'p');
                board.setTimeout(1000);
                break;
                
            default:
                break;
        }
        }
    
    void initialize(){
        game_over = false;
        srand(time(NULL));
        //Scoreboard Initialization
        score=0;
        scoreboard.initialize(score);
        
        //Initialize Snake
        handleNextPiece(SnakePiece(1,1));
        handleNextPiece(snake.nextHead());
        handleNextPiece(snake.nextHead());
        snake.setDirection(right);
        handleNextPiece(snake.nextHead());
        
        //Create Apple
        if (apple == NULL){
            createApple();
        }
        
        
    }
    
    //Update the state of the game.
    void updateState(){
       
        handleNextPiece(snake.nextHead());
        
        if (apple == NULL){
            createApple();
        }
    }
    
    //redraw the screen
    void redraw(){
        board.refresh();
        scoreboard.refresh();
    }
    
    //return if and when the game is over
    bool isOver(){
        return game_over;
    }
    
    int getScore(){
        return score;
    }

    
};


#endif /* SnakeGame_hpp */
