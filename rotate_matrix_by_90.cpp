#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//Time Complexity: O(n*n)
//Space Complexity: O(n*n)
vector < vector < int >> rotate_BF(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
    return rotated;
}

//Optimized Approach
//Time Complexity: O(N*N) + O(N*N)
//Space Complexity: O(1)
void rotateMatrix(vector<vector<int>> &mat){
	// Write your code here.
	int n=mat.size();

        for (int i = 0; i < n - 1; i++) {
          for (int j = i + 1; j < n; j++){
			  swap(mat[i][j],mat[j][i]);
		  }
        }
	
	for(int i=0;i<n;i++){
		reverse(mat[i].begin(),mat[i].end());
	}
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