#include <bits/stdc++.h>
using namespace std;

// Bruteforce approach
// Time complexity: O(n)
// Space complexity: O(n)
vector<int> alternateNumbers_1(vector<int> &a)
{
    int n = a.size();
    vector<int> nli;
    vector<int> pli;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            nli.push_back(a[i]);
        }
        else
            pli.push_back(a[i]);
    }

    int index1 = 0;
    int index2 = 0;

    for (int i = 0; i < n; i += 2)
    {
        a[i] = pli[index1];
        index1++;
    }
    for (int i = 1; i < n; i += 2)
    {
        a[i] = nli[index2];
        index2++;
    }

    return a;
}

// Optimized approach
// Time complexity: O(n)
// Space complexity: O(n)


vector<int> alternateNumbers_2(vector<int>&a) {
    int n=a.size();
    int pos=0;
    int neg=1;
    vector<int> ans(n,0);

    for(int i=0;i<n;i++){
        if(a[i]>0){
            ans[pos]=a[i];
            pos+=2;
        }
        else{
            ans[neg]=a[i];
            neg+=2;
        }
    }
    return ans;
}


int main()
{
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