#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <vector>
#include <iostream>

#include "cell.hpp"

class Board {
public:
    Board(int dimension, int num_mines) : dimension_(dimension), num_mines_(num_mines)
    {
        // initialize all the mines
        bool is_mine = false;
        for (int row = 0; row < dimension; row++)
        {

            // create a new row
            contents_.emplace_back();
            for (int col = 0; col < dimension; col++)
            {
                if (num_mines > 0){
                    int rand = std::rand() % 5 + 1;
                    if(rand == 3){
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

        // update adjacent count for adjacent mines HORIZONTALLY

        // update adjacent count for adjacent mines VERTICALLY
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