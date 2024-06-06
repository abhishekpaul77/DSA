#include<bits/stdc++.h>
using namespace std;

// Problem: Painters Partition
// Problem Statement: In this problem, we are given the number of painters and the time taken by each painter to paint the board.
// We have to find the minimum time required to paint the board such that each painter paints the board continuously.
// We have to find the minimum time required to paint the board.

// Same concept can be applied for largest subarray sum minimization problem.
// Where we have to find the maximum sum of the subarray such that the number of subarrays is minimized.
// We have to find the maximum sum of the subarray.


// Binaru search approach
// Time complexity: O(n) * O(log2(high - low))
// Space complexity: O(1)
int countPainters(vector<int>& arr, int pages){
    int painter=1,maxPage=0;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] + maxPage <= pages){
          maxPage+=arr[i];
      }
      else{
          painter++;
          maxPage=arr[i];
      }
    }
    return painter;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
     if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low<=high){
      int mid=(low + high)/2;
        if(countpainters(arr, mid)<=m){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
  }
  return low;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    return findPages(boards, boards.size(), k);
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

//