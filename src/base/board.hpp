#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <vector>
#include <iostream>

#include "cell.hpp"

class Board {
public:
    Board(int dimension, int num_mines) : dimension_(dimension), num_mines_(num_mines)
    {
        
        for (int row = 0; row < dimension; row++)
        {

            // create a new row
            contents_.emplace_back();
            for (int col = 0; col < dimension; col++)
            {
                // initialize all the mines

                bool is_mine = false;
                if (num_mines > 0){
                    int rand = std::rand() % 5 + 1;
                    if(rand == 2){
                        num_mines--;
                        is_mine= true;
                    }
                }
                Cell init_cell = Cell(is_mine, Coordinate(row, col));
                // create each cell in that row
                contents_.back().push_back(Cell(is_mine, Coordinate(row, col)));
                // std::cout << cell1.to_string() + " ";
            }
            // std::cout << "\n";
        }
        // for(int row = 0; row < dimension; row++){

        //     for(int col = 0; col < dimension; col++ ){
        //         Cell * check_cell = get_cell(Coordinate(row,col));
        //         // check for mine
        //         // if a mine is found start updating adjacent number
        //         if(check_cell->is_mine()){
        //             for(int i = 4; i > 0 ; i--){
        //                 //down
        //                 Cell * check_cell = get_cell(Coordinate(row-1,col));
        //                 check_cell->update_adjacent_number(i);

        //                 Cell * check_cell = get_cell(Coordinate(row,col-1));
        //                 check_cell->update_adjacent_number(i);

        //                 Cell * check_cell = get_cell(Coordinate(row+1,col));
        //                 check_cell->update_adjacent_number(i);
                                                
        //                 Cell * check_cell = get_cell(Coordinate(row,col));
        //                 check_cell->update_adjacent_number(i);
        //             }
        //         }
        //     }
        // }
        // update adjacent count for adjacent mines HORIZONTALLY

        // update adjacent count for adjacent mines VERTICALLY
    }
    void fill_adjacent(int row, int col, int num){
        //base case
        if(num == 0) return;



    }
    Cell* get_cell(Coordinate coordinate)
    {
        return &contents_[coordinate.x][coordinate.y];
    }

    int get_size()
    {
        return contents_.size();
    }
private:
    const int dimension_;
    const int num_mines_;

    std::vector<std::vector<Cell>> contents_;
};

#endif