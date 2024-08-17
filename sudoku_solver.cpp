/*
Problem statement
You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle. The empty cells of the Sudoku are filled with zeros, and the rest of the cells are filled with integers from 1 to 9. Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.

Note:
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.

You can also assume that there will be only one sudoku solution for the given matrix.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.
Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.
*/
bool isPossible(vector<vector<int>> &board, int row, int col, int k)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == k)
            return false;
        if (board[i][col] == k)
            return false;
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == k)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isPossible(board, i, j, k))
                    {
                        board[i][j] = k;
                        if (solve(board) == true)
                            return true;
                        else
                            board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    solve(sudoku);
}

int main()
{
    vector<vector<int>> sudoku = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                                  {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                  {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                  {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                  {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                  {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                  {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                  {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                  {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    solveSudoku(sudoku);

    for (int i = 0; i < sudoku.size(); i++)
    {
        for (int j = 0; j < sudoku[0].size(); j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}