/*
Problem statement
You are given ‘k’ and ‘n’ and you have to do the following:-
Return all possible combinations of arrays whose elements sum is equal to ‘n’, and you can use only elements in the range '1' to '9' inclusive, and you can use each element at most once, and the size of the combination should be exactly ‘k’.
If there is no combination, return an empty array.
It should be noted that the 2-D array should be returned in sorted order, meaning the lexicographically smaller array should come first.
Also, at each index of the 2-D array, the elements present in the array present at that index should be in sorted order.
*/


#include<bits/stdc++.h>
using namespace std;

//Time complexity: O(2^9) because we have 9 choices for each number and we have 9 numbers to choose from. So, the time complexity is O(2^9).
//Space complexity: O(k) because we are using a vector to store the combination of size k. So, the space complexity is O(k). 
void solve(int ind,int sum,vector<vector<int>>& ans,vector<int> &ds,int n,int k){
    if(sum>n) return;
    if(sum==n){
      if (k == 0) {
        ans.push_back(ds);
        return;
      }
      else{   
        return;
    }
    }
    
    if(ind>9) return;

    //pick
    sum-=ind;
    ds.push_back(ind);
    solve(ind+1, sum, ans, ds, n, k-1);

    //not pick
    ds.pop_back();// Backtracking
    sum+=ind;
    solve(ind+1, sum, ans, ds, n, k);

}

vector<vector<int>> combinationSum(int k, int n) {
    // Write Your Code Here
    int sum=0;
    vector<vector<int>> ans;
    vector<int>ds;
    solve(1, sum, ans, ds, n, k);
    return ans;
}

int main(){
    int k,n;
    cin>>k>>n;

    vector<vector<int>> ans = combinationSum(k,n);

    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }



    return 0;
}