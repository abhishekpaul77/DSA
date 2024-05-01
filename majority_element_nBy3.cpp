#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach
//Time Complexity: O(n^2)
//Space Complexity: O(1)
vector<int> majorityElement_BF(vector<int> v) {
	// Write your code here
	int n=v.size();
	int original=n/3;
	vector<int> ans;
	
for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already
        // a part of the answer:
        if (ans.size() == 0 || ans[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > original)
                ans.push_back(v[i]);
        }

        if (ans.size() == 2) break;
    }
return ans;
}

// Using hashmap
//Time Complexity: O(n)
//Space Complexity: O(n)
vector<int> majorityElement_hash(vector<int> v) {
	// Write your code here
	int n=v.size();
	int original=(n/3)+1;
	vector<int> ans;
	unordered_map<int,int> mp;

	for(int i=0;i<n;i++){
		mp[v[i]]++;
		if(mp[v[i]]==original){
			ans.push_back(v[i]);
		}
		if(ans.size()==2)break;
	}

	sort(ans.begin(),ans.end());
	return ans;

}

// Using Boyer-Moore Voting Algorithm
//Time Complexity: O(n)
//Space Complexity: O(1)
vector<int> majorityElement(vector<int> v) {
	// Write your code here
	int n=v.size();
	int original=(n/3)+1;
	vector<int> ans;
	int el1=0,el2=0;
	int cnt1=0,cnt2=0;

	
	for(int i=0;i<n;i++){
		if(cnt1==0 && el2!=v[i]){
			cnt1=1;
			el1=v[i];
		}
		else if(cnt2==0 && el1!=v[i]){
			cnt2=1;
			el2=v[i];
		}
		else if (v[i]==el1)cnt1++;
		else if (v[i]==el2)cnt2++;
		else cnt1--,cnt2--;
	}

	cnt1=0,cnt2=0;

	for(int i=0;i<n;i++){
		if(el1==v[i])cnt1++;
		if(el2==v[i])cnt2++;
	}
	if(cnt1>=original)ans.push_back(el1);
	if(cnt2>=original)ans.push_back(el2);
	sort(ans.begin(),ans.end());
	
	return ans;

}


int main(){
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