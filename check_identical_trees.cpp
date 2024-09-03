/*
Problem statement
You are given two binary trees with 'n' and 'm' nodes respectively.
You need to return true if the two trees are identical. Otherwise, return false.
*/

#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool identicalTrees(BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
    if (p == nullptr || q == nullptr)
        return (p == q);

    return p->data == q->data && identicalTrees(p->left, q->left) && identicalTrees(p->right, q->right);
}

int main()
{
    BinaryTreeNode<int> *root1 = new BinaryTreeNode<int>(1);
    root1->left = new BinaryTreeNode<int>(2);
    root1->right = new BinaryTreeNode<int>(3);
    root1->left->left = new BinaryTreeNode<int>(4);
    root1->left->right = new BinaryTreeNode<int>(5);

    BinaryTreeNode<int> *root2 = new BinaryTreeNode<int>(1);
    root2->left = new BinaryTreeNode<int>(2);
    root2->right = new BinaryTreeNode<int>(3);
    root2->left->left = new BinaryTreeNode<int>(4);
    root2->left->right = new BinaryTreeNode<int>(5);

    cout << identicalTrees(root1, root2) << endl;
    return 0;
}