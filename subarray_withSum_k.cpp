#include<bits/stdc++.h>
using namespace std;

//Optimal Approach
//Time Complexity=O(n * log(n))
//Space Complexity=O(n)
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    int preSum=0,cnt=0;
    unordered_map<int,int>mp;
    mp[0]=1;

    for(int i=0;i<arr.size();i++){
        preSum+=arr[i];
        int remove=preSum - k;
        cnt+=mp[remove];
        mp[preSum]+=1;
    }
    return cnt;
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