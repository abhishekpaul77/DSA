/*
Problem statement
You are given a string 'S'. Your task is to partition 'S' such that every substring of the partition is a palindrome. You need to return all possible palindrome partitioning of 'S'.
Note: A substring is a contiguous segment of a string.
For Example:
For a given string “BaaB”
3 possible palindrome partitioning of the given string are:
{“B”, “a”, “a”, “B”}
{“B”, “aa”, “B”}
{“BaaB”}
Every substring of all the above partitions of “BaaB” is a palindrome.
*/

#include<bits/stdc++.h>
using namespace std;

Time Complexity: O( (2^n) *k*(n/2) )

/*
Time Complexity: O( (2^n) *k*(n/2) )
Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

Space Complexity: O(k * x)
Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
*/
bool isPalindrome(string &s,int start,int end){
    while(start<=end){
        if(s[start++]!=s[end--])  return false;
    }

    return true;
}

void solve(int ind,vector<vector<string>>& ans,vector<string> &ds,string &s){
    if(ind==s.length()){
        ans.push_back(ds);
        return ;
    }   

    for(int i=ind;i<s.length();i++){
        if (isPalindrome(s, ind, i)) {
          ds.push_back(s.substr(ind, i - ind + 1));
          solve(i + 1, ans, ds, s);
          ds.pop_back();
        }
    }

}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> ds;
    solve(0, ans, ds, s);
    return ans;
}


int main(){
    string s;
    cin>>s;
    vector<vector<string>> ans=partition(s);
    for(auto x:ans){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}