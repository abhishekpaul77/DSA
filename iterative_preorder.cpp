#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *r = st.top();
            st.pop();
            ans.push_back(r->val);
            if (r->right != nullptr)
                st.push(r->right);
            if (r->left != nullptr)
                st.push(r->left);
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

    vector<int> result = s.preorderTraversal(root);

    return 0;
}