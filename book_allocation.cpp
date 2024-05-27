#include<bits/stdc++.h>
using namespace std;

// Problem: Book Allocation
// Problem Statement: In this problem, we are given the number of pages in n different books and we have to allocate the books to m students such that the maximum number of pages allocated to a student is minimized.
// We have to find the maximum number of pages allocated to a student.


// Brute force approach
// Time complexity: O(high - low)*n
// Space complexity: O(1)
int countStudents(vector<int>& arr, int pages){
    int student=1,maxPage=0;

    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] + maxPage <= pages){
          maxPage+=arr[i];
      }
      else{
          student++;
          maxPage=arr[i];
      }
    }
    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
     if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
   for (int pages = low; pages <= high; pages++) {
        if (countStudents(arr, pages) == m) {
            return pages;
        }
    }
    return low;
}

// Optimized approach: Binary search
// Time complexity: O(n) * O(log2(high - low))\
// Space complexity: O(1)
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
     if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low<=high){
      int mid=(low + high)/2;
        if(countStudents(arr, mid)<=m){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
  }
  return low;
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