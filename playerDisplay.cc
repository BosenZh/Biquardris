#include <iostream>
#include <sstream>
#include "playerDisplay.h"
#include "Iblock.h"
#include "Jblock.h"
#include "Lblock.h"
#include "Oblock.h"
#include "Sblock.h"
#include "Tblock.h"
#include "Zblock.h"
#include "Sblock.h"
#include "stblock.h"
#include "levelZero.h"
#include "levelOne.h"
#include "board.h"
#include "cell.h"
#include "block.h"
#include "nextBlock.h"
#include "levelOne.h"
#include "levelZero.h"
#include "level.h"

using namespace std;

void fillrec(Xwindow *pxw, int x, int y, int w, int h, string i){
   if(i == "I"){
      pxw->fillRectangle(x, y, w, h, pxw->Red);
   } else if(i == "J"){
      pxw->fillRectangle(x, y, w, h, pxw->Green);
   } else if(i == "L"){
      pxw->fillRectangle(x, y, w, h, pxw->Cyan);
   } else if(i == "O"){
      pxw->fillRectangle(x, y, w, h, pxw->Yellow);
   } else if(i == "S"){
      pxw->fillRectangle(x, y, w, h, pxw->Magenta);
   } else if(i == "T"){
      pxw->fillRectangle(x, y, w, h, pxw->Orange);
   } else if(i == "Z"){
      pxw->fillRectangle(x, y, w, h, pxw->Brown);
   } else {
      pxw->fillRectangle(x, y, w, h, pxw->Black);
   }
}
shared_ptr<Block> PlayerDisplay::newNext(NextBlock *nextb){
   char i = nextb->blockSelector();
   blknum++;
   if(i == 'I'){
      return make_shared<IBlock>(blknum);
   } else if(i == 'J'){
      return make_shared<JBlock>(blknum);
   } else if(i == 'L'){
      return make_shared<LBlock>(blknum);
   } else if(i == 'O'){
      return make_shared<OBlock>(blknum);
   } else if(i == 'S'){
      return make_shared<SBlock>(blknum);
   } else if(i == 'T'){
      return make_shared<TBlock>(blknum);
   } else {
      return make_shared<ZBlock>(blknum);
   }
}

PlayerDisplay::PlayerDisplay(Xwindow *pxw, Board *boardContent,int level, int playerpos, string scriptFile, bool textOnly):
   pxw{ pxw }, 
   boardContent{ boardContent },
   level{ level }, 
   playerpos{ playerpos }, 
   scriptFile{scriptFile},
   textOnly{ textOnly } {
      CL.reset();
      CL = make_shared<ConcreteLevel>();
      cl=CL.get();
      next = cl->createNextBlock(level, scriptFile);
      currBlk = newNext(next);
      nextBlk = newNext(next);
      currblk = currBlk.get();
      nextblk = nextBlk.get();
      if(level > 3){
         heavy = 1;
      }
   }
   
PlayerDisplay::~PlayerDisplay() {
}

void PlayerDisplay::blockUpdate(){
   vector<vector<shared_ptr<Cell>>> mygrid = currblk->getGrid();
   int x,y;
   bool allclear = true;
   for(int i = 0; i < 4; i ++){
     for(int j = 0; j < 4; j++){
        if(mygrid[i][j]->getLabel() == currblk->getLab()){
           x = mygrid[i][j]->getX() * 15 + playerpos;
           y = mygrid[i][j]->getY() * 15 + 160;
           if(blind){
              bool xclear = (mygrid[i][j]->getX() < 2 ||mygrid[i][j]->getX() > 8);
              bool yclear = (mygrid[i][j]->getY() < 5 ||mygrid[i][j]->getX() > 14);
              allclear = (xclear || yclear);
           }
           if (allclear == true){
              fillrec(pxw, x, y, 15, 15, mygrid[i][j]->getValue());
           }
        }
     }
  }
}

void PlayerDisplay::blockClear(){
   vector<vector<shared_ptr<Cell>>> mygrid = currblk->getGrid();
   int x,y;
   for(int i = 0; i < 4; i ++){
     for(int j = 0; j < 4; j++){
        if(mygrid[i][j]->getLabel() == currblk->getLab()){
           x = mygrid[i][j]->getX() * 15 + playerpos;
           y = mygrid[i][j]->getY() * 15 + 160;
           if(playerpos == 50){
              pxw->fillRectangle(x, y, 15, 15, pxw->Blue);
           }
           if(playerpos == 285){
              pxw->fillRectangle(x, y, 15, 15, pxw->Blue);
           }
        }
     }
  }
}

void PlayerDisplay::prtLevel(){
   stringstream out;
   out << "Level:    " << level;
   string op;
   getline(out, op);
   pxw->fillRectangle(playerpos, 40, 150, 30, pxw->White);
   pxw->drawString(playerpos, 50, op);
}
   
void PlayerDisplay::prtScore(){
   stringstream out;
   out << "Score:    " << score;
   string op;
   getline(out, op);
   pxw->fillRectangle(playerpos, 70, 150, 30, pxw->White);
   pxw->drawString(playerpos, 80, op);
}

int PlayerDisplay::getScore(bool hi){
   if(hi){
      return scorehi;
   } else {
      return score;
   }
}

void PlayerDisplay::prtNext(){
   vector<vector<shared_ptr<Cell>>> mygrid = nextblk->getGrid();
   int x, y;
   pxw->fillRectangle(playerpos, 490, 60, 60, pxw->White);
   for(int i = 0; i < 4; i ++){
     for(int j = 0; j < 4; j++){
        if(mygrid[i][j]->getValue() != " "){
           x = j * 15 + playerpos;
           y = i * 15 + 490;
           fillrec(pxw, x, y, 15, 15, mygrid[i][j]->getValue());
        }
     }
  }
}

void PlayerDisplay::heavier(){
   heavy += 2;
}
void PlayerDisplay::force(char i){
   if(i == 'I'){
      currBlk = make_shared<IBlock>(blknum);
   } else if(i == 'J'){
      currBlk = make_shared<JBlock>(blknum);
   } else if(i == 'L'){
      currBlk = make_shared<LBlock>(blknum);
   } else if(i == 'O'){
      currBlk = make_shared<OBlock>(blknum);
   } else if(i == 'S'){
      currBlk = make_shared<SBlock>(blknum);
   } else if(i == 'T'){
      currBlk = make_shared<TBlock>(blknum);
   } else {
      currBlk = make_shared<ZBlock>(blknum);
   }
   currblk = currBlk.get();
   if(!textOnly){
      blockUpdate();
   }
}

void PlayerDisplay::printB(){
   vector<vector<shared_ptr<Cell>>> mygrid = boardContent->getContent();
   int x,y;
   bool allclear = true;
   for(int i = 0; i < 18; i ++){
     for(int j = 0; j < 11; j++){
        if(mygrid[i][j]->getLabel() != 0 ){
           x = mygrid[i][j]->getX() * 15 + playerpos;
           y = mygrid[i][j]->getY() * 15 + 160;
              bool xclear = (mygrid[i][j]->getX() < 2 ||mygrid[i][j]->getX() > 8);
              bool yclear = (mygrid[i][j]->getY() < 5 ||mygrid[i][j]->getX() > 14);
              allclear = (xclear || yclear);
           if (allclear == true){
              fillrec(pxw, x, y, 15, 15, mygrid[i][j]->getValue());
           }
        }
     }
  }
}

void PlayerDisplay::setblind(){
   blind = true;
   printB();
}


void PlayerDisplay::moveLeft() {
   if(!textOnly){
      blockClear();
      boardContent->pushLeft(currblk);
      blockUpdate();
   } else {
      boardContent->pushLeft(currblk);
   }
}

void PlayerDisplay::moveRight() {
   if(!textOnly){
      blockClear();
      boardContent->pushRight(currblk);
      blockUpdate();
   } else {
      boardContent->pushRight(currblk);
   }
}

void PlayerDisplay::moveDown() {
   if(!textOnly){
      blockClear();
      boardContent->pushBack(currblk);
      blockUpdate();
   } else {
      boardContent->pushBack(currblk);
   }
}

void PlayerDisplay::rotateClock() {
   if(!textOnly){
      blockClear();
      currblk->clockwiseRotate();
      blockUpdate();
   } else {
      currblk->clockwiseRotate();
   }
}

void PlayerDisplay::rotateCounterClock() {
   if(!textOnly){
      blockClear();
      currblk->counterClockwiseRotate();
      blockUpdate();
   } else {
      currblk->counterClockwiseRotate();
   }
}

void PlayerDisplay::drop(){
   endround = checkEndRound();
   while(!endround){
      moveDown();
      endround = checkEndRound();
   }
}

void PlayerDisplay::checkEndGame(){
   vector < vector<shared_ptr< Cell > > > mycontent = boardContent->getContent();
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 11; j++){
         if(mycontent[i][j]->getValue() != " "){
            endGame = true;
            return;
         }
      }
   }
}

bool PlayerDisplay::checkEndRound(){
   vector<vector<shared_ptr<Cell>>> *myGrid = currblk->getGridptr();
   for(int i = 3; i >= 0; i--) {
    for(int j = 3; j >=0 ; j--){
      shared_ptr<Cell> next = myGrid->at(i).at(j)->getBot();
      if(myGrid->at(i).at(j)->getLabel() == currblk->getLab()){
      if(next->getbd() == true){
         return true;
      }
        if((next.get())->getLabel() != 0 && next.get()->getLabel()!= currblk->getLab()){
           return true;
        }
      }
    }
  }  
  return false;
}

void setTime(int *t){
   char i;
   string tm;
   while(true){
      i = getchar();
      if(i != ' '){
         ungetc(i, stdin);
         break;
      }
   }
   while(true){
      tm = getchar();
      if(isdigit(tm[0])){
         *t = *t * 10 + stoi(tm);
      } else {
         ungetc(tm[0], stdin);
         break;
      }
   }
   *t = max(*t, 1);
}

bool PlayerDisplay::enterCmd(){
   string cmdStream;
   int time = 0;
  while(!endround && cin >> cmdStream) {
     time = 0;
     cout << "please enter your command" <<endl;
     cout << "enter an int after a moving command will repeat this command multiple times"<<endl;
     if(cin.eof()){
        endGame = true;
        return false;
     }
     if (cmdStream == "left"){
        setTime(&time);
        for(int i = 0; i < time; i++){
         moveLeft();
        }
     } else if (cmdStream == "right"){
        setTime(&time);
        for(int i = 0; i < time; i++){
         moveRight();
        }
     } else if (cmdStream == "down"){
        setTime(&time);
        for(int i = 0; i < time; i++){
         moveDown();
        }
     } else if (cmdStream == "clockwise"){
        setTime(&time);
        for(int i = 0; i < time; i++){
         rotateClock();
        }
     } else if (cmdStream == "counterclockwise"){
        setTime(&time);
        for(int i = 0; i < time; i++){
         rotateCounterClock();
        }
     } else if (cmdStream == "drop"){
        drop();
     } else if (cmdStream == "levelup"){
        if(lvDown > 0){
           lvDown -= 1;
        } else {
           lvUp++;
        }
        continue;
     } else if (cmdStream == "leveldown"){
        if(lvUp > 0){
           lvUp -= 1;
        } else {
           lvDown++;
        }
        continue;
     } else if (cmdStream == "norandom"){
        cin >> newScriptFile;
        if(rand && level >= 3){
         nexttemp = next;
         next= cl->createNextBlock(0, newScriptFile); 
         nextBlk = newNext(next);
         nextblk = nextBlk.get();
         if(!textOnly){
            prtNext();
         }
         rand = false;
        }
        continue;
     } else if (cmdStream == "random"){
        cin >> newScriptFile;
        if(rand == false && level >= 3){
           rand = true;
         next = nexttemp;
        }
        continue;
     } else if (cmdStream == "I"){
        nextBlk = make_shared<IBlock>(blknum);
        blknum++;
        nextblk = nextBlk.get();
        if(!textOnly){
            prtNext();
         }
        continue;
     } else if (cmdStream == "J"){
        nextBlk = make_shared<JBlock>(blknum);
        blknum++;
        nextblk = nextBlk.get();
        if(!textOnly){
            prtNext();
         }
        continue;
     } else if (cmdStream == "L"){
        nextBlk = make_shared<LBlock>(blknum);
        blknum++;
        nextblk = nextBlk.get();
        if(!textOnly){
            prtNext();
         }
        continue;
     } else if (cmdStream == "O"){
        nextBlk = make_shared<OBlock>(blknum);
        blknum++;
        nextblk = nextBlk.get();
        if(!textOnly){
            prtNext();
         }
        continue;
     } else if (cmdStream == "S"){
        nextBlk = make_shared<SBlock>(blknum);
        blknum++;
        nextblk = nextBlk.get();
        if(!textOnly){
            prtNext();
         }
        continue;
     } else if (cmdStream == "T"){
        nextBlk = make_shared<TBlock>(blknum);
        blknum++;
        nextblk = nextBlk.get();
        if(!textOnly){
            prtNext();
         }
        continue;
     } else if (cmdStream == "Z"){
        nextBlk = make_shared<ZBlock>(blknum);
        blknum++;
        nextblk = nextBlk.get();
        if(!textOnly){
            prtNext();
         }
        continue;
     } else if( cmdStream == "restart"){
        endGame = true;
        return true;
     } else {
        continue;
     }
   if(textOnly){
      textDisplay();
   }
     endround = checkEndRound();
   if(!endround){
      for(int i = 0; i < heavy; i++){
         moveDown();
      }
   } else {
      break;
   }
  }
  return false;
}

void PlayerDisplay::playerQuickplay(){
   if(!textOnly){
      blockUpdate();
   }
   bool end = enterCmd();
   clrLine();
   endround = true;
   if(lvUp > 0 ){
     for(int i = 0; i < lvUp; i++){
        if(level < 4){
           level++;
        } else {
           break;
        }   
     }
     lvUp = 0;
     if(!textOnly){
         prtLevel();
     }
   }
   if(lvDown > 0 ){
     for(int i = 0; i < lvDown; i++){
        if(level > 0){
           level--;
        } else {
           break;
        }   
     }
     lvDown = 0;
     if(!textOnly){
         prtLevel();
     }
   }
   endround = false;
}




void PlayerDisplay::clrLine(){
   int res = boardContent->clearLine();
   if(level == 4){
      if(res == 0){
         fivetracker ++;
      } else {
         fivetracker = 0;
      }
      if(fivetracker >= 5){
         fivetracker = 0;
         blknum++;
         currBlk = make_shared<stBlock>(blknum);
         currblk = currBlk.get();
         boardContent->insertMid(currblk);
         endround = false;
         playerQuickplay();
         fivetracker = 0;
      }
   }
   if(res > 0 && !textOnly){
      cout << "please be patient for the line cleaning process" << endl;
      score += res * (level + 1) * (level + 1);
      if(scorehi < score){
         scorehi = score;
      }
      if(res >= 2){
         bool sc = true;
         while( sc){
         cout<< " please enter your special command: blind, heavy, force i";
         string spCommand;
         cin >> spCommand;
         char sp;
         if(spCommand == "blind"){
            opp->setblind();
            sc = false;
         } else if(spCommand == "heavy"){
            opp->heavier();
            sc = false;
         } else if(spCommand == "force"){
            cin >>sp;
            opp->force(sp);
         }
         }
      }
      vector < vector<shared_ptr< Cell > > > mycont = boardContent->getContent();
      bool allclear = true;
      for(int i = 0; i < 18; i++){
         for(int j = 0; j < 11; j++){
            if(blind){
              bool xclear = (mycont[i][j]->getX() < 2 ||mycont[i][j]->getX() > 8);
              bool yclear = (mycont[i][j]->getY() < 5 ||mycont[i][j]->getY() > 14);
              allclear = (xclear || yclear);
           }
            if(mycont[i][j]->getValue() != " " && allclear){
               fillrec(pxw, playerpos + j * 15, i * 15 + 160, 15, 15, mycont[i][j]->getValue());
            } else {
               if(playerpos == 50){
                  pxw->fillRectangle(playerpos+j * 15, i * 15 + 160, 15, 15, pxw->Blue);
               } else {
                  pxw->fillRectangle(playerpos+j * 15, i * 15 + 160, 15, 15, pxw->Blue);    
               }
            }
         }
      }
   }
}




bool PlayerDisplay::playerPlay(){
cout << "commands include left, right, down, clockwise, counterclockwise, drop, levelup, leveldown, norandom, random, sequence file, restart, or any block type "<<endl;
  bool end = enterCmd();
  if(end){
     return true;
  }
  clrLine();
  endround = true;
  if(lvUp > 0 ){
     for(int i = 0; i < lvUp; i++){
        if(level < 4){
           level++;
        } else {
           break;
        }   
     }
     lvUp = 0;
     if(!textOnly){
         prtLevel();
     }
  }
  if(lvDown > 0 ){
     for(int i = 0; i < lvDown; i++){
        if(level > 0){
           level--;
        } else {
           break;
        }   
     }
     lvDown = 0;
     if(!textOnly){
         prtLevel();
     }
  }
  checkEndGame();
  if(endGame != true){
   if(!textOnly){
         prtScore();
     }
   currBlk = nextBlk;
   nextBlk = newNext(next);
   currblk = currBlk.get();
   boardContent->insertBlock(currblk);
   if(!textOnly){
      blockUpdate();
   }
   nextblk = nextBlk.get();
   if(!textOnly){
      prtNext();
      }
  }
  endround = false;
  return false;
}

bool PlayerDisplay::getStatus(){
   return endGame;
}

void PlayerDisplay::setSeed(int currseed){
   seed = currseed;
}

void PlayerDisplay::initialDP(){
   boardContent->insertBlock(currblk);
   if(textOnly == true){
      textDisplay();
      return;
   }
   if(!textOnly){
      blockUpdate();
   }
   if(!textOnly){
      prtNext();
   }
}


void PlayerDisplay::reset(){
  newbd = make_shared<Board>();
  boardContent = newbd.get();
  cl = make_shared<ConcreteLevel>().get();
  next = cl->createNextBlock(level, scriptFile);
  currBlk = newNext(next);
  nextBlk = newNext(next);
  currblk = currBlk.get();
  nextblk = nextBlk.get();
  heavy = 0;
  if(level > 3){
     heavy = 1;
     }
  newScriptFile = " ";
  blknum = 1;
  //Score score;
  textOnly= false;
  endround = false;  
  score = 0;
  endGame = false;
  lvUp = 0;
  lvDown = 0;
  fivetracker = 0;
  rand = true;
  blind = false;
}

void PlayerDisplay::setTextOnly(bool txtOnly){
   textOnly = txtOnly;
}

void PlayerDisplay::setOpponent(PlayerDisplay *opponent){
   opp = opponent;
}

void PlayerDisplay::prtBlock(){
   vector<vector<shared_ptr<Cell>>> grid = nextblk->getGrid();
   for ( unsigned int i = 0; i < grid.size(); i++ ) {
    for ( unsigned int j = 0; j < grid[0].size(); j++ ) {
      cout << grid[i][j]->getValue();
    }
    cout << endl;
  }
}

void PlayerDisplay::prtBlind(){
  vector< vector<shared_ptr< Cell > > >bcontent = boardContent->getContent();
  for(int i = 0; i < 18; i++ ){
    for(int j = 0; j < 11; j++){
       if(j < 2 || j > 8 || i < 5 || i > 14){
          cout << "?";
       } else {
          cout << bcontent[i][j]->getValue();
       }
    }
    cout << "\n";
  }
}

void PlayerDisplay::textDisplay(){
   int playernum = 0;
   if(playerpos > 50){
      playernum = 1;
   }
   cout << "Player    " << playernum  <<endl;
   cout << "Level:    " << level <<endl;
   cout << "Score:    " << score <<endl;
   cout << "-----------" << endl;
   if(blind){
      prtBlind();
   } else {
      cout << boardContent;
   }
   cout << "-----------" << endl;
   cout << "Next:"<<endl;
   prtBlock();
}