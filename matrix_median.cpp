#include<bits/stdc++.h>
using namespace std;

// Problem: Given a matrix of size N x M. For each row the elements are sorted in ascending order, and for each column the elements are also sorted in ascending order. Find the median of the matrix.

// Optimal Approach: Using Binary Search
// Time Complexity: O(row*log col) since the upper bound function takes log c time.
// Space Complexity: O(1)
// In this approach, we will first find the minimum and maximum element in the matrix. Then we will apply binary search on the range of minimum and maximum element. We will find the mid element and then we will find the number of elements less than or equal to mid element. If the number of elements less than or equal to mid element is less than or equal to (n*m)/2 then we will update the low to mid+1 else we will update high to mid-1. We will continue this process until low<=high. Finally, we will return low as the answer.
// Dry run on an example to find the median of the matrix: 
// 1 3 5
// 2 6 9
// 3 6 9
// Here, the minimum element is 1 and the maximum element is 9. So, the range of elements is 1 to 9. Now, we will apply binary search on this range. We will find the mid element which is 5. Now, we will find the number of elements less than or equal to 5. The number of elements less than or equal to 5 is 5. Since 5 is less than or equal to (3*3)/2=4, we will update low to mid+1. Now, the new low is 6. Now, we will find the mid element which is 6. Now, we will find the number of elements less than or equal to 6. The number of elements less than or equal to 6 is 7. Since 7 is greater than (3*3)/2=4, we will update high to mid-1. Now, the new high is 5. Now, we will find the mid element which is 5. Now, we will find the number of elements less than or equal to 5. The number of elements less than or equal to 5 is 5. Since 5 is less than or equal to (3*3)/2=4, we will update low to mid+1. Now, the new low is 6. Now, low>high. So, the answer is 6.
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int ans=n;
	int low=0,high=n-1;

	while(low<=high){
		int mid=(low + high)/2;
		if(arr[mid]>x){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return ans;
}

int countSmallEqual(vector<vector<int>> &A, int n, int m,int x){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=upperBound(A[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &A, int m, int n) {
  int low=INT_MAX,high=INT_MIN;
  for(int i=0;i<n;i++){
      low=min(low,A[i][0]);
      high=max(high,A[i][m-1]);
  }
  int req=(n*m)/2;
  while(low<=high){
      int mid=(low+high)/2;
      int smallEqual=countSmallEqual(A, n, m, mid);
      if(smallEqual<=req) low=mid+1;
      else high=mid-1;
  }
  return low;
}

int main(){
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return 0;
}