#ifndef __BLOCKANIMATION_H__
#define __BLOCKANIMATION_H__
#include <iostream>
#include <vector>
#include <string>
#include "block.h"
#include "board.h"
#include "window.h"
#include "nextBlock.h"
#include "level.h"
#include "cell.h"

class PlayerDisplay {
  Xwindow *pxw;
  shared_ptr<Board> newbd;
  Board *boardContent;
  int level;
  int playerpos;//50 means left, 285 means right
  PlayerDisplay *opp;
  shared_ptr<Block> currBlk;
  shared_ptr<ConcreteLevel> CL;
  shared_ptr<Block> nextBlk;
  Block *currblk;
  Block *nextblk;
  string scriptFile = " ";
  string newScriptFile = " ";
  unsigned int seed;
  int blknum = 1;
  //Score score;
  bool textOnly= false;
  bool endround = false;  
  int score = 0;
  int scorehi = 0;
  shared_ptr<NextBlock>Next;
  shared_ptr<NextBlock>Nexttemp;
  NextBlock *next;
  NextBlock *nexttemp;
  bool endGame = false;
  int lvUp = 0;
  int lvDown = 0;
  int heavy = 0;
  int fivetracker = 0;
  bool rand = true;
  bool blind = false;
  ConcreteLevel* cl;
  public:
  PlayerDisplay(Xwindow *, Board *, int, int, string, bool);
  ~PlayerDisplay();
  shared_ptr<Block> newNext(NextBlock *);
  void blockUpdate();
  void blockClear();
  void prtLevel();
  void prtScore();
  int getScore(bool);
  void prtNext();
  void moveLeft();
  void moveRight();
  void moveDown();
  void rotateClock();
  void rotateCounterClock();
  void drop();
  void checkEndGame();
  bool checkEndRound();
  void heavier();
  void force(char);
  void printB();
  void setblind();
  bool enterCmd();
  void playerQuickplay();
  void clrLine();
  bool playerPlay();
  bool getStatus();
  void setSeed(int);
  void initialDP();
  void reset();
  void setTextOnly(bool);
  void setOpponent(PlayerDisplay *);
  void prtBlock();
  void prtBlind();
  void textDisplay();  
};


#endif