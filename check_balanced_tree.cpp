#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given the root node of a binary tree.
Return 'true' if it is a height balanced binary tree.
Note:
Height of a tree is the maximum number of nodes in a path from the node to the leaf node.

An empty tree is a height-balanced tree. A non-empty binary tree is a height-balanced binary tree if
1. The left subtree of a binary tree is already the height-balanced tree.
2. The right subtree of a binary tree is also the height-balanced tree.
3. The difference between heights of left subtree and right subtree must not more than ‘1’.
*/

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

int heightOfBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if (root == nullptr)
        return 0;

    int l = heightOfBinaryTree(root->left);
    int r = heightOfBinaryTree(root->right);
    if (l == -1)
        return -1;

    if (r == -1)
        return -1;
    if (abs(l - r) > 1)
        return -1;

    int ht = 1 + max(l, r);

    return ht;
}

bool isBalancedBT(TreeNode<int> *root)
{
    // Write your code here.
    return heightOfBinaryTree(root) != -1;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);
    root->right->left = new TreeNode<int>(6);
    root->right->right = new TreeNode<int>(7);
    root->right->right->right = new TreeNode<int>(8);

    cout << isBalancedBT(root) << endl;
    return 0;
}