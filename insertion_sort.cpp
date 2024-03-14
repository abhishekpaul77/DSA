// Insertion sort algorithm
// Time complexity: O(n^2) for the worst case and O(n) for the best case
// Space complexity: O(1)
// About the algorithm: The insertion sort algorithm builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, insertion sort provides several advantages:
// Simple implementation: Jon Bentley shows a three-line C version, and a five-line optimized version 
// Efficient for (quite) small data sets, much like other quadratic sorting algorithms
// More efficient in practice than most other simple quadratic (i.e., O(n^2)) algorithms such as selection sort or bubble sort
// Adaptive, i.e., efficient for data sets that are already substantially sorted: the time complexity is O(nk) when each element in the input is no more than k places away from its sorted position
// Stable, i.e., does not change the relative order of elements with equal keys
// In-place, i.e., only requires a constant amount O(1) of additional memory space
// Online, i.e., can sort a list as it receives it
// When people manually sort cards in a bridge hand, most use a method that is similar to insertion sort.

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        // Using for loop
        // for(int j=i;j>0 && arr[j-1]>arr[j];j--){
        //     int temp=arr[j-1];
        //     arr[j-1]=arr[j];
        //     arr[j]=temp;
        // }
        // Using while loop
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
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

    insertion_sort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}