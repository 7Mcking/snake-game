//
//  board.hpp
//  Snake_game
//
//  Created by Naren Sadhwani on 10.02.23.
//

#ifndef board_hpp
#define board_hpp
#define WORLD_WIDTH 50
#define WORLD_HEIGHT 20
#define SPEED 100
#include <ncurses.h>
#include <stdio.h>
#include "Drawable.hpp"
#include <iostream>

class Board{
public:
    Board(){
        construct(WORLD_HEIGHT, WORLD_WIDTH);
        initialize();
    }
    
    Board(int height, int width){
        construct(height, width);
        initialize();
        
    }
    
    void initialize(){
        clear();
        refresh();
    }
    
    void addBorder(){
        box(boardwin, 0, 0);
    }
    
    void add(Drawable drawble){
        addAt(drawble.getY(), drawble.getX(), drawble.getIcon());
    }
    
    void addAt(int y , int x, chtype ch){
        mvwaddch(boardwin, y, x, ch);
    }
    
    //wgetch gives refresh for free
    chtype getInput(){
        return wgetch(boardwin);
    }
    
    void getEmptyCoordinates(int& y, int&x){
        while((mvwinch(boardwin, y = rand()%height, x= rand()%width)) != ' ');
    }
    
    
    void clear(){
        wclear(boardwin);
        addBorder();
    }
    
    void refresh(){
        wrefresh(boardwin);
    }
    
    void setTimeout(int timeout){
        wtimeout(boardwin, timeout);
    }
    
    chtype getCharAT(int y , int x){
        return mvwinch(boardwin, y, x);
    }
    
    int getStartRow(){
        return startRow;
    }
    
    int getStartCol(){
        return startCol;
    }
    
private:
    WINDOW *boardwin;
    int height , width, startRow, startCol;
    
    void construct(int height, int width){
        int xMax, yMax;
        getmaxyx(stdscr, yMax, xMax);
        this ->height = height;
        this ->width = width;
        
        startRow = (yMax/2)-(height/2);
        startCol = (xMax/2)-(width/2);
        
        boardwin = newwin(height, width, startRow, startCol);
        
        //Add timeout
        wtimeout(boardwin, SPEED);
        
        //Add keypad calls
        keypad(boardwin, true);
    }
    
};

#endif /* board_hpp */
