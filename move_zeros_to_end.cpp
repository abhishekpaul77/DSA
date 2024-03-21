#include<bits/stdc++.h>
using namespace std;


// Brute force approach
vector<int> moveZeros(int n, vector<int> a) {
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            ans.push_back(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==0){
            ans.push_back(a[i]);
        }
    }
    return ans;
}


// Optimal approach
vector<int> moveZeros(int n, vector<int> a) {
    int i =0;
    while(a[i]!=0){
        i++;
    }
    for(int j=i;j<n;j++){
        if(a[j]!=0){
            swap(a[i],a[j]);
            i++;
        }
    }
    return a;
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

    moveZeros(n, arr);

    cout << "After moving zeros to the end: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}