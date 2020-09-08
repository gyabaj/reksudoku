#include "sudoku.h"


        Sudoku::Sudoku()
        {
                for (int i = 0; i < 9; ++i)
                        for (int j = 0; j < 9; ++j)
                                arr[i][j] = 0;
        }
        Sudoku::Sudoku(int *arr,int n)
        {
                if(n == 9)
                {
                   for (int i = 0; i < n; ++i)
                         for (int j = 0; j < n; ++j)
                                this->arr[i][j] = *(arr + j + (n * i));
                }
        }
        Sudoku::Sudoku(const Sudoku &Sud)
        {
                for (int i = 0; i < 9; ++i)
                        for (int j = 0; j < 9; ++j)
                                this->arr[i][j] = Sud.arr[i][j];
        }
        Sudoku::~Sudoku() {}
        void Sudoku::enterDigits()
        {
                for (int i = 0; i < 9; ++i)
                        for (int j = 0; j < 9; ++j)
                                std::cin >> arr[i][j];
        }

        bool Sudoku::solve()
        {
                bool ThisValueIsOk = false;
                for (int i = 0; i < 9; ++i)
                        for (int j = 0; j < 9; ++j)
                                if (!arr[i][j])
                                {
                                        for (int value = 1; value < 10; ++value)
                                        {
                                                bool ValueCanBe = true;
                                                for (int a = 0; a < 9; ++a)
                                                        if (arr[a][j] == value || arr[i][a] == value ||
                                                                arr[i / 3 * 3 + (a % 3)][j / 3 * 3 + (a / 3)] == value)
                                                                       ValueCanBe = false;

                                                if (ValueCanBe)
                                                {
                                                        ThisValueIsOk = true;
                                                        arr[i][j] = value;
                                                        if (solve())
                                                                return true;
                                                        else
                                                                ThisValueIsOk = false;
                                                }
                                        }

                                        if (!ThisValueIsOk)
                                        {
                                                arr[i][j] = 0;
                                                return false;
                                        }
                                }

                return true;

        }

        void Sudoku::print()
        {
                for (int i = 0; i < 9; ++i)
                {
                        if (!(i % 3))
                                std::cout << "\n";
                        for (int j = 0; j < 9; ++j)
                        {
                          if (!(j % 3))
                            std::cout << ' ';
			  std::cout << arr[i][j];
		       	}
                        std::cout << "\n";
                }
        }
