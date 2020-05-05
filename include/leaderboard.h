//
// Created by valkee on 4/24/2020.
//

#ifndef FINALPROJECT_LEADERBOARD_H
#define FINALPROJECT_LEADERBOARD_H

#include <sqlite_modern_cpp.h>

#include <string>
#include <vector>

#include "player.h"

namespace timer {

class LeaderBoard {
 public:
  // Creates a new leaderboard table if it doesn't already exist.
  explicit LeaderBoard(const std::string& db_path);

  // Adds a player to the leaderboard.
  void AddScoreToLeaderBoard(const Player&);

  // Returns a list of the players with the highest scores, in decreasing order.
  // The size of the list should be no greater than `limit`.
  std::vector<Player> RetrieveScores();
 private:
  sqlite::database db_;
};

}  // namespace timer

#endif  // FINALPROJECT_LEADERBOARD_H