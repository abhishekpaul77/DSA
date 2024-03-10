// Hashing in C++
// Hashing is a technique to convert a range of key values into a range of indexes of an array.

/*
In int main() we can declare int array upto size 10^6 but if we declare array of size 10^7 then it will give segmentation fault.
And if we declare array of size 10^7 globally then it will not give segmentation fault.

For boolean array we can declare array of size 10^7 in int main() and it will not give segmentation fault.
And boolean array can be declared of size 10^8 globally and it will not give segmentation fault.
*/

#include <bits/stdc++.h>
using namespace std;


int charhash(char any, string str)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == any)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    // 1.Number hashing
    // int n;
    // cout << "Enter the size of array" << endl;
    // cin >> n;

    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter the" << i << " element:" << endl;
    //     cin >> arr[i];
    // }

    // //Prestoring the frequency of each element in the array
    // int hash[n+1]={0};
    // for (int i = 0; i < n; i++)
    // {
    //     hash[arr[i]]=hash[arr[i]]+1;
    // }

    // //Printing the frequency of each element in the array
    // int query;
    // cout << "Enter the number of queries" << endl;
    // cin >> query;
    // while (query--){
    //     int x;
    //     cout << "Enter the element to be queried" << endl;
    //     cin >> x;
    //     cout << "The frequency of " << x << " is " << hash[x] << endl;
    // }

    // 2.String hashing
    // a-> Using for loop
    // string s = "abbc";
    // cout << charhash('b', s) << endl;
    string s;
    cout << "Enter the string" << endl;
    cin >> s;

    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]-'a']=hash[s[i]-'a']+1;//hash[s[i]-'a']++; or hash[s[i]-'a']+=1;
    }

    int query;
    cout << "Enter the number of queries" << endl;
    cin >> query;
    while (query--)
    {
        char x;
        cout << "Enter the element to be queried" << endl;
        cin >> x;
        cout << "The frequency of " << x << " is " << hash[x-'a'] << endl;
    }

    return 0;
}