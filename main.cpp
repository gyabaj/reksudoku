#include "sudoku.h"

int main()
{
   Sudoku mySudoku{};
   mySudoku.enterDigits();
   mySudoku.solve();
   mySudoku.print();
}
