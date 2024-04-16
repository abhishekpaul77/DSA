#include<bits/stdc++.h>
using namespace std;

//Bruteforce method
// Time complexity: O(n^2)
// 1. Generate all permutations of the array
// 2. Find the next permutation of the array
// 3. Return the next permutation
// 4. We use recursion to generate all permutations of the array
// 5. If given array is the last permutation, then the next permutation will be the first permutation.

vector<int> next_permutation(vector<int> arr){
    vector<int> res;
    sort(arr.begin(),arr.end());
    do{
        res=arr;
    }while(next_permutation(arr.begin(),arr.end()));
    return res;
}

// Using c++ inbuilt function
// Time complexity: O(n)
vector<int> next_permutation_inbuilt(vector<int> arr){
    next_permutation(arr.begin(),arr.end());
    return arr;
}

// Optimal solution
// Time complexity: O(n)
vector<int> nextGreaterPermutation(vector<int> &A) {
    int n=A.size();
    int ind=-1;
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(A.begin(),A.end());
        return A;
    }

    for(int i=n-1;i>ind;i--){
            if (A[i] > A[ind]) {
              swap(A[i], A[ind]);
              break;
            }
    }
    
    reverse(A.begin() + ind +1 ,A.end());
   return A;
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