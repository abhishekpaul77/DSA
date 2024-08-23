/*
Problem statement
You have been given a Binary Tree of 'n' nodes, where the nodes have integer values. Your task is to return the In-Order traversal of the given binary tree.
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left),
                                                       right(right) {}
};


// Time complexity: O(n)
// Space complexity: O(n)

void solve(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    solve(root->left, ans);
    ans.push_back(root->data);
    solve(root->right, ans);

    return;
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    solve(root, ans);

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    vector<int> result = getInOrderTraversal(root);
    return 0;
}