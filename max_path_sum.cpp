/*
Problem statement
You are given a binary tree with ‘N’ nodes.
Your task is to find the “Maximum Path Sum” for any path.
Note :
1. A ‘path’ is a sequence of adjacent pair nodes with an edge between them in the binary tree.
2. The ‘path’ doesn’t need to pass through the root.
3. The ‘path sum’ is the sum of the node’s data in that path.
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int heightOfBinaryTree(TreeNode<int> *root, int &maxi)
{
    // Write your code here.
    if (root == nullptr)
        return 0;

    int l = max(0, heightOfBinaryTree(root->left, maxi));
    int r = max(0, heightOfBinaryTree(root->right, maxi));
    maxi = max(maxi, l + r + root->val);
    int ht = root->val + max(l, r);

    return ht;
}
int maxPathSum(TreeNode<int> *root)
{
    // Write your code here.
    if (root->left == nullptr && root->right == nullptr)
        return root->val;
    int maxi = INT_MIN;
    heightOfBinaryTree(root, maxi);

    return maxi;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);

    cout << maxPathSum(root) << endl;
    return 0;
}