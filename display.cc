#include "display.h"
#include "window.h"
#include "playerDisplay.h"
#include <stdlib.h>
#include <sstream>
#include <iostream>


using namespace std;
GameDisplay::GameDisplay(Xwindow *pxw, PlayerDisplay *p1, PlayerDisplay *p2, bool textOnly):
pxw{ pxw }, p1{ p1 }, p2{ p2 }, textOnly{ textOnly} {}


void GameDisplay::boardSetUp(){
   pxw->drawString(50, 110, "-----------");
   pxw->drawString(285, 110, "-----------");
   pxw->fillRectangle(50, 160, 165, 270, pxw->Blue);
   pxw->fillRectangle(285, 160, 165, 270, pxw->Blue);
   pxw->drawString(50, 440, "-----------");
   pxw->drawString(285, 440, "-----------");
   pxw->drawString(50, 460, "Next:");
   pxw->drawString(285, 460, "Next:");
}

void GameDisplay::play() {
   int score;
   int hiscore;
   if(!textOnly){
   pxw->fillRectangle(0, 0, 500, 600, pxw->White);
   boardSetUp();
   p1->prtLevel();
   p2->prtLevel();
   p1->prtScore();
   p2->prtScore();
   }
   p1->initialDP();
   p2->initialDP();
   if(restart == true){
   p1->setOpponent(p2);
   p2->setOpponent(p1);
   }
   restart = true;
   while (restart == true) {
   while(p1->getStatus()!= true && p2->getStatus()!= true){
      cout<< "Player 1" << endl;
      restart = p1->playerPlay();
      if(restart == true){
         break;
      }
      if(p1->getStatus()== true){
         pxw->fillRectangle(50, 50, 400, 500, pxw->Red);
         pxw->drawString(250,200,"Game End");
         pxw->drawString(250,250,"P2 wins");
         score = p1->getScore(false);
         hiscore = p1->getScore(true);
         stringstream out;
         out << " Player 1 Current Score: " << score << ", Highest score: "<<hiscore;
         string op;
         getline(out, op);
         pxw->drawString(150, 300, op);
         score = p2->getScore(false);
         hiscore = p2->getScore(true);
         out << " Player 2 Current Score: " << score << ", Highest score: "<<hiscore;
         getline(out, op);
         pxw->drawString(150, 350, op);
         cout << " Enter end to quit, or Enter restart to restart" << endl;
         break;
      }
      cout<< "Player 2" << endl;
      restart = p2->playerPlay();
      if(restart == true){
         break;
      }
      if(p2->getStatus()== true){
         pxw->fillRectangle(50, 50, 400, 500, pxw->Red);
         pxw->drawString(250,200,"Game End");
         pxw->drawString(250,250,"P1 wins");
         score = p1->getScore(false);
         hiscore = p1->getScore(true);
         stringstream out;
         out << " Player 1 Current Score: " << score << ", Highest score: "<<hiscore;
         string op;
         getline(out, op);
         pxw->drawString(150, 300, op);
         score = p2->getScore(false);
         hiscore = p2->getScore(true);
         out << " Player 2 Current Score: " << score << ", Highest score: "<<hiscore;
         getline(out, op);
         pxw->drawString(150, 3500, op);
         break;
      }
   }
   }
   if(restart == true){
      cout << "Game Restarted"<<endl;
      p1->reset();
      p2->reset();
      restart = false;
      this->play();
   }
   
}