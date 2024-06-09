#include<bits/stdc++.h>
using namespace std;

// Problem statement: Given two sorted arrays, find the median of the two sorted arrays.

// Brute force approach
// Time complexity: O(n1 + n2)
// Space complexity: O(n1 + n2)
// In this approach, we first merge the two sorted arrays into a single sorted array.
// Then we find the median of the merged array and return it.
// This approach requires extra space to store the merged array.
// This approach is not efficient as it requires extra space to store the merged array.
double median_BF(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < n1) arr3.push_back(a[i++]);
    while (j < n2) arr3.push_back(b[j++]);

    //Find the median:
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}

// Better approach
// Time complexity: O(n1 + n2)
// Space complexity: O(1)
// This approach is better than the brute force approach as it does not require any extra space.
// In this solution, we first find the required indices of the median elements.
// Then we apply the merge step of the merge sort algorithm to find the median elements.
// Finally, we find the median of the two elements and return it.
double median_Better(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

// Optimal approach: Binary search
// Time complexity: O(log(min(n1, n2)))
// Space complexity: O(1)
// This approach is the most efficient as it uses binary search to find the median of two sorted arrays.
// Explanation of the approach:
// 1. We need to find the partition of the two arrays such that the elements on the left side of the partition are less than the elements on the right side.
// 2. We can find the partition by using binary search on the smaller array.
// 3. Let's say we have two arrays A and B of sizes n1 and n2, where n1 <= n2.
// 4. We can find the partition of the smaller array A at index i such that the elements on the left side of A[i] are less than the elements on the right side.
// 5. Now, we need to find the partition of the larger array B at index j such that the elements on the left side of B[j] are less than the elements on the right side.
// 6. The median of the two arrays will be the maximum of the left elements and the minimum of the right elements.
// 7. If the total number of elements is odd, the median will be the maximum of the left elements.
// 8. If the total number of elements is even, the median will be the average of the maximum of the left elements and the minimum of the right elements.
// 9. We can find the partition of the two arrays by using binary search on the smaller array A.
// 10. We can calculate the partition of the larger array B based on the partition of the smaller array A.
// 11. We can check if the elements on the left side of A[i] are less than the elements on the right side of B[j] and vice versa.
// 12. If the elements on the left side of A[i] are less than the elements on the right side of B[j] and vice versa, we have found the correct partition.
// 13. If the elements on the left side of A[i] are greater than the elements on the right side of B[j], we need to move the partition to the left side of A[i].
// 14. If the elements on the left side of A[i] are less than the elements on the right side of B[j], we need to move the partition to the right side of A[i].
// 15. We can repeat the binary search process until we find the correct partition.
// 16. Once we find the correct partition, we can calculate the median based on the elements on the left and right sides of the partition.
// 17. We can return the median as the final answer.
// This approach has a time complexity of O(log(min(n1, n2))) and a space complexity of O(1).
// This approach is the most efficient and optimal solution to find the median of two sorted arrays.
double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    if(n1>n2) return median(b, a);

    int n = n1 + n2; //total length
    int low=0,high=n1;
    int left=(n1+n2+1)/2;

    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;

        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;

        if(mid1 < n1) r1=a[mid1];
        if(mid2< n2) r2=b[mid2];
        if(mid1-1 >= 0) l1=a[mid1-1];
        if(mid2-1 >=0) l2=b[mid2-1];

        if(l1<=r2 && l2<=r1){
            if(n%2==1) return max(l1,l2);
            else{
                return ((double)(max(l1,l2) + min(r1,r2)))/2.0;
            }
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }
        return 0;

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