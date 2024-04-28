#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
// Time Complexity: O(n^3) + O(log(triplets))
// Space Complexity: 2O(triplets)
vector<vector<int>> triplet_BF(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> st;
   


    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j=1;k<n;k++){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==0){
                  vector<int> temp = {arr[i], arr[j], arr[k]};
                  sort(temp.begin(), temp.end());
                  st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


// Using hashing
// Time Complexity: O(n^2) + O(log(triplets))
// Space Complexity: O(triplets)
vector<vector<int>> triplet_hash(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> st;
    
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third=-(arr[i]+arr[j]);
            if(hashset.find(third)!=hashset.end()){
                vector<int>temp={arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Using two pointer approach:Optimal Approach
// Time Complexity: O(nlogn) + O(n * m)
// Space Complexity: O(triplets)
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1])continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
        int sum=arr[i]+arr[j]+arr[k];

        if(sum<0){
            j++;
        }
        else if(sum > 0){
            k--;
        }
        else{
            vector<int> temp = {arr[i] , arr[j] , arr[k]};
            ans.push_back(temp);
            j++;
            k--;
            while (j < k && arr[j] == arr[j - 1])
              j++;
            while (j < k && arr[k] == arr[k + 1])
              k--;
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