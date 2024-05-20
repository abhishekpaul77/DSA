#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n) + O(n) + O(max(arr) * n), which simplifies to O(max(arr) * n).
// Space Complexity: O(1)
int findMax(vector<int> &arr) {
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}


int div(vector<int> &arr, int x) {
  long long sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    sum += ceil((double)(arr[i]) / (double)(x));
  }
  return sum;
}

int smallestDivisor_BF(vector<int> &arr, int limit) {
  // Write your code here.
  int maxi = findMax(arr);
// int maxi = *max_element(arr.begin(), arr.end());
  int ans = 0;
  for (int i = 1; i <= maxi; i++) {
    if (div(arr, i)<=limit){
		return i;
	}
  }
  return -1;
} 

// Optimized Approach: Binary Search
// Time Complexity: O(n) + O(n) + O(log(max_val) * n), which simplifies to O(n * log(max_val)).
// Space Complexity: O(1)
int smallestDivisor(vector<int> &arr, int limit) {
  // Write your code here.
  int maxi = findMax(arr);
  int ans=-1;
// int maxi = *max_element(arr.begin(), arr.end());
	int low=1,high=maxi;
	while(low<=high){
		int mid=(low + high)/2;
		if(div(arr,mid)<=limit){
			ans= mid;
			high=mid-1;
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