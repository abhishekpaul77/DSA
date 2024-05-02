#include<bits/stdc++.h>
using namespace std;

//Brute Force
//Time Complexity: O(n^2)
//Space Complexity: O(1)
int subarraysWithSumK_BF(vector < int > a, int b) {
   int n=a.size();
   int cnt=0;
   
   for(int i=0;i<n;i++){
      int xor1=0;
       for(int j=i;j<n;j++){
           xor1=xor1^a[j];
       if(xor1==b){
           cnt++;
       }
       }
   }
   return cnt;
}

//Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
int subarraysWithSumK(vector < int > a, int b) {
   int n=a.size();
   int cnt=0;
    int xr=0;
    map<int,int> mp;
    mp[xr]++;

    for(int i=0;i<n;i++){
        xr=xr^a[i];//b
        //Find x
        int x=xr^b;
        cnt=cnt + mp[x];
        mp[xr]++;
    }
   return cnt;
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