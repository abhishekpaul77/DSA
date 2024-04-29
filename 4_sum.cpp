#include<bits/stdc++.h>
using namespace std;

//Brute force and hashing approach are same as 3_sum.cpp
// Using two pointer approach:Optimal Approach
// Time Complexity: O(n^2 * n)
// Space Complexity: O(four_sum)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // Write your code here
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1])continue;
        for(int j=i+1;j<n;j++){
            if(j!=(i+1) && nums[j]==nums[j-1])continue;
            int k=j+1;
            int l=n-1;

            while(k<l){
                long long sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum>target){
                    l--;
                }
                else if(sum<target){
                    k++;
                }
                else{
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    l--;
                    k++;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
            }
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