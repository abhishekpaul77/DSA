/*
Problem statement
You are given an array ‘arr’ of ‘N’ distinct integers. Your task is to print all the non-empty subsets of the array.
Note: elements inside each subset should be sorted in increasing order. But you can print the subsets in any order, you don’t have to specifically sort them.
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &arr, int n, vector<int> &ds)
{

    if (ind == n)
    {

        for (auto i : ds)

            cout << i << " ";

        cout << endl;

        return;
    }

    // Pick the element

    ds.push_back(arr[ind]);

    solve(ind + 1, arr, n, ds);

    // Not pick the element

    ds.pop_back();

    solve(ind + 1, arr, n, ds);
}

void printAllSubsets(int n, vector<int> &arr)
{

    // Write your code here

    vector<int> ds;

    solve(0, arr, n, ds);
}

int main()
{

    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    printAllSubsets(n, arr);

    return 0;
}