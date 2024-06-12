#include<bits/stdc++.h>
using namespace std;

// Binary search approach
// Time complexity: O(log2n)
// Space complexity: O(1)
int findMin(vector<int>& arr)
{
	// Write your code here.
	int n=arr.size();
	int low=0,high=n-1;
	int ans=INT_MAX;

	while(low<=high){
		int mid=(low + high)/2;
		if(arr[low]<=arr[high]){
			ans=min(ans,arr[low]);
			break;
		}
		if(arr[low]<=arr[mid]){
			ans=min(ans,arr[low]);
			low=mid+1;
		}
		else {
			ans=min(ans,arr[mid]);
			high=mid-1;
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