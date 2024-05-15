#include<bits/stdc++.h>
using namespace std;

// Brute force approach
// Time complexity: O(n^2)
// Space complexity: O(1)
int team(vector <int> & skill, int n)
{
    int count=0;
  for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
          if(skill[i]>2*skill[j]){
              count++;
          }
      }
  }
  return count;
}

// Optimized approach
// Time complexity: 2O(nlogn)
// Space complexity: O(n)
// In this approach, we will use the merge sort algorithm to count the number of reverse pairs in the array.
// We will count the number of reverse pairs in the left half of the array, the number of reverse pairs in the right half of the array, and the number of reverse pairs that cross the mid-point of the array.
// The number of reverse pairs that cross the mid-point of the array can be calculated by counting the number of elements in the left half of the array that are greater than twice the elements in the right half of the array.
// We will use the merge function to merge the two halves of the array and count the number of reverse pairs that cross the mid-point of the array.
// The total number of reverse pairs in the array will be the sum of the number of reverse pairs in the left half of the array, the number of reverse pairs in the right half of the array, and the number of reverse pairs that cross the mid-point of the array.
// The merge function will merge the two halves of the array in a sorted manner and count the number of reverse pairs that cross the mid-point of the array.
// The merge function will take the array, the starting index of the left half of the array, the mid-point of the array, and the ending index of the right half of the array as input.
// The merge function will create a temporary array to store the sorted elements of the two halves of the array.
// The merge function will compare the elements of the two halves of the array and store the smaller element in the temporary array.
// The merge function will count the number of reverse pairs that cross the mid-point of the array by counting the number of elements in the left half of the array that are greater than twice the elements in the right half of the array.
// The merge function will transfer the sorted elements from the temporary array to the original array.
// The merge function will return the number of reverse pairs that cross the mid-point of the array.
// The team function will use the merge sort algorithm to count the number of reverse pairs in the array.
// The team function will take the array and the number of elements in the array as input.
// The team function will call the merge function to count the number of reverse pairs in the array.
// The team function will return the total number of reverse pairs in the array.
void merge(vector<int> &arr, int low, int mid, int high) {
  int left = low;
  int right = mid + 1;
  vector<int> temp;

  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }

  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }

  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

int countPairs(vector<int> &arr,int low,int mid,int high){
    int right=mid+1;
    int cnt=0;
    for (int i = low; i <= mid; i++) {
    while (right <= high && arr[i]> 2* arr[right])right++;
        cnt+=(right -(mid + 1));
    }
    return cnt;
}

int mS(vector<int> &arr, int low, int high) {
  int cnt = 0;
  if (low >= high)
    return cnt;
  int mid = (low + high) / 2;

  cnt += mS(arr, low, mid);
  cnt += mS(arr, mid + 1, high);
  cnt += countPairs(arr,low,mid,high);
  merge(arr, low, mid, high);
  return cnt;
}

int team(vector<int> &skill, int n) { return mS(skill, 0, n - 1); }


int main(){
    int n;

    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    return 0;
}