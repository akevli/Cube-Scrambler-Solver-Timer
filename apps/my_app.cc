// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <sqlite3.h>

#include <catch2/catch.hpp>
#include <chrono>
#include <cmath>
#include <string>

#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "scramble.h"
#include "search.h"
#include "engine.h"
#include "graph.h"

namespace myapp {

using cinder::app::KeyEvent;
using cinder::Color;
using cinder::ColorA;
using cinder::Rectf;
using cinder::TextBox;
using cinder::app::KeyEvent;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::system_clock;
using std::string;

const char kNormalFont[] = "Arial";
const char kDbPath[] = "timer.db";
std::vector<std::string> Scramble;
std::string scramble_string;
std::string solve_algorithm;
double time = 0.00;
char* char_state = new char[54];
char* sol;


template <typename C>
void PrintText(const string& text, const C& color, const cinder::ivec2& size,
               const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = TextBox()
      .alignment(TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 30))
      .size(size)
      .color(color)
      .backgroundColor(ColorA(0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);

  cinder::gl::draw(texture, locp);
}

MyApp::MyApp() : leaderboard_{cinder::app::getAssetPath(kDbPath).string()} {
  Scramble = GetScramble();
  scramble_string = GetScrambledState(Scramble);
  graph_state_ = false;
  timer_state_ = false;
  solution_state_ = false;
  leaderboard_state_ = true;
  paused_ = false;
  std::strcpy(char_state, scramble_string.c_str());
  sol = solution(char_state, 24, 1000, 0, "cache");
}

void MyApp::setup() {
  cinder::gl::enableDepthWrite();
  cinder::gl::enableDepthRead();
}

void MyApp::update() {
  if (!leaderboard_state_) {
    if (top_players_.empty()) {
      leaderboard_.AddScoreToLeaderBoard({time});
      top_players_ = leaderboard_.RetrieveScores();
      // It is crucial the this vector be populated, given that `kLimit` > 0.
      assert(!top_players_.empty());
    }

    return;
  }

  if (paused_) {
    return;
  }
}

void MyApp::draw() {
  cinder::gl::enableAlphaBlending();

  cinder::gl::clear();
  const cinder::vec2 center = getWindowCenter();
  cinder::ivec2 size = {500, 50};
  const Color color = Color::white();

  std::string scramble_moves;
  for (const auto& move : Scramble) {
    scramble_moves += move + " ";
  }

  double display_time = timer_.getSeconds();
  PrintText("*Scramble with Green in front and White on top*", Color::hex(0xFF0000), {500, 50},
      {center.x, center.y - 250});
  PrintText(std::to_string(display_time), color, {2000, 200},
      {center.x, center.y - 200});
  PrintText("Scramble", color, size, center);
  PrintText(scramble_moves, color, size, {center.x, center.y + 50});
  PrintText("Solution", color, size, {center.x, center.y + 100});
  if (solution_state_) {
    PrintText(solve_algorithm, color, size, {center.x, center.y + 150});
  }
  size = {15, 30};
  for (size_t i = 0; i < scramble_string.size(); ++i) {
    int y_coord = 200;
    double displacement = 67.5;
    if (i < 9) {
      y_coord = 200;
      displacement = 67.5;
      PrintText("Upper Layer: ", color, {150, 30}, {center.x - 150, center.y + y_coord});
    } else if (i < 18) {
      y_coord = 230;
      displacement = 202.5;
      PrintText("Right Layer: ", Color::hex(0xFF0000), {150, 30}, {center.x - 150, center.y + y_coord});
    } else if (i < 27) {
      y_coord = 260;
      displacement = 337.5;
      PrintText("Front Layer: ", Color::hex(0x00FF00), {150, 30}, {center.x - 150, center.y + y_coord});
    } else if (i < 36) {
      y_coord = 290;
      displacement = 472.5;
      PrintText("Bottom Layer: ", Color::hex(0xFFFF00), {150, 30}, {center.x - 150, center.y + y_coord});
    } else if (i < 45) {
      y_coord = 320;
      displacement = 607.5;
      PrintText("Left Layer: ", Color::hex(0xFFA500), {150, 30}, {center.x - 150, center.y + y_coord});
    } else {
      y_coord = 350;
      displacement = 742.5;
      PrintText("Back Layer: ", Color::hex(0x0000ff), {150, 30}, {center.x - 150, center.y + y_coord});
    }
    if (char_state[i] == 'U') {
      PrintText("U", Color::white(), size,
                {center.x + (15 * i) - displacement, center.y + y_coord});
    } else if (char_state[i] == 'R') {
      PrintText("R", Color::hex(0xFF0000), size,
                {center.x + (15 * i) - displacement, center.y + y_coord});
    } else if (char_state[i] == 'F') {
      PrintText("F", Color::hex(0x00FF00), size,
                {center.x + (15 * i) - displacement, center.y + y_coord});
    } else if (char_state[i] == 'D') {
      PrintText("D", Color::hex(0xFFFF00), size,
                {center.x + (15 * i) - displacement, center.y + y_coord});
    } else if (char_state[i] == 'L') {
      PrintText("L", Color::hex(0xFFA500), size,
                {center.x + (15 * i) - displacement, center.y + y_coord});
    } else if (char_state[i] == 'B') {
      PrintText("B", Color::hex(0x0000ff), size,
                {center.x + (15 * i) - displacement, center.y + y_coord});
    }
  }
}

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_SPACE: {
      if (!timer_state_) {
        timer_.start();
        timer_state_ = true;
        leaderboard_state_ = true;
        break;
      } else {
        time = timer_.getSeconds();
        timer_.stop();
        timer_state_ = false;
        leaderboard_state_ = false;
        top_players_.clear();
        break;
      }
    }
    case KeyEvent::KEY_t: {
      Scramble = GetScramble();
      scramble_string = GetScrambledState(Scramble);
      solution_state_ = false;
      std::strcpy(char_state, scramble_string.c_str());
      sol = solution(char_state, 24, 1000, 0, "cache");
      break;
    }
    case KeyEvent::KEY_v: {
      if (sol == NULL) {
        solve_algorithm = "Unsolvable";
      } else {
        solve_algorithm = std::string(sol);
        free(sol);
      }
      solution_state_ = true;
      break;
    }
    case KeyEvent::KEY_g: {
      SaveGraph(leaderboard_);
      graph_state_ = !graph_state_;
      paused_ = !paused_;
      break;
    }
  }
}
}  // namespace myapp
