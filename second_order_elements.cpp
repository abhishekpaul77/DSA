#include<bits/stdc++.h>
using namespace std;


void second_largest(vector<int> &arr, int n){
    int largest=arr[0];
    int second_largest=INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            second_largest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>second_largest){
            second_largest=arr[i];
        }
    }
    cout<<"Second largest element: "<<second_largest<<endl;
}

void second_smallest(vector<int> &arr, int n){
    int smallest=arr[0];
    int second_smallest=INT_MAX;

    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            second_smallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]>smallest && arr[i]<second_smallest){
            second_smallest=arr[i];
        }
    }
    cout<<"Second smallest element: "<<second_smallest<<endl;
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

    second_largest(arr, n);
    second_smallest(arr, n);
    
    return 0;
}