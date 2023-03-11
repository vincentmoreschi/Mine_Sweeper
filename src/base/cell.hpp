#ifndef CELL_HPP_
#define CELL_HPP_

#include <string>

struct Coordinate {
  int x;
  int y;
};

class Cell {
public:
  enum class State { REVEALED, HIDDEN };

  Cell(bool is_mine, Coordinate coordinate)
      : is_mine_(is_mine), coordinate_(coordinate) {}

  void update_adjacent_number(int num) { adjacent_mines_ = num; }

  bool is_mine() { return is_mine_; }

  void reveal() { state_ = State::REVEALED; }

  State get_state() { return state_; }

  std::string to_string();  

private:
  const bool is_mine_;
  const Coordinate coordinate_;
  int adjacent_mines_ = -1;
  State state_ = State::HIDDEN;
};

#endif