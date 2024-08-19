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

vector<int> bottomView(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == nullptr)
        return ans;
    map<int, int> mp;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        auto *temp = it.first;
        int line = it.second;
        mp[line] = temp->data;
        if (temp->left != nullptr)
            q.push({temp->left, line - 1});
        if (temp->right != nullptr)
            q.push({temp->right, line + 1});
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    root->left = new TreeNode<int>(2);
    root->right = new TreeNode<int>(3);
    root->left->right = new TreeNode<int>(4);
    root->left->right->right = new TreeNode<int>(5);
    root->left->right->right->right = new TreeNode<int>(6);

    vector<int> ans = bottomView(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}