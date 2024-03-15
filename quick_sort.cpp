// Quick sort
// Time complexity: O(nlogn)
// Space complexity: O(logn)
// About the algorithm: Quick sort is a divide and conquer algorithm. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively. This can be done in-place, requiring small additional amounts of memory to perform the sorting

#include<bits/stdc++.h>
using namespace std;


int pivot_partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quick_sort(vector<int> &arr,int low,int high){
    if(low<high){
        int pivot=pivot_partition(arr,low,high);
        quick_sort(arr,low,pivot-1); 
        quick_sort(arr,pivot+1,high);
    }
}

int main(){
    int n;
    
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> arr(n);

    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // Quick sort
    quick_sort(arr,0,n-1);

    cout<<"The sorted array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}