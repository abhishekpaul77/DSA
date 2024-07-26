/*
Problem statement
You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. Otherwise, return false.
For Example
'N' = 3, 'K' = 5, 'A' = [1, 2, 3].
Subset [2, 3] has sum equal to 'K'.
So our answer is True.
*/

#include<bits/stdc++.h>
using namespace std;


//Just like count subsets problem, the issue here is that it doesnt work for large inputs. So we need to use DP to solve this problem.
//This is recursive approach which uses 2^n time complexity which is not efficient, so we use DP to solve this problem. Which I will learn later in the course.
bool solve(vector<int>& arr, vector<int>& ds, int ind, int k, int s) {
    if (ind >= arr.size()) {
        if (s == k) {
            return true;
        } else {
            return false;
        }
    }
    // Pick
    ds.push_back(arr[ind]);
    s += arr[ind];
    if (solve(arr, ds, ind + 1, k, s) == true) return true;

    // Not pick
    ds.pop_back();
    s -= arr[ind];
    if (solve(arr, ds, ind + 1, k, s) == true) return true; 

    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
    // Write your code here
    int sum = 0;
    vector<int> ds;
    return solve(a, ds, 0, k, sum);
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << isSubsetPresent(n, k, a) << endl;

    return 0;
}