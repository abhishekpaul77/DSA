/*
Problem statement
You are given an array 'ARR' of 'N' distinct positive integers. You are also given a non-negative integer 'B'.
Your task is to return all unique combinations in the array whose sum equals 'B'. A number can be chosen any number of times from the array 'ARR'.
Elements in each combination must be in non-decreasing order.
*/

#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(2^t * k) where t is the number of times we choose the particular element and k is the average length of the combination
// Space complexity: O(k) * x where x is the number of combinations and k is the average length of the combination
void solve(vector<int> &ARR, int B, vector<int> &ds, int ind,
           vector<vector<int>> &ans)
{

    if (ind >= ARR.size())
    {
        if (B == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    // Pick the current element
    if (ARR[ind] <= B)
    {
        ds.push_back(ARR[ind]);
        solve(ARR, B - ARR[ind], ds, ind, ans);
        ds.pop_back();
    }

    // Not pick the current element and move to the next
    solve(ARR, B, ds, ind + 1, ans);
}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    vector<int> ds;
    vector<vector<int>> ans;
    sort(ARR.begin(), ARR.end());
    solve(ARR, B, ds, 0, ans);
    return ans;
}

int main()
{

    vector<int> ARR = {2, 3, 6, 7};
    int B = 7;
    vector<vector<int>> res = combSum(ARR, B);

    for (auto x : res)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}