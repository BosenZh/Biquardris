#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <string>
#include "playerDisplay.h"
using namespace std;

const uint32_t DEFAULT_SEED = 123456789;

class GameDisplay {
  Xwindow *pxw; // 600*500, each cell takes 15, margin = 50, each string takes 30, distance between two boards is 70
  PlayerDisplay *p1; 
  PlayerDisplay *p2; 
  int currentSeed; // used for setting seed by user.
  bool textOnly;
  bool restart = true;

  public:
  GameDisplay(Xwindow *, PlayerDisplay *, PlayerDisplay *, bool);
  void boardSetUp();
  void play();
};

#endif