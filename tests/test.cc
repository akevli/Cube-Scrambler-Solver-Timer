// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include "leaderboard.h"
#include "player.h"
#include "scramble.h"
#include "search.h"
#include "engine.h"

#include <catch2/catch.hpp>

TEST_CASE("Random sanity test", "[random]") {
  const float random = cinder::randFloat();
  REQUIRE(0. <= random);
  REQUIRE(random <= 1.);
}

TEST_CASE("Test Scrambler", "[scramble]") {
  std::vector<std::string> scramble_one = GetScramble();
  std::vector<std::string> scramble_two = GetScramble();
  std::string string_scramble_one;
  std::string string_scramble_two;
  for (size_t i = 0; i < scramble_one.size(); ++i) {
    string_scramble_one += scramble_one.at(i);
    string_scramble_two += scramble_two.at(i);
  }
  REQUIRE(string_scramble_one != string_scramble_two);
}