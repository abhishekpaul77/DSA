#include<bits/stdc++.h>
using namespace std;

// Brute force approach
// Time complexity: O(n2)
// Space complexity: O(1)
vector<int> findMissingRepeatingNumbers_BF(vector < int > a) {
    // Write your code here
    int missing=-1,repeating= -1;
    int n=a.size();

    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j]==i){
                cnt++;
            }
        }
        if(cnt==2){
            repeating=i;
        }
        else if (cnt==0){
            missing=i;
        }
        if(missing!=-1 && repeating!=-1){
            break;
        }
    }
    return {repeating,missing};
}

// Better approach: Using hashing
// Time complexity: O(n)
// Space complexity: O(n)
vector<int> findMissingRepeatingNumbers_Better(vector < int > a) {
    // Write your code here
    int missing=-1,repeating= -1;
    int n=a.size();

    int hash[n+1]={0};

    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }
    
    for(int i=0;i<=n;i++){
        if(hash[i]==2){
            repeating=i;
        }
        else if(hash[i]==0){
            missing=i;
        }
    }
    return {repeating,missing};
}

// Optimal approach: Using Maths
// Time complexity: O(n)
// Space complexity: O(1)
// In this approach we will use the concept of sum of n natural numbers and sum of squares of n natural numbers to find the missing and repeating number in the array.
// Let's say the repeating number is x and missing number is y.
// Let's say the sum of n natural numbers is S and sum of squares of n natural numbers is S1.
// So, the sum of n natural numbers in the array is S1-S and sum of squares of n natural numbers in the array is S1-S1.
// So, the sum of n natural numbers in the array is S1-S = S-x+y
// So, the sum of squares of n natural numbers in the array is S1-S1 = S1-x^2+y^2
// So, we have two equations:
// 1. S-x+y = S1-S
// 2. S1-x^2+y^2 = S1-S1
// Solving these two equations we get:
// x-y = S-S1/S-S1
// x = S-S1/S-S1 + y
// y = S+S1/S-S1 - x
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    int n=a.size();
    long long sn=(n*(n+1))/2;
    long long s2n=(n*(n+1)*(2*n+1))/6;
    long long s=0,s2=0;

    for(int i=0;i<n;i++){
        s+=a[i];
        s2+=(long long)a[i] * (long long)a[i];
    }

    long long val1=s-sn;
    long long val2=s2-s2n;

    val2=val2/val1;

    long long x=(val1 + val2)/2;
    long long y=x-val1;;

    return {(int)x,(int)y};
}

// Optimized approach: Using XOR
// Time complexity: O(n)
// Space complexity: O(1)
// In this approach we will use the concept of XOR to find the missing and repeating number in the array.
//In the code below, we first find the XOR of all the elements of the array and XOR of all the elements from 1 to n.
//Then we find the rightmost set bit in the XOR of the two values.
//Then we divide the elements of the array into two groups based on the rightmost set bit.
//Then we divide the elements from 1 to n into two groups based on the rightmost set bit.
//Then we find the XOR of the two groups of elements.
//Then we find the repeating and missing number based on the XOR of the two groups of elements.
vector<int> findMissingRepeatingNumbers_XOR(vector<int> a) {
  // Write your code here
  long long n = a.size();
  int xr = 0;

  for (int i = 0; i < n; i++) {
    xr = xr ^ a[i];
    xr = xr ^ (i + 1);
  }
  int bitNo = 0;
  while (1) {
    if ((xr & (1 << bitNo)) != 0) {
      break;
    }
    bitNo++;
  }
  int zero = 0, one = 0;

  for (int i = 0; i < n; i++) {
    if ((a[i] & (1<<bitNo))!=0){
        one=one ^ a[i];
    }
    else{
        zero=zero ^ a[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    if ((i & (1<<bitNo))!=0){
        one=one ^ i;
    }
    else{
        zero=zero ^ i;
    }
  }

  int cnt=0;
  for(int i=0;i<n;i++){
      if(a[i]==zero)cnt++;
  }
  if(cnt== 2) return {zero,one};
  return {one,zero};
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