#include<bits/stdc++.h>
using namespace std;

// Brute force approach/ Better approach
// Time complexity: O(n^2)
// Space complexity: O(1)
int subarrayWithMaxProduct(vector<int> &arr){
	int n = arr.size(); //size of array.
    int maxP=arr[0];
    for(int i=0;i<n;i++){
        int product=arr[i];
        for(int j=i+1;j<n;j++){
            product=product*arr[j];
        }
        maxP=max(maxP,product);
    }
    return maxP;
}
// Optimal approach: Observation based
// Time complexity: O(n)
// Space complexity: O(1)
// The idea is to have two products, one from the start of the array and the other from the end of the array.
// Starting product is named as pref and ending product is named as suff.
// We iterate through the array and update the pref and suff products.
// If pref becomes 0, we reset it to 1.
// If suff becomes 0, we reset it to 1.
// We update the maxP with the maximum of maxP, pref and suff at each iteration.
// At the end of the iteration, maxP will contain the maximum product of the subarray.
// This approach is based on the observation that the maximum product of the subarray will be the maximum of pref and suff products.
// This is because the pref product will contain the maximum product of the subarray starting from the beginning of the array.
// The suff product will contain the maximum product of the subarray starting from the end of the array.
// The maximum product of the subarray will be the maximum of pref and suff products.
// This approach has a time complexity of O(n) and a space complexity of O(1).
int subarrayWithMaxProduct(vector<int> &arr){
	// Write your code here.
	int n = arr.size(); //size of array.
    int pref=1,suff=1;
    int maxP=INT_MIN;
    for(int i=0;i<n;i++){
        if(pref==0) pref=1;
        if(suff==0) suff=1;
        pref=pref*arr[i];
        suff=suff*arr[n-i-1];
        maxP=max(maxP,max(pref,suff));
    }
    return maxP;
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