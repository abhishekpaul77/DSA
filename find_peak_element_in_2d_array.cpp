#include<bits/stdc++.h>
using namespace std;

// Problem: Find peak element in a 2D matrix
// Problem statement: You are given a 2D matrix ‘MATRIX’ of ‘N’*’M’ dimension. You must find the peak element in the matrix.
// You are given a 0-indexed 2-D grid ‘g’ of size ‘n’ X ‘m’, where each cell contains a positive integer, and adjacent cells are distinct.
// You need to find the location of a peak element in it. If there are multiple answers, find any of them.
// A peak element is a cell with a value strictly greater than all its adjacent cells.
// Assume the grid to be surrounded by a perimeter of ‘-1s’.
// You must write an algorithm that works in O(n * log(m)) or O(m * log(n)) complexity.

// Optimized approach: Binary search
// Time complexity: O(n*log(m))
// Space complexity: O(1)
int findMax(vector<vector<int>> &a,int n,int m,int col){
    int maxVal=-1;
    int ind=-1;

    for(int i=0;i<n;i++){
        if(a[i][col]>maxVal){
            maxVal=a[i][col];
            ind=i;
        }
    }
    return ind;
}

vector<int> findPeakGrid(vector<vector<int>> &g){
    // Write your code here.    
    int n=g.size();
    int m=g[0].size();

    int low=0,high=m-1;

    while(low<=high){
        int mid=(low + high)/2;
        int maxRowIndex=findMax(g, n, m, mid);
        int left=mid-1>=0 ? g[maxRowIndex][mid-1]: -1;
        int right=mid+1<m ? g[maxRowIndex][mid+1]: -1;
        if(g[maxRowIndex][mid] > left && g[maxRowIndex][mid] > right){
            return {maxRowIndex,mid};
        }
        else if(g[maxRowIndex][mid] < left){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return {-1,-1};
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