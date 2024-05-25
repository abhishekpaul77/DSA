#include<bits/stdc++.h>
using namespace std;
// Problem: Aggressive Cows
// Problem Statement: In this problem, we are given the positions of the stalls and we have to place the cows in the stalls such that the minimum distance between the cows is maximized.
// We have to find the maximum minimum distance between the cows.


// Brute force approach
// Time complexity: O(max-min)*n
// Space complexity: O(1)
// In this approach, we will check for each possible distance between the cows and then check if it is possible to place the cows at that distance or not.
// If it is possible, then we will continue to check for the next distance, else we will return the previous distance.
// We will sort the stalls and then check for each possible distance between the cows.
// We will check if it is possible to place the cows at that distance or not.
// If it is possible, then we will continue to check for the next distance, else we will return the previous distance.

bool possible(vector<int> &a, int cows,int dist){
    int cntCows=1;
    int last=a[0];
    for(int i=0;i<a.size();i++){
        if(a[i]-last>=dist){
            cntCows++;
            last=a[i];
        }
    }
    if(cntCows>=cows){
        return true;
    }
    else{
        return false;
    }
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int limit=stalls[n-1]-stalls[0];
    for(int i=1;i<=limit;i++){
        if(possible(stalls, k, i)==true){
            continue;
        }
        else{
            return i-1;
        }
    }
    return limit;
}

// Optimized approach: Binary search
// Time complexity: O(nlogn) + O(nlog(max-min))
// Space complexity: O(1)
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int limit=stalls[n-1]-stalls[0];
   int low=1,high=limit;
   while(low<=high){
       int mid=(low + high)/2;
       if(possible(stalls, k, mid)==true){
           low=mid+1;
       }
       else{
           high=mid-1;
       }
   }
   return high;
}

int main(){
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    return 0;
}