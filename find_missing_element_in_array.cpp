#include <bits/stdc++.h>
using namespace std;

// Brute force approach
//  Time complexity: O(n^2)
int find_missing_element(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
}

// Hashing approach
// Time complexity: O(n)
// Space complexity: O(n)

int find_missing_element_hash(int arr[], int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}

// Using sum of n natural numbers
//  Time complexity: O(n)
int find_missing_element_sum(int arr[], int n)
{
    int sum = n * (n + 1) / 2;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + arr[i];
    }
    int missing_elemnt = sum - s;
    return missing_elemnt;
}

// Using XOR operation
//  Time complexity: O(n)
int find_missing_element_xor(int arr[], int N)
{
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < N-1; i++) {
        xor1 =xor1 ^ (i + 1);
        xor2 = xor2 ^ arr[i];
    }
    xor1 = xor1 ^ (N);
    int missing_element = xor1 ^ xor2;
    return missing_element;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element " << i + 1 << ": ";
        cin >> arr[i];
    }
    // cout<<"The missing element is: "<<find_missing_element(arr,n);
    // cout<<"The missing element is: "<<find_missing_element_hash(arr,n);
    // cout<<"The missing element is: "<<find_missing_element_sum(arr,n);
    cout << "The missing element is: " << find_missing_element_xor(arr, n);

    return 0;
}