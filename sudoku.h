#pragma once
#include <iostream>



class Sudoku
{
private:
        int arr[9][9];

public:
        Sudoku();
        Sudoku(int *arr, int n);
        Sudoku(const Sudoku &Sud);
        ~Sudoku();

        void enterDigits();
        bool solve();
        void print();
};
