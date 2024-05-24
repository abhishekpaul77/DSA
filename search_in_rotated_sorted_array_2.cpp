#include<bits/stdc++.h>
using namespace std;

// Binary Search
// Time Complexity: O(logn) or O(n/2) for worst case
// Space Complexity: O(1)
bool searchInARotatedSortedArrayII(vector<int>&arr, int k) {
    // Write your code here.
    int n=arr.size();
     int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
            return true; // Return the index if k is found
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low=low+1;
            high=high-1;
            continue;
        }
        else {
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= k && k <= arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (arr[mid] <= k && k <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }
    return false; 
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