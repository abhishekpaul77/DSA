#include<bits/stdc++.h>
using namespace std;

//Brute Force
//Time Complexity: O(nlogn) + O(2n)
//Space Complexity: O(n)
vector<vector<int>> mergeOverlappingIntervals_BF(vector<vector<int>> &arr){
	int n=arr.size();
	vector<vector<int>> ans;

	for(int i=0;i<n;i++){
		int start=arr[i][0];
		int end=arr[i][1];

		if(!ans.empty() && end<=ans.back()[1]){
			continue;
		}

		for(int j=i+1;j<n;j++){
			if(arr[j][0] <=end){
				end=max(end,arr[j][1]);
			}
			else break;
		}
		ans.push_back({start,end});
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