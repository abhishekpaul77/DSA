#include<bits/stdc++.h>
using namespace std;

void shiftArrayByOne(vector<int> &arr, int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp; 
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


    shiftArrayByOne(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }


    return 0;
}