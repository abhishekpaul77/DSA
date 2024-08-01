// Problem statement
// You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
// Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
// Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.

#include<bits/stdc++.h>
using namespace std;


// This is recursive approach which uses 2^n time complexity which is not efficient, so we use DP to solve this problem. Which I will learn later in the course.
//Time complexity: O(2^n)
int solve(vector<int>& arr,int ind,int k,int s){
	if(ind>=arr.size()){
		if(s==k){
			return 1;
		}
		else return 0;
	}
	//Pick
	s+=arr[ind];
	int l=solve(arr, ind+1, k, s);

	//Not pick
	s-=arr[ind];
	int r=solve(arr, ind+1, k, s);

	return l+r;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int s=0;
	return solve(arr, 0, k, s);
	
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<findWays(arr,k);
    return 0;
}