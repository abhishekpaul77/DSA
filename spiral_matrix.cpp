#include<bits/stdc++.h>
using namespace std;

//Optimal Approach
//Time Complexity=O(n*m)
//Space Complexity=O(n*m)
vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    // Write your code here.
    int n=MATRIX.size();
    int m=MATRIX[0].size();

    int top=0,left=0,right=m-1,bottom=n-1;
    vector<int> ans;

    while(top<=bottom && left<=right){
    for(int i=left;i<=right;i++){
        ans.push_back(MATRIX[top][i]);
    }
    top++;

    for(int i=top;i<=bottom;i++){
        ans.push_back(MATRIX[i][right]);
    }
    right--;

    if(top<=bottom){
        for (int i = right; i >= left; i--) {
          ans.push_back(MATRIX[bottom][i]);
        }
        bottom--;
    }
    if(left<=right){
        for (int i = bottom; i >= top; i--) {
          ans.push_back(MATRIX[i][left]);
        }
        left++;
    }
    }
    return ans;
}

int main(){
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return 0;
}