#include<bits/stdc++.h>
using namespace std;

// Brute force approach
// Time complexity: O(n)
// Space complexity: O(1)
int findPeakElement_BF(vector<int> &arr) {
    // Write your code her
    int n=arr.size();
    for(int i=0;i<n;i++){
        if((i==0 || arr[i-1]<arr[i]) && (i==n-1 || arr[i]>arr[i+1])){
            return i;
        }
    }
}

// Binary search approach
// Time complexity: O(log2n)
// Space complexity: O(1)
int findPeakElement(vector<int> &arr) {
    // Write your code her
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
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