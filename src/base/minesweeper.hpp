#ifndef MINSWEEPER_HPP_
#define MINSWEEPER_HPP_

#include "cell.hpp"
#include "board.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Minesweeper {
public:
    void run();
    const Coordinate INVALID_COORDINATE{-1,-1};
protected:
  Minesweeper();
  ~Minesweeper();

  
  std::shared_ptr<Board> get_current_board_state();

  void kill();
  virtual int get_board_dimension() = 0;
  virtual std::vector<std::vector<std::string>> init_board_display() = 0;
  virtual void display() = 0;
  virtual bool exit_condition() = 0;
  virtual Coordinate get_user_selection() = 0;

  const int MAX_BOARD_DIM = 10;
  const int BOARD_DIM_ERROR = -1;

private:
  void update_board_state(const Coordinate &user_selection);
  void init_board();

  std::shared_ptr<Board> board_;
  int board_dimension_ = BOARD_DIM_ERROR;
  bool is_active_;
  const int mines_ = 3;
};

#endif