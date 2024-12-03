#pragma once

// 210 for blue
// 20 for red
constexpr int SORT_COLOUR = 210;

typedef enum { 
  FORWARD = 0, 
  BACKWARD, 
  STOP 
} ConveyorDirection_e;

extern bool doColorSort;
extern bool armToLoadPos;
extern bool armToStartPos;

extern ConveyorDirection_e convDir;

void debugTask(void *params);
void conveyorTask(void *params);
void armTask(void *params);
void autonColorSort(void *params);