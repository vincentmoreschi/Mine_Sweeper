#include "minesweeper-cli.hpp"
#include "../base/minesweeper.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

int MinesweeperCli::get_board_dimension(){
    std::cout << "-> MinesweeperCli::" << __func__ << "()\n";
    std::string input;
    int size;
    std::cout << "Welcome to Minesweeper, you can press q at anytime to quit \nPlease enter board size. For example typing 5 will generate a 5X5 \n";
    // Get size of board if to big return a -1 for error
    
    getline(std::cin,input);
    while(!tryParse(input,size)){
        
        std::cout << "Please enter a number\n";
        getline(std::cin,input);
        if(input == "q"){
            quit_ = true;
            return BOARD_DIM_ERROR;
        }
        // if(size > MAX_BOARD_DIM){
        //     std::cout << "Invalid size: over size limit\n";
        // }
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
    std::cout << "  ";
    for(int i = 0; i < board->get_size();i++){
        std::cout << i;
        std::cout << " ";
    }
    std::cout << " ";
    std::cout << "y";
    std::cout << "\n";
    for(int row = 0; row < board->get_size(); row++){
        std::cout << row;
         std::cout << " ";
        for(int col = 0; col < board->get_size(); col++){
            // auto cell = board->get_cell(Coordinate(row,col));
            std::cout << board->get_cell(Coordinate(row,col))->to_string() + " ";
        }
        std::cout << "\n";
        

       
    }
    std::cout << "x\n";
}
bool MinesweeperCli::exit_condition(){
    return quit_;
}
// read stdin for user input return -1,-1 if input is invalid
Coordinate MinesweeperCli::get_user_selection(){
    std::cout << "-> MinesweeperCli::" << __func__ << "()\n";
    std::string input;
    Coordinate error_coord(-1,-1);
    std::cout <<  "Please enter a coordinate to reveal a square, you can type 'q' at anytime to quit\nPlease enter the X coord \n";
    int x,y = 0;
    auto board = get_current_board_state();
   
    getline(std::cin,input);

    while(true){
        if(input =="q"){
            quit_ = true;
            return error_coord;
        }
        if (tryParse(input,x)){
            if(x < 0 || x > board->get_size()){
                std::cout << "Number outside of range\n";
                getline(std::cin,input);
            }else{
                break;
            }
        }else{
            std::cout << "Please enter a number\n";
            getline(std::cin,input);
        }
    }

    std::cout << "Please enter the Y coord\n";
    getline(std::cin,input);

    while(true){
        if(input =="q"){
            quit_ = true;
            return error_coord;
        }
        if (tryParse(input,y)){
            if(y < 0 || y > board->get_size()){
                std::cout << "Number outside of range\n";
                getline(std::cin,input);
            }else{
                break;
            }
            
        }else{
            std::cout << "Please enter a number\n";
            getline(std::cin,input);
        }
        
    }
    
    Coordinate coord(x,y);
    // std::cout << coord.x;
    // std::cout << coord.y;
    return coord;

}
bool MinesweeperCli::tryParse(std::string& input, int& output){
    try{
        output = std::stoi(input);
    } catch(std::invalid_argument){
        return false;
    }
    return true;
}