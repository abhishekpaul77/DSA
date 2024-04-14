#include <bits/stdc++.h>
using namespace std;

// Brute force approach
#include <bits/stdc++.h>
void sortArray(vector<int> &arr, int n)
{

    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            count_0++;
        }
        else if (arr[i] == 1)
        {
            count_1++;
        }
        else
        {
            count_2++;
        }
    }

    arr.clear();

    for (int i = 0; i < count_0; i++)
    {
        arr.push_back(0);
    }
    for (int i = 0; i < count_1; i++)
    {
        arr.push_back(1);
    }
    for (int i = 0; i < count_2; i++)
    {
        arr.push_back(2);
    }
}

// Optimized approach: Dutch National Flag Algorithm
// Time complexity: O(n)
// Space complexity: O(1)
// The idea is to use three pointers to divide the array into four sections: 0, 1, 2, and unknown.
// The unknown section is the section that we have not yet traversed.
// The unknown section is divided into two parts: the left part and the right part. The left part is the part that contains 0, and the right part is the part that contains 2.
// The left pointer points to the end of the 0 section, and the right pointer points to the beginning of the 2 section.
// The middle pointer is used to traverse the unknown section.
// If the middle pointer points to 0, we swap the element at the middle pointer with the element at the left pointer and increment both the middle and left pointers.
// If the middle pointer points to 1, we increment the middle pointer.
// If the middle pointer points to 2, we swap the element at the middle pointer with the element at the right pointer and decrement the right pointer.

void sortArray_DNFA(vector<int> &arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    return 0;
}