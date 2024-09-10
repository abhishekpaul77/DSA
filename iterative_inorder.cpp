#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> st;
        TreeNode *r = root;
        while (true)
        {
            if (r != nullptr)
            {
                st.push(r);
                r = r->left;
            }
            else
            {
                if (st.empty() == true)
                    break;
                r = st.top();
                st.pop();
                ans.push_back(r->val);
                r = r->right;
            }
        }
        return ans;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);

    root->right = new TreeNode(2);

    root->right->left = new TreeNode(3);

    Solution s;

    vector<int> result = s.inorderTraversal(root);

    return 0;
}