#include<bits/stdc++.h>
using namespace std;

//Brute force approach
//Time complexity: O(n)
//Space complexity: O(1)
int singleNonDuplicate_BF(vector<int>& arr)
{
	// Write your code here
	int n=arr.size();
	for(int i=0;i<n;i++){
		if(i==0){
			if(arr[i]!=arr[i+1])return arr[i];
		}
		if(i==n-1){
			if(arr[i]!=arr[i-1])return arr[i];
		}
		if(arr[i-1]!=arr[i] && arr[i]!=arr[i+1]){
			return arr[i];
		}
	}
}

// Binary search approach
// Time complexity: O(log2n)
// Space complexity: O(1)
 int n = arr.size(); //size of the array.

    //Edge cases:
    if (n == 1) return arr[0];
    if (arr[0] != arr[1]) return arr[0];
    if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if arr[mid] is the single element:
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return arr[mid];
        }

        //we are in the left:
        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
            //eliminate the left half:
            low = mid + 1;
        }
        //we are in the right:
        else {
            //eliminate the right half:
            high = mid - 1;
        }
    }

    // dummy return statement:
    return -1;
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