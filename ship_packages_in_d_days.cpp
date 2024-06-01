#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n) + O(n) + O(sum-max(arr) + 1)
// Space Complexity: O(1)
int findMax(vector<int> &arr) {
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int maxSum(vector<int> &arr){
    long long sum=0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

int possible(vector<int> &arr, int x){
    int day=1;
    int capacity=0;
    for(int i=0;i<arr.size();i++){
        if( capacity> x){
            day++;
            capacity=arr[i];
        }
        else{
            capacity+=arr[i];
        }
    }
    return day;
}

int leastWeightCapacity_BF(vector<int> &weights, int d)
{
    // Write your code here.
    int maxi=findMax(weights);
    long long sum=maxSum(weights);
    
    for(int i=maxi;i<=sum;i++){
        if(possible(weights, i)<=d){
            return i;
        }
    }
    return -1;
} 

// Optimized Approach: Binary Search
// Time Complexity: O(n) + O(n) + O(log(sum-max(arr) + 1))
// Space Complexity: O(1)
int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int maxi=findMax(weights);
    long long sum=maxSum(weights);
    int ans=0;
    
    int low=maxi,high=sum;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(weights,mid)<=d){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
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