#include<bits/stdc++.h>
using namespace std;

// Bruteforce approach
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){
    vector<int> intersection;
	int size=max(n,m);
	int taken[size]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr1[i]==arr2[j] && taken[j]==0){
				intersection.push_back(arr1[i]);
				taken[j]=1;
				break;
			}
			if(arr2[j]>arr1[i])break;
		}
	}
	return intersection;
}



int main(){
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


    return 0;
}