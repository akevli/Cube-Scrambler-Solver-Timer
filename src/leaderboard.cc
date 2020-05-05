#include <leaderboard.h>
#include <player.h>
#include <sqlite_modern_cpp.h>

#include <string>
#include <vector>

namespace timer {

using std::string;
using std::vector;

// See examples: https://github.com/SqliteModernCpp/sqlite_modern_cpp/tree/dev

LeaderBoard::LeaderBoard(const string& db_path) : db_{db_path} {
  db_ << "CREATE TABLE if not exists leaderboard (\n"
         "  score REAL NOT NULL\n"
         ");";
}

void LeaderBoard::AddScoreToLeaderBoard(const Player& player) {
  db_ << "insert into leaderboard (score) values (?);"
      << player.score;
}

vector<Player> GetPlayers(sqlite::database_binder* rows) {
  vector<Player> players;

  for (auto&& row : *rows) {
    string name;
    double score;
    row >> score;
    Player player = {score};
    players.push_back(player);
  }

  return players;
}

vector<Player> LeaderBoard::RetrieveScores() {
  auto rows = db_ << "select score from leaderboard";
  return GetPlayers(&rows);
}
}  // namespace timer

