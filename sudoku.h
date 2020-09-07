#include <iostream>



class Sudoku
{
private:
        int arr[9][9];

public:
        Sudoku();
        Sudoku(int arr[9][9]);
        Sudoku(const Sudoku &Sud);
        ~Sudoku();

        void enterDigits();
        bool solve();
        void print();
};
