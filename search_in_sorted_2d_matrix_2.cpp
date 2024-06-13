#include<bits/stdc++.h>
using namespace std;

// Problem: Search in a 2D matrix
// Problem statement: You are given a 2D matrix ‘MATRIX’ of ‘N’*’M’ dimension. You must check whether a given number ‘target’ is present in the matrix.
// The following properties apply to the given matrix:
// 1. In each row, integers are sorted from left to right.
// 2. Each row's first integer is greater than the previous row's last integer.


// Optimized approach: Binary search
// Time complexity: O(n+m)
// Space complexity: O(1)
bool searchElement(vector<vector<int>> &a, int target) {
    int n=a.size();
    int m=a[0].size();

    int row=0,col=m-1;

    while(row < n && col >=0){
        if(a[row][col]== target){
            return true;
        }
        else if(a[row][col] > target){
            col--;
        }
        else{
            row++;
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