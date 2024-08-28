#include <bits/stdc++.h>
using namespace std;

template <typename T>

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

vector<int> solve(BinaryTreeNode<int> *root, int level, vector<int> &ans)
{
    if (root == nullptr)
        return ans;

    if (level == ans.size())
        ans.push_back(root->data);

    // Right view
    solve(root->right, level + 1, ans);
    solve(root->left, level + 1, ans);

    /*
    // Left view
    solve(root->left, level + 1, ans);
    solve(root->right, level + 1, ans);
    */

    return ans;
}

vector<int> printRightView(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == nullptr)
        return ans;
    solve(root, 0, ans);

    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->right = new BinaryTreeNode<int>(4);
    root->left->right->right = new BinaryTreeNode<int>(5);
    root->left->right->right->right = new BinaryTreeNode<int>(6);

    vector<int> ans = printRightView(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}