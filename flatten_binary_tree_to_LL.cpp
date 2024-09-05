#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T dat)
    {
        this->data = dat;
        left = NULL;
        right = NULL;
    }
};

// Using recursion
// Time Complexity: O(n)
// Space Complexity: O(n)
void flattenBinaryTree_R(TreeNode<int> *root)
{
    // Write your code here.
    if (root == nullptr)
    {
        return;
    }
    flattenBinaryTree(root->left);
    flattenBinaryTree(root->right);
    TreeNode<int> *temp = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right != nullptr)
    {
        root = root->right;
    }
    root->right = temp;
}

// Using stack
// Time Complexity: O(n)
// Space Complexity: O(n)
void flattenBinaryTree_S(TreeNode<int> *root)
{
    // Write your code here.
    if (root == nullptr)
    {
        return;
    }
    stack<TreeNode<int> *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode<int> *cur = st.top();
        st.pop();
        if (cur->right != nullptr)
        {
            st.push(cur->right);
        }
        if (cur->left != nullptr)
        {
            st.push(cur->left);
        }
        if (!st.empty())
        {
            cur->right = st.top();
        }
        cur->left = nullptr;
    }
}

// Using Morris Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)
void flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *cur = root;
    TreeNode<int> *prev;
    while (cur != nullptr)
    {
        if (cur->left != nullptr)
        {
            prev = cur->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}
int main()
{
    // Creating the tree
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(5);
    root->left->left = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->right->right = new TreeNode<int>(6);

    // Using recursion
    flattenBinaryTree_R(root);

    // Using stack
    flattenBinaryTree_S(root);

    // Using Morris Traversal
    flattenBinaryTree(root);

    return 0;
}