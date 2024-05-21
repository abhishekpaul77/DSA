#include<bits/stdc++.h>
using namespace std;

// Problem statement: Given two sorted arrays, find the kth element in the two sorted arrays.


// Optimal approach: Binary search
// Time complexity: O(log(min(n1, n2)))
// Space complexity: O(1)
// In this approach, we perform a binary search on the smaller array to find the kth element.
// We maintain two pointers, low and high, to search for the kth element.
// Now there is a minor change in low and high pointers as compared to the median of two sorted arrays.
// Low is max(0, k - n2) because if k is greater than n2, then we need to consider all elements of the smaller array.
// High is min(k, n1) because if k is less than n1, then we need to consider only k elements of the smaller array.
// We find mid1 and mid2 such that mid1 + mid2 = k.
// We find the left and right elements of mid1 and mid2.
// If the left elements are less than or equal to the right elements, we return the maximum of the left elements.
// If the left elements are greater than the right elements, we update the low and high pointers accordingly.
// We repeat this process until we find the kth element.
// Finally, we return the kth element.
int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
    if(n1>n2) return kthElement(b, a,n2,n1,k);

    int low=max(0,k-n2);
    int high=min(k,n1);
    int left=k;
    int n=n1+n1;

    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;

        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;

        if(mid1 < n1) r1=a[mid1];
        if(mid2< n2) r2=b[mid2];
        if(mid1-1 >= 0) l1=a[mid1-1];
        if(mid2-1 >=0) l2=b[mid2-1];

        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }
        return 0;

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