/*
Problem statement
Ninja is observing an array of ‘N’ numbers and wants to make as many unique subsets as possible. Can you help the Ninja to find all the unique subsets?
Note: Two subsets are called same if they have same set of elements.For example {3,4,1} and {1,4,3} are not unique subsets.
You are given an array ‘ARR’ having N elements. Your task is to print all unique subsets.
*/

#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).

// Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.

void solve(int n, vector<int> &arr,int ind,vector<int> ds,vector<vector<int>> ans){
    if(ind>=n){
        ans.push_back(ds);
        return;
    }
    
    for(int i=ind;i<n;i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        solve(n, arr, i+1, ds, ans);
        ds.pop_back();
    }

}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    sort(ans.begin(),ans.end());
    solve(n, arr, 0, ds, ans);

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>> ans = uniqueSubsets(n, arr);

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    return 0;
}