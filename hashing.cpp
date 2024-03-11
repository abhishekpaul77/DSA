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

    // b-> Using hash array
    // string s;
    // cout << "Enter the string" << endl;
    // cin >> s;

    // int hash[26] = {0};
    // for (int i = 0; i < s.size(); i++)
    // {
    //     hash[s[i]-'a']=hash[s[i]-'a']+1;//hash[s[i]-'a']++; or hash[s[i]-'a']+=1;
    // }

    // int query;
    // cout << "Enter the number of queries" << endl;
    // cin >> query;
    // while (query--)
    // {
    //     char x;
    //     cout << "Enter the element to be queried" << endl;
    //     cin >> x;
    //     cout << "The frequency of " << x << " is " << hash[x-'a'] << endl;
    // }

    // c-> Using map
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;

    int arr[n];
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the" << i << " element:" << endl;
        cin >> arr[i];
    }

    map<int, int> hashmpp;
    for (int i = 0; i < n; i++)
    {
        hashmpp[arr[i]]++;
    }

    int query;
    cout << "Enter the number of queries" << endl;
    cin >> query;
    while (query--)
    {
        int x;
        cout << "Enter the element to be queried" << endl;
        cin >> x;
        cout << "The frequency of " << x << " is " << hashmpp[x] << endl;
    }

    // Time complexity of hashing is O(1) and space complexity is O(n)
    // Time complexity of hashing using map is O(logn) and space complexity is O(n)
    // Time complexity of hashing using unordered_map is O(1) and space complexity is O(n), for
    // Worst case time complexity is O(n) and space complexity is O(n) because of collision.
    // Collison is when two different keys are mapped to the same index of the array. To grab the theory of collision, refer to division method in hashing.
    // To avoid collision we can use separate chaining or open addressing.
    // Ordered list can have any data type as key and value but unordered_map can have only primitive data type as key.

    return 0;
}