//
//  Scoreboard.hpp
//  Snake_game
//
//  Created by Naren Sadhwani on 12.02.23.
//

#ifndef Scoreboard_hpp
#define Scoreboard_hpp

#pragma once
#include <stdio.h>
#include <ncurses.h>



class Scoreboard{
    WINDOW *scoreWin;
    
public:
    Scoreboard(){}
    
    Scoreboard(int width, int y , int x){
        scoreWin = newwin(1, width, y, x);
    }
    
    void initialize(int initialScore){
        clear();
        mvwprintw(scoreWin, 0, 0, "Score:");
        updateScore(initialScore);
        refresh();
        
    }
    
    void updateScore(int score){
        mvwprintw(scoreWin, 0, getmaxx(scoreWin) - 10, "%10lu", score);
    }
    
    void clear(){
        wclear(scoreWin);
    }
    
    void refresh(){
        wrefresh(scoreWin);
    }
};
#endif /* Scoreboard_hpp */
