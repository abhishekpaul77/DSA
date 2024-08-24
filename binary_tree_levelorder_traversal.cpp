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

// Time complexity: O(n)
// Space complexity: O(n)
vector<int> levelOrder(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == nullptr)
        return ans;

    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *r = q.front();
            q.pop();
            if (r->left != nullptr)
                q.push(r->left);
            if (r->right != nullptr)
                q.push(r->right);
            ans.push_back(r->data);
        }
    }

    return ans;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);

    vector<int> result = levelOrder(root);
    return 0;
}