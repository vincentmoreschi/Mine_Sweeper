#include "minesweeper-cli.hpp"
#include "../base/minesweeper.hpp"
#include <iostream>

int MinesweeperCli::get_board_dimension(){
    int size;
    std::cout << "Please enter board size. For example typing 5 will generate a 5X5 board maximum is 10";
    std::cin >> size;
    if(size > 10){
        std::cout << "To Big";
    }
    return size;

}

bool MinesweeperCli::init_board_display(){
    
}
bool MinesweeperCli::display(){

}
bool MinesweeperCli::exit_condition(){
    quit= true;
}
// read stdin for user input return -1,-1 if input is invalid
Coordinate MinesweeperCli::get_user_selection(){
    char*  input;
    std::cin >> input;
    if(!strcmp(input,"q") ){
        exit_condition();
    }
}