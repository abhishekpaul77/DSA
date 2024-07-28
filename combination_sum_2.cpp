/*
Problem statement
You are given an array ‘arr’ of ‘n’ positive integers.
You are also given a positive integer ‘target’.
Your task is to find all unique combinations of elements of array ‘arr’ whose sum is equal to ‘target’. Each number in ‘arr’ may only be used once in the combination.
Elements in each combination must be in non-decreasing order and you need to print all unique combinations in lexicographical order.
*/

#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity:O(2^n*k)

Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

Space Complexity:O(k*x)

Reason: if we have x combinations then space will be x*k where k is the average length of the combination.
*/
void solve(vector<int> &arr, int n, int target, vector<int> &ds, int ind, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = ind; i < n; i++)
    {
        // Skip duplicates
        if (i > ind && arr[i] == arr[i - 1])
            continue;

        // If the current element is greater than the target, break the loop
        if (arr[i] > target)
            break;

        ds.push_back(arr[i]);
        solve(arr, n, target - arr[i], ds, i + 1, ans); // Move to the next element
        ds.pop_back();                                  // Backtrack
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<int> ds;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end()); // Sort to handle duplicates and ensure order
    solve(arr, n, target, ds, 0, ans);
    return ans;
}

int main()
{

    return 0;
}