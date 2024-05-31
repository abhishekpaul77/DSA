#include<bits/stdc++.h>
using namespace std;

// Problem: Search in a 2D matrix
// Problem Statement: In this problem, we are given a matrix of n rows and m columns.
// The matrix is sorted row-wise and column-wise.
// We have to find if a given element is present in the matrix or not.

// Brute force approach
// Time complexity: O(n*m)
// Space complexity: O(1)
bool searchInMatrix_BF(vector<vector<int>> &matrix, int n, int m, int x) {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==x){
                return true;
            }
        }
    }
    return false;
}

// Binary search approach: but this is not the optimized approach
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

bool searchInMatrix(vector<vector<int>> &matrix, int n, int m, int x) {
    for(int i=0;i<n;i++){
        if(matrix[i][0]<=x && matrix[i][m-1]>=x){
            if(lowerBound(matrix[i], m, x)<m && matrix[i][lowerBound(matrix[i], m, x)]==x){
                return true;
            }
        }
    }
    return false;
}

// Optimized approach: Binary search
// Time complexity: O(log2(n*m))
// Space complexity: O(1)
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n=mat.size();
    int m=mat[0].size();

    int low=0,high=(n*m)-1;
    while(low<=high){
        int mid=(low + high)/2;

        int row=mid/m,col=mid%m;

        if(mat[row][col]==target){
            return true;
        }
        else if(mat[row][col]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return false;
        
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