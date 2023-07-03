//#include <ncurses_dll.h>
#include <ncurses.h>
#include "src/board.hpp"
#include "src/SnakeGame.hpp"
#define WORLD_WIDTH 50
#define WORLD_HEIGHT 20

void board();

 
int main(int argc, char *argv[]) {
 
    initscr();
    refresh();
    noecho();
    curs_set(0);
    
    SnakeGame myGame= SnakeGame(WORLD_HEIGHT,WORLD_WIDTH);
    while (!myGame.isOver()){
        myGame.processInput();
        myGame.updateState();
        myGame.redraw();
    }
    
    // 1. Get input from the user
    
    
    // 2. update game state
    
    // 3. redaw display
    
    // 4. go to 1, unless over
    
    getch();
    endwin();
    
    std::cout <<"Game is over. Well Played!!. The final score was "<< myGame.getScore() << std::endl;
    
    return 0;
 
}
