// #include <iostream>
// #include <fstream>
// #include <vector>
// #include "block.h"
// #include "Iblock.h"
// #include "Zblock.h"

// #include "nextBlock.h"
// #include "levelOne.h"
// #include "levelZero.h"
// using namespace std;


// // testing for Block output
// // az comment: should be moved to block file
// // ostream& operator<<( ostream& out, Block* b ) {
// //   vector<vector<shared_ptr<Cell>>> grid = b->getGrid();
// //   for ( unsigned int i = 0; i < grid.size(); i++ ) {
// //     for ( unsigned int j = 0; j < grid[0].size(); j++ ) {
// //       cout << grid[i][j]->getValue();
// //     }
// //     cout << endl;
// //   }
// //   return out;
// // }


// int main() {
//   NextBlock* playerA = new LevelZero{ "biquadris_sequence1.txt", 0 };
//   NextBlock* playerB = new LevelOne{ 1 }

//   vector<char> blocks = playerB->getBlocks();
//   for( auto b : blocks ) { cout << b << " " ;}
//   cout << endl;
//   char a = playerB->blockSelector();
//   std::cout << a << std::endl;
//   a = playerB->blockSelector();
//   std::cout << a << std::endl;
//   a = playerB->blockSelector();
//   std::cout << a << std::endl;
//   a = playerB->blockSelector();
//   std::cout << a << std::endl;
//   a = playerB->blockSelector();
//   std::cout << a << std::endl;
//   a = playerB->blockSelector();
//   std::cout << a << std::endl;
//   a = playerB->blockSelector();
//   std::cout << a << std::endl;
//   a = playerB->blockSelector();
//   std::cout << a << std::endl;

//   std::cout << 12 % 11 << std::endl;


//   // testing for block class
//   // Block* b = new ZBlock();

//   // std::cout << "Original look:" << std::endl;
//   // std::cout << b;// << std::endl;
//   // b->clockwiseRotate();
//   // std::cout << "after rotation:" << std::endl;
//   // std::cout << b;// << std::endl;
//   // b->clockwiseRotate();
//   // std::cout << "after rotation:" << std::endl;
//   // std::cout << b;// << std::endl;
//   // b->clockwiseRotate();
//   // std::cout << "after rotation:" << std::endl;
//   // std::cout << b;// << std::endl;
//   // b->clockwiseRotate();
//   // std::cout << "after rotation:" << std::endl;
//   // std::cout << b;// << std::endl;
//   // b->counterClockwiseRotate();
//   // std::cout << "after counterclockrotation:" << std::endl;
//   // std::cout << b;// << std::endl;

//   // testing for blocks:
  
//   // Block* i = new Iblock{}; 

// }