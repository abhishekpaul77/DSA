#include<bits/stdc++.h>
using namespace std;

//Binary search is a searching algorithm that finds the position of a target value within a sorted array.
//Binary search compares the target value to the middle element of the array.
//If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found.
//If the search ends with the remaining half being empty, the target is not in the array.

// Overflow Case: If the sum of low and high is greater than the maximum positive int value (2^31 - 1), then it will cause integer overflow.
// To avoid integer overflow, we can use low + (high - low) / 2 instead of (low + high) / 2.

//Iterative approach
//Time complexity: O(n^2)
//Space complexity: O(1)
int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
//Recursive approach
//Time complexity: O(log2n)
//Space complexity: O(logn)
int bs(vector<int> &a,int low,int high, int target){
    if(low >high) return -1;
    int mid=(low+high)/2;
    if(a[mid]==target)return mid;
    else if(a[mid]<target){
       return bs(a, mid+1, high, target);
    }
    else{
       return  bs(a, low, mid-1, target);
    }
    
}


int search(vector<int> &nums, int target) {
    // Write your code here.
int n = nums.size(); //size of the array
bs(nums, 0, n-1, target);
    
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