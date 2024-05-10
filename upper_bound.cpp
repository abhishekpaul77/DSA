#include<bits/stdc++.h>
using namespace std;

// upper_bound() returns an iterator pointing to the first element in the range [first, last) which has a value greater than val.
// If all the elements in the range compare less than or equal to val, the function returns last.

// Brute force approach
// Time complexity: O(n)
// Space complexity: O(1)
int upperBound_BF(vector<int> &arr, int x, int n){	
	int ans=0;
	for(int i=0;i<n;i++){
		if(arr[i]==x){
			ans=i+1;		
		}
		else if(arr[i]>x){
			ans=i;
			break;
		}
		else{
			ans=n;
		}
	}
	return ans;
}

// Binary search approach
// Time complexity: O(logn)
// Space complexity: O(1)
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