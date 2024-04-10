#include<bits/stdc++.h>
using namespace std;

// Brute force approach
// Time complexity: O(n^3)
long long maxSubarraySum(vector<int> arr, int n)
{
    long long max_sum = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            long long sum = 0;
            for(int k = i; k <= j; k++) { 
                sum += arr[k]; 
            }
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

// Better approach
// Time complexity: O(n^2)
long long maxSubarraySum_better(vector<int> arr, int n)
{
    long long max_sum = INT_MIN;
    for(int i = 0; i < n; i++){
            long long sum = 0;
        for(int j = i; j < n; j++){
                sum += arr[j]; 
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

// Kadane's algorithm
// Time complexity: O(n)
// Space complexity: O(1)
// This algorithm is used to find the maximum subarray sum in an array in O(n) time complexity. 
// It is based on the idea that if the sum of the subarray becomes negative, then it is better to start the subarray from the next element.
// The algorithm maintains two variables, max_sum and current_sum, to keep track of the maximum subarray sum found so far and the sum of the current subarray, respectively.
// The algorithm iterates through the array and updates the current_sum by adding the current element to it. If the current_sum becomes negative, it is reset to 0.
// The max_sum is updated with the maximum of max_sum and current_sum at each iteration. 
// At the end of the iteration, max_sum will contain the maximum subarray sum. 


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