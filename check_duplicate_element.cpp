#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int index=0;
	for(int i=1;i<n;i++){
		if(arr[i]!=arr[index]){
			arr[index+1]=arr[i];
			index++;
		}
	}
	return index+1;
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

    cout << removeDuplicates(arr,n);

    return 0;
}