#include "minesweeper.hpp"

Minesweeper::Minesweeper() {}

Minesweeper::~Minesweeper() {}

void Minesweeper::run() {
    Coordinate user_selection;
    get_board_dimension();
    init_board();
    init_board_display();
    
    while(is_active_)
    {
        if (exit_condition()) {
            kill();
            break;
        }
        display();
        user_selection = get_user_selection();
        update_board_state(user_selection);
    }
}

std::vector<Cell> Minesweeper::get_current_board_state(){
    return board_;
}

void Minesweeper::kill() {
    is_active_ = false;
}

void Minesweeper::update_board_state(const Coordinate &user_selection) {}

void Minesweeper::init_board() {}