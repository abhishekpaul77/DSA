#include <bits/stdc++.h>
using namespace std;

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

TreeNode<int> *findLCA(TreeNode<int> *root, int x, int y)
{
    // Base case: if the root is null, return null
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == x || root->data == y)
    {
        return root;
    }
    TreeNode<int> *l = findLCA(root->left, x, y);
    TreeNode<int> *r = findLCA(root->right, x, y);
    if (l == NULL)
        return r;
    else if (r == NULL)
        return l;
    else
        return root;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    TreeNode<int> *ans = findLCA(root, x, y);
    return ans->data;
}
int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(5);


    cout << lowestCommonAncestor(root, 4, 5) << endl;
    return 0;
}