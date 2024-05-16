#include<bits/stdc++.h>
using namespace std;

// Bruteforce approach
// Time complexity: O(n)
// Space complexity: O(1)
pair<int, int> firstAndLastPosition_BF(vector<int>& arr, int n, int k)
{
    int cnt=0;
    int ans1=-1;
    int ans2=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            cnt++;
            ans1=i;
        }
    }

    if (cnt > 0) {
        ans2 = ans1 - cnt + 1;
    }

    return make_pair(ans2,ans1);
}


// Optimized approach: Binary search
// Time complexity: O(logn)
// Space complexity: O(1)
int upperBound(vector<int> &arr, int n, int x){
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
int lowerBound(vector<int> &arr, int n, int x) {
    int ans=n;
	int low=0,high=n-1;

    while(low<=high){
        int mid=(low + high)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }else {
            low = mid + 1;
        }
    }
    
    return ans;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)

{
int lb=lowerBound(arr, n, k);
if(lb==n || arr[lb]!=k){
    return {-1,-1};
}
else{
    return {lb,(upperBound(arr, n, k)-1)};
}

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