#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
// Time Complexity: O(m*log2n)
// Space Complexity: O(1)
int NthRoot_BF(int n, int m) {
  // Write your code here.
  int ans=-1;
  for(int i=0;i<=m;i++){
    if(pow(i,n)==m){
      ans= i;
    }
  }
  return ans;
}

// Binary Search Approach
// Time Complexity: O(log2m) + O(log2n)
// Space Complexity: O(1)
int NthRoot_1(int n, int m) {
  // Write your code here.
  int ans=-1;
    int low=1,high=m;
    while(low<=high){
        int mid=(low + high)/2;
        if(pow(mid,n)==m){
            ans=mid;
            break;
        }
        else if(pow(mid,n)<m){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

// OR
// Funtion func is used for special case when mid is very large and n is very large then mid^n will overflow the integer limit so we will return 2 in that case.
int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot_2(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return mid;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
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