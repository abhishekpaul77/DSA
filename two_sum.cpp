#include<bits/stdc++.h>
using namespace std;

//Bruteforce method
// Time complexity: O(n^2)
string read(int n, vector<int> book, int target)
{
    int a=0,b=0;
    for(int i=0;i<n;i++){
        a=book[i];
        int rem=target-a;
        for(int j=i;j<n;j++){
            if(book[j]==rem){
             b=book[j];
             break;
            }
        }
    }
        if(a && b){
            return "YES";
        }
        else{
            return "NO";
        }
}

// Better approach: Using hash map
// Time complexity: O(n)
string read_hash(int n, vector<int> book, int target)
{
   map<int,int> mp;
   for(int i=0;i<n;i++){
       int a=book[i];
       int b=target-a;
       if(mp.find(b)!=mp.end()){
           return "YES";
       }
       mp[a]=i;
   }
   return "NO";
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