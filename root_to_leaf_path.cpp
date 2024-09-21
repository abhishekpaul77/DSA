#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void solve(BinaryTreeNode<int> *root, vector<string> &ans, string path)
{
    if (root == nullptr)
    {
        return;
    }

    // Append current node to the path

    path += to_string(root->data) + " ";

    // Check if the current node is a leaf node
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(path);
        return;
    }

    // Recursive calls for left and right subtrees
    solve(root->left, ans, path);
    solve(root->right, ans, path);
}

vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
{
    vector<string> ans;
    solve(root, ans, "");
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(7);


    vector<string> ans = allRootToLeaf(root);
    for (string s : ans)
    {
        cout << s << endl;
    }
    return 0;
}