/*
Problem statement
Given a string S containing digits from 2 to 9 inclusive. Your task is to find all possible letter combinations that the number could represent.
A mapping from Digits to Letters (just like in Nokia 1100) is shown below. Note that 1 does not map to any letter.
*/

#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(4^n) because for each digit we have 4 choices. So, the time complexity is O(4^n).
// The 4 choices are:
// 1. a
// 2. b
// 3. c
// 4. ""
// So, the time complexity is O(4^n).
// Space complexity: O(n) because we are using a vector to store the combination of size n. So, the space complexity is O(n).

void solve(string& s,vector<string> &ans,string& ds,int ind,string mpp[]){
	if(ind>=s.length()){
		ans.push_back(ds);
		return;
	}

	int num=s[ind]-'0';
	string val=mpp[num];

	for(int i=0;i<val.length();i++){
		ds.push_back(val[i]);
		solve(s, ans, ds, ind+1, mpp);
		ds.pop_back();
	}

}

vector<string> combinations(string s){
	vector<string> ans;
	string ds;

	string mpp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

	solve(s, ans, ds, 0, mpp);

	return ans;
	
}

int main(){
    string s;
    cin>>s;

    vector<string> ans = combinations(s);

    for(auto it:ans){
        cout<<it<<endl;
    }

    return 0;
}