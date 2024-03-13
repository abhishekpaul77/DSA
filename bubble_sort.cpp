// Bubble sort
// Time complexity: O(n^2) but it can be optimized to O(n) in the best case if the array is already sorted.
// Space complexity: O(1)
// About the algorithm: Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.


#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[],int n){
    bool did_swap=false;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                did_swap=true;
            }
        }
        if(did_swap==false){
            break;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element "<<i+1<<": ";
        cin>>arr[i];
    }

    bubble_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}