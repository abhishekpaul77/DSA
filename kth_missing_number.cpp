#include<bits/stdc++.h>
using namespace std;

// Brute force approach
// Time complexity: O(n)
// Space complexity: O(1)
// In this approach, we will iterate through the array and check if the element is less than or equal to k. If it is, we will increment k by 1. If the element is greater than k, we will break out of the loop and return k.
int missingK(vector < int > vec, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (vec[i] <= k) k++; //shifting k
        else break;
    }
    return k;
}

// Optimized approach: Binary search
// Time complexity: O(log n)
// Space complexity: O(1)
// In this approach, we will use binary search to find the kth missing number. We will initialize low to 0 and high to n-1. We will then calculate the mid value and find the number of missing elements before the mid element. If the number of missing elements is less than k, we will update low to mid+1. If the number of missing elements is greater than or equal to k, we will update high to mid-1. We will continue this process until low is less than or equal to high. Finally, we will return k+high+1.
// The reason behind returning k+high+1 is that the number of missing elements before the high index is high. So, the kth missing number will be k+high+1.
// To represent the same in formula, ans is supposed to be vec[high] + more, where more = k - missing.
// So, ans = vec[high] + k - (vec[high] - high - 1) = k + high + 1.
int missingK(vector < int > vec, int n, int k) {
    // Write your code here.
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low + high)/2;
        int missing=vec[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return k+high+1;
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