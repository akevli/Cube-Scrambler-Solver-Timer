//
// Created by valkee on 4/25/2020.
//

#include <string>
#include <vector>

std::string up = "UUUUUUUUU";
std::string right = "RRRRRRRRR";
std::string front = "FFFFFFFFF";
std::string down = "DDDDDDDDD";
std::string left = "LLLLLLLLL";
std::string back = "BBBBBBBBB";

std::string temp_up = "UUUUUUUUU";
std::string temp_right = "RRRRRRRRR";
std::string temp_front = "FFFFFFFFF";
std::string temp_down = "DDDDDDDDD";
std::string temp_left = "LLLLLLLLL";
std::string temp_back = "BBBBBBBBB";

void UpdateState() {
  temp_up = up;
  temp_right = right;
  temp_front = front;
  temp_down = down;
  temp_left = left;
  temp_back = back;
}

void ResetSolvedState() {
  up = "UUUUUUUUU";
  right = "RRRRRRRRR";
  front = "FFFFFFFFF";
  down = "DDDDDDDDD";
  left = "LLLLLLLLL";
  back = "BBBBBBBBB";

  temp_up = "UUUUUUUUU";
  temp_right = "RRRRRRRRR";
  temp_front = "FFFFFFFFF";
  temp_down = "DDDDDDDDD";
  temp_left = "LLLLLLLLL";
  temp_back = "BBBBBBBBB";
}

void CWFront() {
  // Rotate other sides
  up[6] = temp_left[8];
  up[7] = temp_left[5];
  up[8] = temp_left[2];

  right[0] = temp_up[6];
  right[3] = temp_up[7];
  right[6] = temp_up[8];

  down[0] = temp_right[6];
  down[1] = temp_right[3];
  down[2] = temp_right[0];

  left[2] = temp_down[0];
  left[5] = temp_down[1];
  left[8] = temp_down[2];

  // Rotate front cubelets
  // Rotate corners first
  front[2] = temp_front[0];
  front[8] = temp_front[2];
  front[6] = temp_front[8];
  front[0] = temp_front[6];

  // Rotate edges
  front[5] = temp_front[1];
  front[7] = temp_front[5];
  front[3] = temp_front[7];
  front[1] = temp_front[3];

  UpdateState();
}

void CCWFront() {
  CWFront();
  CWFront();
  CWFront();
}

void CWBack() {
  // Rotate edges
  left[0] = temp_up[2];
  left[3] = temp_up[1];
  left[6] = temp_up[0];

  down[6] = temp_left[0];
  down[7] = temp_left[3];
  down[8] = temp_left[6];

  right[2] = temp_down[8];
  right[5] = temp_down[7];
  right[8] = temp_down[6];

  up[2] = temp_right[8];
  up[1] = temp_right[5];
  up[0] = temp_right[2];

  // Rotate back cubelets
  // Rotate corners first
  back[2] = temp_back[0];
  back[8] = temp_back[2];
  back[6] = temp_back[8];
  back[0] = temp_back[6];

  // Rotate edges
  back[5] = temp_back[1];
  back[7] = temp_back[5];
  back[3] = temp_back[7];
  back[1] = temp_back[3];

  UpdateState();
}

void CCWBack() {
  CWBack();
  CWBack();
  CWBack();
}

void CWRight() {
  // Rotate other sides
  up[2] = temp_front[2];
  up[5] = temp_front[5];
  up[8] = temp_front[8];

  back[0] = temp_up[8];
  back[3] = temp_up[5];
  back[6] = temp_up[2];

  down[2] = temp_back[6];
  down[5] = temp_back[3];
  down[8] = temp_back[0];

  front[2] = temp_down[2];
  front[5] = temp_down[5];
  front[8] = temp_down[8];
  // Rotate right cubelets
  // Rotate corners first
  right[2] = temp_right[0];
  right[8] = temp_right[2];
  right[6] = temp_right[8];
  right[0] = temp_right[6];

  // Rotate edges
  right[5] = temp_right[1];
  right[7] = temp_right[5];
  right[3] = temp_right[7];
  right[1] = temp_right[3];

  UpdateState();
}

void CCWRight() {
  CWRight();
  CWRight();
  CWRight();
}

void CWLeft() {
  // Rotate edges
  front[0] = temp_up[0];
  front[3] = temp_up[3];
  front[6] = temp_up[6];

  down[0] = temp_front[0];
  down[3] = temp_front[3];
  down[6] = temp_front[6];

  back[2] = temp_down[6];
  back[5] = temp_down[3];
  back[8] = temp_down[0];

  up[0] = temp_back[8];
  up[3] = temp_back[5];
  up[6] = temp_back[2];

  // Rotate left cubelets
  // Rotate corners first
  left[2] = temp_left[0];
  left[8] = temp_left[2];
  left[6] = temp_left[8];
  left[0] = temp_left[6];

  // Rotate edges
  left[5] = temp_left[1];
  left[7] = temp_left[5];
  left[3] = temp_left[7];
  left[1] = temp_left[3];

  UpdateState();
}

void CCWLeft() {
  CWLeft();
  CWLeft();
  CWLeft();
}

void CWUp() {
  // Rotate other sides
  left[0] = temp_front[0];
  left[1] = temp_front[1];
  left[2] = temp_front[2];

  back[0] = temp_left[0];
  back[1] = temp_left[1];
  back[2] = temp_left[2];

  right[0] = temp_back[0];
  right[1] = temp_back[1];
  right[2] = temp_back[2];

  front[0] = temp_right[0];
  front[1] = temp_right[1];
  front[2] = temp_right[2];

  // Rotate up cubelets
  // Rotate corners first
  up[2] = temp_up[0];
  up[8] = temp_up[2];
  up[6] = temp_up[8];
  up[0] = temp_up[6];

  // Rotate edges
  up[5] = temp_up[1];
  up[7] = temp_up[5];
  up[3] = temp_up[7];
  up[1] = temp_up[3];

  UpdateState();
}

void CCWUp() {
  CWUp();
  CWUp();
  CWUp();
}

void CWDown() {
  // Rotate other sides
  right[6] = temp_front[6];
  right[7] = temp_front[7];
  right[8] = temp_front[8];

  back[6] = temp_right[6];
  back[7] = temp_right[7];
  back[8] = temp_right[8];

  left[6] = temp_back[6];
  left[7] = temp_back[7];
  left[8] = temp_back[8];

  front[6] = temp_left[6];
  front[7] = temp_left[7];
  front[8] = temp_left[8];

  // Rotate down cubelets
  // Rotate corners first
  down[2] = temp_down[0];
  down[8] = temp_down[2];
  down[6] = temp_down[8];
  down[0] = temp_down[6];

  // Rotate edges
  down[5] = temp_down[1];
  down[7] = temp_down[5];
  down[3] = temp_down[7];
  down[1] = temp_down[3];

  UpdateState();
}

void CCWDown() {
  CWDown();
  CWDown();
  CWDown();
}

std::string GetScrambledState(std::vector<std::string> scramble) {
  ResetSolvedState();
  for (const auto & move : scramble) {
    if (move == "U") {
      CWUp();
    } else if (move == "U'") {
      CCWUp();
    } else if (move == "U2") {
      CWUp();
      CWUp();
    }

    if (move == "F") {
      CWFront();
    } else if (move == "F'") {
      CCWFront();
    } else if (move == "F2") {
      CWFront();
      CWFront();
    }

    if (move == "R") {
      CWRight();
    } else if (move == "R'") {
      CCWRight();
    } else if (move == "R2") {
      CWRight();
      CWRight();
    }

    if (move == "L") {
      CWLeft();
    } else if (move == "L'") {
      CCWLeft();
    } else if (move == "L2") {
      CWLeft();
      CWLeft();
    }

    if (move == "B") {
      CWBack();
    } else if (move == "B'") {
      CCWBack();
    } else if (move == "B2") {
      CWBack();
      CWBack();
    }

    if (move == "D") {
      CWDown();
    } else if (move == "D'") {
      CCWDown();
    } else if (move == "D2") {
      CWDown();
      CWDown();
    }
  }

  std::string updated_state = up + right + front + down + left + back;
  return updated_state;
}