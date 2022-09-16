#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include "block.h"
#include "Iblock.h"
#include "Lblock.h"
#include "Zblock.h"
#include "Tblock.h"
#include "cell.h"
#include "board.h"
#include "nextBlock.h"
#include "levelOne.h"
#include "levelZero.h"
#include "playerDisplay.h"
#include "display.h"
#include "window.h"
using namespace std;


// testing for Block output
// az comment: should be moved to block file



int main( int argc, char* argv[] ) {
  int startLevelp1 = 0;
  int startLevelp2 = 0;
  string file1 = "sequence1.txt";
  string file2 = "sequence2.txt";
  bool text = false;
  // srand(time(0));
  // command line argument
  if ( argc != 1 ) {
    // -text
    for( int i = 0; i < argc; i++ ) {
      if ( string(argv[i]) == "-text" ) { 
        text = true; 
        break;
      }
    }
    // -seed XXX
    bool seedSet = false;
    for( int i = 0; i < argc; i++ ) {
      if ( string(argv[i]) == "-seed" ) { 
        if ( i + 1 >= argc ) { 
          cerr << "no seed after -seed" << endl;
          throw; 
        }
        string s = string(argv[i + 1]);
        stringstream ss{ s };
        int seed;
        ss >> seed;
        srand(seed);
        seedSet = true;
      }
    }
    if ( seedSet == false ) { srand(time(0)); }
    // -scriptfile1 xxx 
    for( int i = 0; i < argc; i++ ) {
      if ( string(argv[i]) == "-scriptfile1" ) { 
        if ( i + 1 >= argc ) { 
          cerr << "no scriptfile after -scriptfile1" << endl;
          throw; 
        }
        file1 = string(argv[i + 1]);
      }
    }
    // -scriptfile2 xxx 
    for( int i = 0; i < argc; i++ ) {
      if ( string(argv[i]) == "-scriptfile2" ) { 
        if ( i + 1 >= argc ) { 
          cerr << "no scriptfile after -scriptfile2" << endl;
          throw; 
        }
        file2 = string(argv[i + 1]);
      }
    }
    // -startlevel n
    for( int i = 0; i < argc; i++ ) {
      if ( string(argv[i]) == "-startlevel" ) { 
        if ( i + 1 >= argc ) { 
          cerr << "no startlevel after -startlevel" << endl;
          throw; 
        }
        string s = string(argv[i + 1]);
        stringstream ss{ s };
        int l;
        ss >> l;
        startLevelp1 = l;
        startLevelp2 = l;
      }
    }

    

  }

  while(true) {
    cout << "enter start to begin" <<endl;
    string cmdLine;
    cin >> cmdLine;
    /*if(cmdLine == "text") {
      cout << "Text Mode";
      text = true;
    } else if(cmdLine == "seed"){
      cout << "Seed Set" << endl;
      int sd = 0;
      cin >> sd;
      srand(sd);
    } else if(cmdLine == "scriptfile1"){
      cin >> file1;
      cout << "Default File Set" << endl;
    } else if(cmdLine == "scriptfile2"){
      cin >> file2;
      cout << "Default File Set" << endl;
    } else if(cmdLine == "startlevelp1"){
      cin >> startLevelp1;
      cout << "Player 1 Level = " << startLevelp1 << endl;
    } else if(cmdLine == "startlevelp2"){
      cin >> startLevelp2;
      cout << "Player 2 Level = " << startLevelp2;
    } else if(cmdLine == "startlevel"){
      cin >> startLevelp1;
      startLevelp2 = startLevelp1;
      cout << "Player 1 Level = " << startLevelp1 << endl;
      cout << "Player 2 Level = " << startLevelp2 << endl;
    } else*/
    if(cmdLine == "start"){
      break;
      cout << "Game Start" <<endl;
    }
  }
  shared_ptr<Board> p1 = make_shared<Board>();
  shared_ptr<Board> p2 = make_shared<Board>();
  Board *p1bd = p1.get();
  Board *p2bd = p2.get();
  shared_ptr<Xwindow> PXW = make_shared<Xwindow>(500, 600);
  Xwindow * pxw = PXW.get();
  shared_ptr<PlayerDisplay> Player1 = make_shared<PlayerDisplay>(pxw, p1bd, startLevelp1, 50, file1, text);
  shared_ptr<PlayerDisplay> Player2 = make_shared<PlayerDisplay>(pxw, p2bd, startLevelp2, 285, file2, text);
  PlayerDisplay *player1 = Player1.get();
  PlayerDisplay *player2 = Player2.get();
  shared_ptr<GameDisplay> dp= make_shared<GameDisplay>(pxw, player1, player2, text);
  dp->play();

}