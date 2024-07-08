#include <bits/stdc++.h>
using namespace std;

// Bruteforce approach
// Time complexity: O(n^3)
int longestSubarrayWithSumK(vector<int> arr, int d)
{
    int n = arr.size();
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int p = i; p <= j; p++)
            {
                sum = sum + arr[p];
            }
            if (sum == d)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}

// Better approach
// Time complexity: O(n^2)
int longestSubarrayWithSumK_better(vector<int> arr, int d)
{
    int n = arr.size();
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if (sum == d)
            {
                length = max(length, j - i + 1);
            }
        }
    }
    return length;
}

// More better approach
//  Time complexity: O(n * log(n)) if we use map and O(n) if we use unordered_map, because map takes log(n) time to search an element and unordered_map takes O(1) time to search an element.
//  Space complexity: O(n)
int longestSubarrayWithSumK(vector<int> arr, long long d)
{
    map<long long, int> mp;
    long long sum = 0;
    int length = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == d)
        {
            length = i + 1;
        }
        long long rem = sum - d;
        if (mp.find(rem) != mp.end())
        {
            int l = i - mp[rem];
            length = max(length, l);
        }
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
    }
    return length;
}

// Optimal approach: Two pointer approach
int longestSubarrayWithSumK_optimal(vector<int> a, int k)
{
    int n = a.size();
    int left = 0, right = 0;
    long long sum = a[0];
    int max_len = 0;
    while (right < n)
    {
        while (sum > k && left <= right)
        {
            sum -= a[left];
            left++;
        }
        if (sum == k)
        {
            max_len = max(max_len, right - left + 1);
        }

        right++;
        sum += a[right];
    }
    return max_len;
}
// Time complexity: O(2n) and not O(n^2) because the right pointer will move at most n times and the left pointer will move at most n times. So, the time complexity is O(2n) which is O(n).

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value of d: ";
    int d;
    cin >> d;

    cout << "Length of longest subarray with sum d: " << longestSubarrayWithSumK(arr, d) << endl;

    return 0;
}