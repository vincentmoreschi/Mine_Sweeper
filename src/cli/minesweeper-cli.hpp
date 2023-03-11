#ifndef MINSWEEPER_CLI_HPP_
#define MINSWEEPER_CLI_HPP_

#include "../base/minesweeper.hpp"

class MinesweeperCli : public Minesweeper {
    bool quit = false;
    int get_board_dimension();
    bool init_board_display();
    bool display();
    bool exit_condition();
    Coordinate get_user_selection();
};

#endif