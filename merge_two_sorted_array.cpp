#include<bits/stdc++.h>
using namespace std;

// Brute Force
// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
#include<bits/stdc++.h>
void mergeTwoSortedArraysWithoutExtraSpace_BF(vector<long long> &a, vector<long long> &b){
    int i=0;
    int j=0;
    int n=a.size();
    int m=b.size();
    vector<long long> ans;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            ans.push_back(a[i]);
        i++;
        }
        else{
            ans.push_back(b[j]);
        j++;
        }
    }
    

    while(i<n){
            ans.push_back(a[i]);
        i++;
    }
    while(j<m){
            ans.push_back(b[j]);
            j++;
    }
    for(int i=0;i<n+m;i++){
        if(i<n) a[i]=ans[i];
        else b[i-n]=ans[i];
    }
   
}

//Optimal Approach 1:
// Time Complexity: O(min(n,m)) + O(nlogn + mlogm)
// Space Complexity: O(1)
#include<bits/stdc++.h>
void mergeTwoSortedArraysWithoutExtraSpace_O1(vector<long long> &a, vector<long long> &b){
    int n=a.size();
    int m=b.size();
    int i=n-1;
    int j=0;
   
    while(i>=0 && j<m){
        if(a[i]>b[j]){
            swap(a[i],b[j]);
        i--,j++;
        }
        else{
            break;
        }
    }
    
   sort(a.begin(),a.end());
   sort(b.begin(),b.end());
}

//Optimal Approach 2: Gap Method
// Time Complexity: O(Log2(n + m)) + O(n + m)
// Space Complexity: O(1)
// About Gap Method: In this method, we first calculate the gap and then we compare the elements of the first array with the elements of the second array. If the element of the first array is greater than the element of the second array, we swap the elements and sort the arrays. We continue this process until the elements of the first array are smaller than the elements of the second array.
#include<bits/stdc++.h>

void swapIfGreater(vector<long long> &a, vector<long long> &b, int ind1, int ind2) {
    if (a[ind1] > b[ind2]) {
        swap(a[ind1], b[ind2]);
    }
}

void mergeTwoSortedArraysWithoutExtraSpace_O2(vector<long long> &a, vector<long long> &b){
    int n=a.size();
    int m=b.size();
    int len=n+m;
    int gap=(len/2) + (len%2);

    while(gap>0){
    int left=0;
    int right=left + gap;
        while(right < len){
           if (left < n && right >= n) {
                swapIfGreater(a, b, left, right - n);
            }
            // case 2: both pointers in b[]:
            else if (left >= n) {
                swapIfGreater(b, b, left - n, right - n);
            }
            // case 3: both pointers in a[]:
            else {
                swapIfGreater(a, a, left, right);
            }
                left++,right++;
            }
        
        if(gap==1) break;
        gap=(gap/2) + (gap%2);
    }
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