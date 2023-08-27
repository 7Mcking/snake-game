# snake-game on mac terminal

This is c++ version of snake game that can be played on the terminal. It requires ncurses on mac in order to be played and will only work on mac. In order to play the game make sure you have setup the required libraries on mac
and the linker sees the library

To play the game download the repo and build.

```
git clone https://github.com/7Mcking/snake-game.git
```

Navigate to the main.cpp file in the cloned repo and build 


```
clang++ main.cpp -lncurses -o main.out
```
Run
```
./main.out
```

How it looks:
![Snake Game](https://github.com/7Mcking/snake-game/blob/main/Screenshot%202023-08-27%20at%2013.00.38.png)


