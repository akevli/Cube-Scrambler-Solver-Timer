//
// Created by valkee on 4/25/2020.
//

#ifndef FINALPROJECT_CORNER_H
#define FINALPROJECT_CORNER_H
// The names of the corner positions of the cube. Corner URF e.g., has an U(p), a R(ight) and a F(ront) facelet
typedef enum {
  URF, UFL, ULB, UBR, DFR, DLF, DBL, DRB
} corner_t;

#define CORNER_COUNT 8

#endif  // FINALPROJECT_CORNER_H
