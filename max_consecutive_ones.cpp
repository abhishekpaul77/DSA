#include<bits/stdc++.h>
using namespace std;

int max_consecutive_ones(vector<int> &arr){
    int count = 0;
    int n=arr.size();
    int max_count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count = 0;
        }
        else{
            count++;
            max_count = max(max_count,count);
        }
    }
    return max_count;
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

    cout << "The maximum number of consecutive ones is: " << max_consecutive_ones(arr) << endl;

    return 0;
}