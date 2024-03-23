#include <bits/stdc++.h>
using namespace std;

// Bruteforce approach
void union_of_two_arrays_BF(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    vector<int> Union;

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        mp[b[i]]++;
    }

    for (auto &it : mp)
    {
        Union.push_back(it.first);
    }

    for (int i = 0; i < Union.size(); i++)
    {
        cout << Union[i] << " ";
    }
}

// Using set
vector<int> union_of_two_arrays_set(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    set<int> s;
    vector<int> Union;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    for (auto &it : s)
        Union.push_back(it);
    return Union;
}

// Two pointer approach
vector<int> union_of_two_arrays_TP(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    vector < int > Union;
    while (i < n && j < m){
    if (a[i] <= b[j])
        {
            if (Union.size() == 0 || Union.back() != a[i])
                Union.push_back(a[i]);
            i++;
        } else
        {
            if (Union.size() == 0 || Union.back() != b[j])
                Union.push_back(b[j]);
                j++;
        }
  }
  while (i < n)
  {
        if (Union.size() == 0 || Union.back() != a[i])
            Union.push_back(a[i]);
            i++;
  }
  while (j < m)
    {
        if (Union.size() == 0 || Union.back() != b[j])
            Union.push_back(b[j]);
            j++;
    }
    return Union;
}

int main()
{
    int n, m;

    cout << "Enter the number of elements for first array: ";
    cin >> n;
    cout << "Enter the number of elements for second array: ";
    cin >> m;

    vector<int> a(n);
    vector<int> b(n);

    cout << "Enter the elements for 1st array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the elements for 2nd array: ";
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    // 1. union_of_two_arrays_BF(a,b);
    // 2. union_of_two_arrays_set(a, b);

    vector<int> Unionarr = union_of_two_arrays_TP(a, b);

    for (int i = 0; i < Unionarr.size(); i++)
    {
        cout << Unionarr[i] << " ";
    }

    return 0;
}