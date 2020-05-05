//
// Created by valkee on 4/26/2020.
//
#define WITHOUT_NUMPY

#include "matplotlibcpp.h"
#include "leaderboard.h"
#include <cmath>

namespace plt = matplotlibcpp;

void SaveGraph(timer::LeaderBoard leaderboard) {
  // Retrieve list of players
  std::vector<timer::Player> player_list = leaderboard.RetrieveScores();
  // Preparing data
  int n = player_list.size();
  std::vector<double> x(n), y(n);
  // Add each y position as the players score from the beginning of the database
  for (size_t i = 0; i < player_list.size(); ++i) {
    x.at(i) = i;
    y.at(i) = player_list.at(i).score;
  }
  plt::plot(x, y);
  plt::title("3x3 Cube Times");
  plt::save("C:\\Users\\Natsu\\Documents\\CS126\\cinder_0.9.2_vc2015\\my-project\\final-project-akevli\\assets\\graph.png");
  plt::show();
}