#include "minesweeper.hpp"
#include "board.hpp"


Minesweeper::Minesweeper() {
    // std::cout << "-> Minesweeper::" << __func__ << "()\n";
}

Minesweeper::~Minesweeper() {
    // std::cout << "-> Minesweeper::" << __func__ << "()\n";
}

void Minesweeper::run() {
    // std::cout << "-> Minesweeper::" << __func__ << "()\n";

    board_dimension_ = get_board_dimension();
    init_board();
    // init_board_display();
    
    is_active_ = true;
    while(is_active_)
    {
        display();
        Coordinate user_selection = get_user_selection();
        if (exit_condition()) {
            kill();
            break;
        }

        update_board_state(user_selection);
    }
}

std::shared_ptr<Board> Minesweeper::get_current_board_state(){
    // std::cout << "-> Minesweeper::" << __func__ << "()\n";
    return board_;
}

void Minesweeper::kill() {
    // std::cout << "-> Minesweeper::" << __func__ << "()\n";
    is_active_ = false;
}

void Minesweeper::update_board_state(const Coordinate &user_selection) {
    std::cout << "-> Minesweeper::" << __func__ << "()\n";
    Cell * check_cell = board_->get_cell(user_selection);

    check_cell->reveal();

}

void Minesweeper::init_board() {
    // std::cout << "-> Minesweeper::" << __func__ << "()\n";
    board_ = std::make_shared<Board>(board_dimension_,mines_);
}