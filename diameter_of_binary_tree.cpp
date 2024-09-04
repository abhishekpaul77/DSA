#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given a Binary Tree.
Return the length of the diameter of the tree.
Note :
The diameter of a binary tree is the length of the longest path between any two end nodes in a tree.
The number of edges between two nodes represents the length of the path between them.
*/

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int heightOfBinaryTree(TreeNode<int> *root, int &maxi)
{
    // Write your code here.
    if (root == nullptr)
        return 0;

    int l = heightOfBinaryTree(root->left, maxi);
    int r = heightOfBinaryTree(root->right, maxi);
    maxi = max(maxi, l + r);
    int ht = 1 + max(l, r);

    return ht;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int maxi = 0;
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
    root->right->right = new TreeNode<int>(7);
    root->left->left->left = new TreeNode<int>(8);
    root->left->left->right = new TreeNode<int>(9);
    root->left->right->left = new TreeNode<int>(10);
    root->left->right->right = new TreeNode<int>(11);

    cout << diameterOfBinaryTree(root) << endl;

    return 0;
}