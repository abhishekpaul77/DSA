//Problem stament:Given N pairs of parentheses, write a function to generate and print all combinations of well-formed parentheses. That is, you need to generate all possible valid sets of parentheses that can be formed with a given number of pairs.


#include<bits/stdc++.h>
using namespace std;
//Type 1
void fun(vector<string>& ans, int n, int open, int close, string curr_str) {
    if (curr_str.size() == 2 * n) {
        ans.push_back(curr_str);
        return;
    }

    if (open <n) {
        fun(ans, n, open + 1, close, curr_str + "{");
    }
    if (close < open) {
        fun(ans, n, open, close + 1, curr_str + "}");
    }
}

void printParantheses(int n) {
    vector<string> ans;
    fun(ans, n, 0, 0, "");
    for (const string &str : ans) {
        cout << str << endl;
    }
}

//Type 2
// void fun(vector<string>& ans, int n, int open, int close, string curr_str) {
//     if (curr_str.size() == 2 * n) {
//         ans.push_back(curr_str);
//         return;
//     }

//     if (open < n) {
//         fun(ans, n, open + 1, close, curr_str + "(");
//     }
//     if (close < open) {
//         fun(ans, n, open, close + 1, curr_str + ")");
//     }
// }

// vector<string> validParenthesis(int n) {
//     vector<string> ans;
//     fun(ans, n, 0, 0, "");
//     return ans;
// }

int main(){
    int n;
    cin>>n;
    printParantheses(n);
    return 0;
}