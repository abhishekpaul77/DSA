#include<bits/stdc++.h>
using namespace std;

//Brute force approach
void leftRotateByOne(vector<int> &arr, int k){
    int n=arr.size();
    int d=k%n;
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }
}

//Optimal approach
void leftRotateByOneOptimal(vector<int> &arr, int k){
    int n=arr.size();
    int d=k%n;
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.end());
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

    // 1. leftRotateByOne(arr, 3);  
    leftRotateByOneOptimal(arr, 3);// 2. leftRotateByOneOptimal(arr, 3);

    cout << "Array after left rotation by 3: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}