/*
Problem statement
You are given a starting position for a rat which is stuck in a maze at an initial point (0, 0) (the maze can be thought of as a 2-dimensional plane). The maze would be given in the form of a square matrix of order 'N' * 'N' where the cells with value 0 represent the maze’s blocked locations while value 1 is the open/available path that the rat can take to reach its destination. The rat's destination is at ('N' - 1, 'N' - 1). Your task is to find all the possible paths that the rat can take to reach from source to destination in the maze. The possible directions that it can take to move in the maze are 'U'(up) i.e. (x, y - 1) , 'D'(down) i.e. (x, y + 1) , 'L' (left) i.e. (x - 1, y), 'R' (right) i.e. (x + 1, y).
Note:
Here, sorted paths mean that the expected output should be in alphabetical order.
*/

#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
Space Complexity:  O(m*n), Maximum Depth of the recursion tree(auxiliary space).
*/
void solve(vector<vector<int>> &arr, vector<string> &ans,
           vector<vector<int>> &vis,string ds, int n, int i, int j) {
  if (i < 0 || j < 0 || i == n || j == n || arr[i][j]==0)
    return;

    if(i==n-1 && j==n-1){
        ans.push_back(ds);
        return;
    }

    string dir="RULD";
    int ir[]={0,-1,0,1};
    int jc[]={1,0,-1,0};

    for(int ind=0;ind<4;ind++){
        if(vis[i][j]!=1){
            vis[i][j]=1;
            solve(arr, ans, vis,ds +  dir[ind] ,n, i+ir[ind],j + jc[ind]);
            vis[i][j]=0;
        }

    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
  // Write your code here.
  vector<string> ans;
  vector<vector<int>> vis(n, vector<int>(n, 0));
  string ds;
  if(n==0)return ans;
  if (arr[0][0] == 1) {
    solve(arr, ans, vis,ds, n, 0, 0);
  }
    sort(ans.begin(), ans.end());

  return ans;
}

int main(){
    
    return 0;
}