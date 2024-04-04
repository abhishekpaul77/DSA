#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// Time complexity: O(n^2)
int majorityElement(vector<int> v)
{
    int n = v.size();
    int check = n / 2;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[i] == v[j])
            {
                count++;
            }
        }
        if (count >= check)
        {
            return v[i];
        }
    }
}

// Better solution: hashing
// Time complexity: O(N log N) (for sorting) + O(N) (for traversing) = O(N log N)
int majorityElement_hashing(vector<int> v) {
  // Write your code here
  int n = v.size();
  int check = n / 2;
  map<int,int> mp;

  for(int i=0;i<n;i++){
	  mp[v[i]]++;
  }
  for(auto it: mp){
	  if(it.second>=check){
		  return it.first;
	  }
  }
}

// Optimal solution: Boyer-Moore Voting Algorithm
// Time complexity: O(N)
// Space complexity: O(1)
// The idea is to use two variables, candidate and count. The candidate variable stores the current candidate for the majority element, and the count variable stores the count of the current candidate.
// Initially, the candidate variable is set to the first element of the array, and the count variable is set to 1.
// We then iterate through the array, starting from the second element.
// If the current element is equal to the candidate element, we increment the count variable.
// If the current element is not equal to the candidate element, we decrement the count variable.
// If the count variable becomes 0, we update the candidate variable to the current element and set the count variable to 1.
// At the end of the iteration, the candidate variable will contain the majority element.
// We then iterate through the array again to count the occurrences of the candidate element.
// If the count of the candidate element is greater than n/2, we return the candidate element as the majority element.
// If the count of the candidate element is less than or equal to n/2, we return -1, indicating that there is no majority element.
int majorityElement_BMVA(vector<int> v) {
  int n = v.size();
  int el = v[0];
  int count = 0;
  int check = n / 2;
  for (int i = 0; i < n; i++) {
    if (v[i] == el) {
      count++;
    } else {
      count--;
    }
    if (count == 0) {
      el = v[i + 1];
    }
  }
  count = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == el) {
      count++;
    }
  }
  if (count > check) {
    return el;
  }
}

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

    return 0;
}