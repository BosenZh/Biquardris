#include "board.h"
#include "block.h"
#include "cell.h"
#include <memory>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

Board::Board(){
  for(int i = 0; i < 18; i++ ){
    vector<shared_ptr<Cell>> currRow;
    for(int j = 0; j < 11; j++){
      currRow.emplace_back(make_shared<Cell>());
    }
    content.emplace_back(currRow);
  }
  shared_ptr<Cell> bd = make_shared<Cell>();
  bd->setbd(true);
  for(int i = 0; i < 18; i++ ){
    for(int j = 0; j < 11; j++){
      content[i][j]->setX(j);
      content[i][j]->setY(i);
      if(i < 17){
        content[i][j]->setBot(content[i+1][j]);
      } else {
        content[i][j]->setBot(bd);
      }
      if(j > 0){
        content[i][j]->setLeft(content[i][j-1]);
      }
      if(j < 10){
        content[i][j]->setRight(content[i][j+1]);
      }
    }
  }
  vector<shared_ptr<Cell>> leftadd1;
  vector<shared_ptr<Cell>> leftadd2;
  vector<shared_ptr<Cell>> rightadd1;
  vector<shared_ptr<Cell>> rightadd2;
  for(int i = 0; i < 18; i++){
    leftadd1.emplace_back(make_shared<Cell>());
    leftadd2.emplace_back(make_shared<Cell>());
    rightadd1.emplace_back(make_shared<Cell>());
    rightadd2.emplace_back(make_shared<Cell>());
  }
  for(int i = 0; i < 18; i++){
    leftadd1[i]->setbd(true);
    leftadd2[i]->setbd(true);
    rightadd1[i]->setbd(true);
    rightadd2[i]->setbd(true);

    content[i][0]->setLeft(leftadd1[i]);
    content[i][10]->setRight(rightadd1[i]);
    leftadd1[i]->setRight(content[i][0]);
    rightadd1[i]->setLeft(content[i][10]);

    leftadd1[i]->setLeft(leftadd2[i]);
    rightadd1[i]->setRight(rightadd2[i]);
    leftadd2[i]->setRight(leftadd1[i]);
    rightadd2[i]->setLeft(rightadd1[i]);

    rightadd2[i]->setRight(bd);
    leftadd2[i]->setLeft(bd);

    if(i!=17){
      leftadd1[i]->setBot(leftadd1[i+1]);
      leftadd2[i]->setBot(leftadd2[i+1]);
      rightadd1[i]->setBot(rightadd1[i+1]);
      rightadd2[i]->setBot(rightadd2[i+1]);
    } else {
      leftadd1[i]->setBot(bd);
      leftadd2[i]->setBot(bd);
      rightadd1[i]->setBot(bd);
      rightadd2[i]->setBot(bd);
    }
  }
  vector<shared_ptr<Cell>> botadd1;
  vector<shared_ptr<Cell>> botadd2;
  for(int i = 0; i < 11; i++){
    botadd1.emplace_back(make_shared<Cell>());
    botadd2.emplace_back(make_shared<Cell>());
  }
  for(int i = 0; i < 11; i++){
    botadd1[i]->setbd(true);
    botadd2[i]->setbd(true);

    content[17][i]->setBot(botadd1[i]);
    botadd1[i]->setBot(botadd2[i]);
    botadd2[i]->setBot(bd);

    if(i<10){
      botadd1[i]->setRight(botadd1[i+1]);
      botadd2[i]->setRight(botadd2[i+1]);
    } else {
      botadd1[i]->setRight(bd);
      botadd2[i]->setRight(bd);
    }

    if(i>0){
      botadd1[i]->setLeft(botadd1[i-1]);
      botadd2[i]->setLeft(botadd2[i-1]);
    } else {
      botadd1[i]->setLeft(bd);
      botadd2[i]->setLeft(bd);
    }    
  }
}

Board::~Board(){}
vector < vector<shared_ptr< Cell > > >Board::getContent() {
  return content;
}

void Board::insertBlock(Block *B){
  vector<vector<shared_ptr<Cell>>> *myGrid = B->getGridptr();
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++){
      Cell* myC = (myGrid->at(i).at(j)).get();
      if(myC->getLabel() == B->getLab()){
        content[i][j]->cellMove(myGrid->at(i).at(j).get());
      }
      myGrid->at(i).at(j) = content[i][j];
    }
  }
}

void Board::insertMid(Block *B){
  vector<vector<shared_ptr<Cell>>> *myGrid = B->getGridptr();
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++){
      Cell* myC = (myGrid->at(i).at(j)).get();
      if(myC->getLabel() == B->getLab()){
        content[i][j+4]->cellMove(myGrid->at(i).at(j).get());
      }
      myGrid->at(i).at(j) = content[i][j+4];
    }
  }
}

void Board::pushBack(Block *B){
  vector<vector<shared_ptr<Cell>>> *myGrid = B->getGridptr();
  for(int i = 3; i >= 0; i--) {
    for(int j = 3; j >=0 ; j--){
      shared_ptr<Cell> next = myGrid->at(i).at(j)->getBot();
      if(myGrid->at(i).at(j)->getLabel() == B->getLab()){
        if(next->getbd()==true){
          return;
        }
        if(next.get()->getLabel() != B->getLab() && next.get()->getValue()!=" "){
          return;
        }
      }
    }
  }
  for(int i = 3; i >= 0; i--) {
    for(int j = 3; j >=0 ; j--){
      shared_ptr<Cell> next = myGrid->at(i).at(j)->getBot();
      if(myGrid->at(i).at(j)->getLabel() == B->getLab()){
        next.get()->cellMove(myGrid->at(i).at(j).get());
      }
      myGrid->at(i).at(j) = next;
    }
  }    
}


void Board::pushLeft(Block *B){
  vector<vector<shared_ptr<Cell>>> *myGrid = B->getGridptr();
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4 ; j++){
      shared_ptr<Cell> next = ((myGrid->at(i).at(j).get())->getLeft());
      if(myGrid->at(i).at(j)->getLabel() == B->getLab()){
        if(next->getbd()==true){
          return;
        }
        if(next.get()->getLabel() != B->getLab() && next.get()->getValue()!=" "){
          return;
        }
      }
    }
  }
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4 ; j++){
      shared_ptr<Cell> next = ((myGrid->at(i).at(j).get())->getLeft());
      if(myGrid->at(i).at(j)->getLabel() == B->getLab()){
        next.get()->cellMove(myGrid->at(i).at(j).get());
      }
      myGrid->at(i).at(j) = next;
    }
  }  
}


void Board::pushRight(Block *B){
  vector<vector<shared_ptr<Cell>>> *myGrid = B->getGridptr();
  pushrErr error;
  for(int i = 3; i >= 0; i--) {
    for(int j = 3; j >=0 ; j--){
      shared_ptr<Cell> next = ((myGrid->at(i).at(j).get())->getRight());
      if(myGrid->at(i).at(j)->getLabel() == B->getLab()){
        if(next->getbd()==true){
          return;
        }
        if(next.get()->getLabel() != B->getLab() && next.get()->getValue()!=" "){
          return;
        }
      }
    }
  }
  for(int i = 3; i >= 0; i--) {
    for(int j = 3; j >=0 ; j--){
      shared_ptr<Cell> next = ((myGrid->at(i).at(j).get())->getRight());
      if(myGrid->at(i).at(j)->getLabel() == B->getLab()){
        next.get()->cellMove(myGrid->at(i).at(j).get());
      }
      myGrid->at(i).at(j) = next;
    }
  }    
}


int Board::clearLine(){
  vector<int> myln;
   myln.emplace_back(0);
  int acc = 1;
  for(int i = 0; i < 18; i++ ){
    bool clr = true;
    for(int j = 0; j < 11; j++){
      if(content[i][j]->getValue() == " "){
        clr = false;
        break;
     }
    }
    if(clr == true){
      acc++;
      myln.emplace_back(i);
    for(int j = 0; j < 11; j++){
      content[i][j]->unsetValue();
    }
    }
  }
  if( acc > 1){
  for(int o = acc - 1; o > 0; o--){
    for(int i = myln[o]; i > myln[o - 1]; i--){
      if(i == myln[o-1]+acc-o){
        myln[o-1] = i;
        continue;
      }
      int tar = i - acc + o;
      if(tar < 0){
        continue;
      }
      for(int j = 0; j < 11; j++){
        content[i][j]->cellMove(content[tar][j].get());
      }
    }
  }
  }
  return acc - 1;
}


ostream& operator<<( ostream& out, Board* b ) {
  vector< vector<shared_ptr< Cell > > >bcontent = b->getContent();
  for(int i = 0; i < 18; i++ ){
    for(int j = 0; j < 11; j++){
      cout << bcontent[i][j]->getValue();
    }
    cout << "\n";
  }
  return out;
}