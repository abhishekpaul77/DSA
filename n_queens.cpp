/*
The problem statement is:
Given an NxN chessboard, find a way to place N queens such that no queen can attack any other queen on the chessboard. A queen can attack any other queen if they are in the same row, column, or diagonal.
The image also describes the input and output format for the problem.
Here are the details:
Input format: The first line of input contains an integer N representing the size of the chessboard and the number of queens.
Output format: Each line represents a single configuration. Each configuration is an NxN matrix where 1 represents a queen and 0 represents an empty space.
*/

#include <bits/stdc++.h>
using namespace std;

// First approach
/*
Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O(N! * N) nearly.
Space Complexity: O(N^2)
*/

/*
bool isSafe1(int row, int col, vector<string> board, int n)
{
    // check upper element
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe1(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}
*/

// Second approach
// Intuition: This is the optimization of the issafe function. In the previous issafe function, we need o(N) for a row, o(N) for the column, and o(N) for the diagonal. Here, we will use hashing to maintain a list to check whether that position can be the right one or not.
/*
Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).

Space Complexity: O(N)
*/
void solve(int col, int n, vector<vector<int>> &ans, vector<vector<int>> &board,
           vector<int> &leftR, vector<int> &lowerD, vector<int> &upperD)
{
    if (col == n)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftR[row] == 0 && lowerD[row + col] == 0 && upperD[(n - 1) + (col - row)] == 0)
        {
            board[row][col] = 1;
            leftR[row] = 1;
            lowerD[row + col] = 1;
            upperD[(n - 1) + (col - row)] = 1;
            solve(col + 1, n, ans, board, leftR, lowerD, upperD);
            board[row][col] = 0;
            leftR[row] = 0;
            lowerD[row + col] = 0;
            upperD[(n - 1) + (col - row)] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<int> leftR(n, 0), lowerD(2 * n - 1, 0), upperD(2 * n - 1, 0);
    solve(0, n, ans, board, leftR, lowerD, upperD);
    return ans;
}

int main()
{

    // First approach
    // int n = 4; // we are taking 4*4 grid and 4 queens
    // Solution obj;
    // vector<vector<string>> ans = obj.solveNQueens(n);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << "Arrangement " << i + 1 << "\n";
    //     for (int j = 0; j < ans[0].size(); j++)
    //     {
    //         cout << ans[i][j];
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    // Second approach
    int n = 4; // we are taking 4*4 grid and 4 queens
    vector<vector<int>> ans = solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Arrangement " << i + 1 << "\n";
        for (int j = 0; j < ans[0].size(); j++)
        {
            for (int k = 0; k < ans[0].size(); k++)
            {
                cout << ans[i][j * ans[0].size() + k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}