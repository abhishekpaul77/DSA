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

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
bool solve(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right)
{
    if (left == nullptr || right == nullptr)
    {
        return left == right;
    }
    if (left->data != right->data)
    {
        return false;
    }

    return solve(left->left, right->right) &&
           solve(left->right, right->left);
}

bool isSymmetric(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (root == nullptr)
        return true;

    return solve(root->left, root->right);
}

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(2);
    root->left->left = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(4);
    root->right->left = new BinaryTreeNode<int>(4);
    root->right->right = new BinaryTreeNode<int>(3);

    cout << isSymmetric(root) << endl;

    delete root;
    
    return 0;
}