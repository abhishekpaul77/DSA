/*
Problem statement
You are given a 2D board('N' rows and 'M' columns) of characters and a string 'word'.
Your task is to return true if the given word exists in the grid, else return false. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
*/

#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity:  O(m*n*4^k), where “K” is the length of the word. And we are searching for the letter m*n times in the worst case. Here 4 in 4^k is because at each level of our decision tree we are making 4 recursive calls which equal 4^k in the worst case.
Space Complexity: O(K), Where k is the length of the given words.
*/
bool solve(vector<vector<char>> &board, string &word, int n, int m, int i, int j, int k)
{
    if (k == word.size())
        return true;
    if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k])
        return false;

    board[i][j] = '#';

    bool op1 = solve(board, word, n, m, i + 1, j, k + 1);
    bool op2 = solve(board, word, n, m, i - 1, j, k + 1);
    bool op3 = solve(board, word, n, m, i, j + 1, k + 1);
    bool op4 = solve(board, word, n, m, i, j - 1, k + 1);

    board[i][j] = word[k];

    return op1 || op2 || op3 || op4;
}

bool present(vector<vector<char>> &board, string &word, int n, int m)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                if (solve(board, word, n, m, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    cout << present(board, word, n, m);

    return 0;
}