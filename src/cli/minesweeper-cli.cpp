#include "minesweeper-cli.hpp"
#include "../base/minesweeper.hpp"
#include <iostream>
#include <string>

int MinesweeperCli::get_board_dimension(){
    std::cout << "-> MinesweeperCli::" << __func__ << "()\n";
    int size;
    std::cout << "Welcome to Minesweeper \nPlease enter board size. For example typing 5 will generate a 5X5 \n";
    // Get size of board if to big return a -1 for error
    std::cin >> size;
    if(size > MAX_BOARD_DIM){
        std::cout << "Invalid size: over size limit";
        return BOARD_DIM_ERROR;
    }
    return size;

}

std::vector<std::vector<std::string>> MinesweeperCli::init_board_display(){
    // std::cout << "-> MinesweeperCli::" << __func__ << "()\n";
    
    // Board * board =  get_current_board_state();
    // for(int row = 0; row < board->get_size(); row++){
    //     string_board.emplace_back();
    //     for(int col = 0; col < board->get_size(); col++){
    //         Cell * cell = board->get_cell(Coordinate(row,col));
    //         string_board.back().push_back(cell->to_string());
    //     }
    // }
    // return string_board;
}
void MinesweeperCli::display(){
    std::cout << "-> MinesweeperCli::" << __func__ << "()\n";
    auto board = get_current_board_state();
    
    for(int row = 0; row < board->get_size(); row++){
        for(int col = 0; col < board->get_size(); col++){
            // auto cell = board->get_cell(Coordinate(row,col));
            std::cout << board->get_cell(Coordinate(row,col))->to_string() + " ";
        }
        std::cout << "\n";
    }
}
bool MinesweeperCli::exit_condition(){
    return quit_;
}
// read stdin for user input return -1,-1 if input is invalid
Coordinate MinesweeperCli::get_user_selection(){
    std::cout << "-> MinesweeperCli::" << __func__ << "()\n";
    std::string input;
    Coordinate error_coord(-1,-1);
    std::cout <<  "Please enter a coordinate to reveal with the format of x,y ex. 5,5 would be reveal (5,5) on the board\n";
    std::cin >> input;
    if(input =="q"){
        quit_ = true;
        return error_coord;
    }
    Coordinate coord((int)input[0],(int)input[2]);
    return coord;

}