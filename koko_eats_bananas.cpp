#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
// Time Complexity: O(max(arr) * n);
// Space Complexity: O(1)
// In this code snippet, we are given an array of integers, where each element of the array represents the number of bananas that Koko can eat in an hour. We are also given an integer H, which represents the total number of hours Koko has to eat all the bananas. Our task is to find the minimum integer K such that Koko can eat all the bananas within H hours.
// The brute-force approach is to iterate over all the possible values of K from 1 to the maximum number of bananas that Koko can eat in an hour. For each value of K, we calculate the total number of hours required to eat all the bananas using the formula ceil(arr[i] / K) and sum up the total hours. If the total hours are less than or equal to H, we return the current value of K as the answer.
// If we do not find any value of K that satisfies the condition, we return the maximum number of bananas that Koko can eat in an hour as the answer.
int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas_BF(vector<int> v, int h) {
    //Find the maximum number:
    int maxi = findMax(v);

    //Find the minimum value of k:
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }

    //dummy return statement
    return maxi;
}

//Binary Search Approach
// Time Complexity: O(n*log(max(arr)))
// Space Complexity: O(1)
// In this approach, we use binary search to find the minimum value of K such that Koko can eat all the bananas within H hours. We first find the maximum number of bananas that Koko can eat in an hour. We then perform a binary search on the answer space from 1 to the maximum number of bananas that Koko can eat in an hour.
// For each value of K, we calculate the total number of hours required to eat all the bananas using the formula ceil(arr[i] / K) and sum up the total hours. If the total hours are less than or equal to H, we update the answer with the current value of K and continue the binary search in the lower half of the answer space. If the total hours are greater than H, we continue the binary search in the upper half of the answer space.
// We repeat this process until the lower bound is less than or equal to the upper bound. At the end of the binary search, we return the answer as the minimum value of K.
int minimumRateToEatBananas(vector<int> v, int h) {
    //Find the maximum number:
    int maxi = findMax(v);
    int low=1,high=maxi;
    int ans=INT_MAX;

    while(low<=high){
        int mid=(low + high)/2;
        int totalTime=0;
        totalTime=calculateTotalHours(v, mid);
        if( totalTime<=h){
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