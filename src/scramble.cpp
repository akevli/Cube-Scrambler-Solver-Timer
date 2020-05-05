//
// Created by valkee on 4/25/2020.
//

#include "scramble.h"

#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

const int scramble_length = 21;
const int number_moves = 18;

int RandomMove() {
  int x = std::rand() % number_moves;
  return x;
}

std::vector<std::string> GetScramble() {
  std::string moves[number_moves] = {"U", "F", "B", "D", "R", "L", "U2", "F2", "B2", "D2", "R2", "L2", "U'", "F'", "B'", "D'", "R'", "L'"};
  std::vector<std::string> scramble;
  for (size_t i = 0; i < scramble_length; ++i) {
    scramble.push_back(moves[RandomMove()]);
  }
  return scramble;
}