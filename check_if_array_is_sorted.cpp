#include<bits/stdc++.h>
using namespace std;

int isSorted(int n, vector<int> a) {
  // Write your code here.
  int initial = a[0];
  int track = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= initial) {
      initial = a[i];
      track++;
    }
  }
   if (track == n) {
      return 1;
    } else {
      return 0;
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

    cout << isSorted(n,arr);

    return 0;
}