//
// Created by valkee on 4/25/2020.
//

#ifndef FINALPROJECT_EDGE_H
#define FINALPROJECT_EDGE_H
// The names of the edge positions of the cube. Edge UR e.g., has an U(p) and R(ight) facelet.
typedef enum {
  UR, UF, UL, UB, DR, DF, DL, DB, FR, FL, BL, BR
} edge_t;

#define EDGE_COUNT 12
#endif  // FINALPROJECT_EDGE_H
