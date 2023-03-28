#ifndef MINSWEEPER_CLI_HPP_
#define MINSWEEPER_CLI_HPP_

#include "../base/minesweeper.hpp"
#include "../base/board.hpp"

class MinesweeperCli : public Minesweeper {
    bool quit_ = false;
    int get_board_dimension();
    std::vector<std::vector<std::string>> init_board_display();
    void display();
    bool exit_condition();
    Coordinate get_user_selection();
    bool tryParse(std::string& input, int& output);
};

#endif