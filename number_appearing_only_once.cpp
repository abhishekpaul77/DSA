#include<bits/stdc++.h>
using namespace std;

//Bruteforce method
// Time complexity: O(n^2)
int find_number_appearing_once(vector<int> arr){
    int count=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count==1){
            return arr[i];
        }
    }
}

// Using hash map
// Time complexity: O(n/2 + 1) 
int find_number_appearing_once_hash(vector<int> arr){
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    for(auto i:mp){
        if(i.second==1){
            return i.first;
        }
    }
}

// Optimal solution using XOR
// Time complexity: O(n)
int find_number_appearing_once_xor(vector<int> arr){
    int res=0;
    for(int i=0;i<arr.size();i++){
        res=res^arr[i];
    }
    return res;
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

    // cout << "The number appearing only once is: " << find_number_appearing_once(arr) << endl;
    // cout << "The number appearing only once is: " << find_number_appearing_once_hash(arr) << endl;
    cout << "The number appearing only once is: " << find_number_appearing_once_xor(arr) << endl;
    return 0;
}