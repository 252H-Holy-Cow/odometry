#pragma once

// 210 for blue
// 20 for red
constexpr int SORT_COLOUR = 210;

typedef enum { 
  FORWARD = 0, 
  BACKWARD, 
  STOP 
} ConveyorDirection_e;

extern ConveyorDirection_e convDir;
extern int convVelocity;
extern bool doColorSort;
extern bool armToLoadPos;
extern bool armToStartPos;
extern bool armToScorePos;

void debugLoop(void* params);
void conveyorLoop(void* params);
void armLoop(void* params);
