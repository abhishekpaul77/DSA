#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
int floorSqrt_BF(int n)
{
    // Write your code here.
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i*i<=n){
            ans= i;
        }
        else{
            break;
        }
    }
    return ans;
}

// Binary Search Approach
// Time Complexity: O(logn)
// Space Complexity: O(1)
int floorSqrt(int n)
{
    // Write your code here.
    int ans=0;
    int low=1,high=n;
    while(low<=high){
        int mid=(low + high)/2;
        if(mid*mid<=n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
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