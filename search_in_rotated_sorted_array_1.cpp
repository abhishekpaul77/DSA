#include<bits/stdc++.h>
using namespace std;

// Bruteforce approach
// Time complexity: O(n)
// Space complexity: O(1)
int search_BF(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int ans=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            ans=i;
        }
    }
    return ans;
}

// Optimized approach
// Time complexity: O(logn)
// Space complexity: O(1)
int search(vector<int> &arr, int n, int k) {
  // Write your code here.
  // Return the position of K in ARR else return -1.
  int low = 0, high = n - 1;
  int ans = -1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == k)
      ans = mid;
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