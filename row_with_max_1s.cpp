#include<bits/stdc++.h>
using namespace std;

// Problem: Row with max 1s
// Problem Statement: In this problem, we are given a matrix of 0s and 1s.
// We have to find the row with the maximum number of 1s.

// Brute force approach
// Time complexity: O(n*m)
// Space complexity: O(1)
int rowWithMax1s_BF(vector<vector<int>> &matrix, int n, int m) {
    int maxi=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<m;j++){
            cnt+=matrix[i][j];
        }
        if(cnt>maxi){
            maxi=cnt;
            ans=i;
        }
    }
    return ans;
}

// Optimized approach: Binary search
// Time complexity: O(n*log2(m))
// Space complexity: O(1)
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Write Your Code Here
    int maxi=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        int cnt=m-lowerBound(matrix[i], m, 1);
        if(cnt>maxi){
            maxi=cnt;
            ans=i;
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