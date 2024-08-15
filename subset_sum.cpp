/*
Problem statement
You are given an array 'nums' of ‘n’ integers.
Return all subset sums of 'nums' in a non-decreasing order.
Note:
Here subset sum means sum of all elements of a subset of 'nums'. A subset of 'nums' is an array formed by removing some (possibly zero or all) elements of 'nums'.
*/

#include<bits/stdc++.h>
using namespace std;


// Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

// Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
void solve(vector<int> &num,int n,int ind,vector<int> &ds,int s ){
	if(ind==n){
		ds.push_back(s);
		return;
	}

	s+=num[ind];
	solve(num, n, ind+1, ds, s );

	s-=num[ind];
	solve(num, n, ind+1, ds, s);

	;
}


vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	int n=num.size();
	vector<int>ds;
	int s=0;
	solve(num, n, 0, ds, s);
	sort(ds.begin(),ds.end());

	return ds;
}

int main(){
    vector<int> num={1,2,3};
    vector<int> ans=subsetSum(num);
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}