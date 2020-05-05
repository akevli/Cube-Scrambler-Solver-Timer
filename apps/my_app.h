// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/audio/Voice.h>
#include <cinder/gl/gl.h>
#include <leaderboard.h>
#include <search.h>

#include <random>
#include <string>
#include <vector>

namespace myapp {

class MyApp : public cinder::app::App {
 private:
  timer::LeaderBoard leaderboard_;
  bool graph_state_;
  bool solution_state_;
  bool timer_state_;
  bool leaderboard_state_;
  bool paused_;
  cinder::Timer timer_;
  std::vector<timer::Player> top_players_;
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
