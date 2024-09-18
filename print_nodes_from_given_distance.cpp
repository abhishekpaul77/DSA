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

void parentMark(TreeNode<int> *root, map<TreeNode<int> *, TreeNode<int> *> &parent)
{
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *r = q.front();
        q.pop();
        if (r->left)
        {
            parent[r->left] = r;
            q.push(r->left);
        }
        if (r->right)
        {
            parent[r->right] = r;
            q.push(r->right);
        }
    }
}

vector<int> kDistance(TreeNode<int> *root, int target, int k)
{
    vector<int> ans;
    if (root == nullptr)
        return ans;

    // Map to track parent nodes
    map<TreeNode<int> *, TreeNode<int> *> parent;
    parentMark(root, parent);

    // Finding the target node
    TreeNode<int> *targetN = nullptr;
    queue<TreeNode<int> *> que;
    que.push(root);

    while (!que.empty())
    {
        TreeNode<int> *r = que.front();
        que.pop();

        if (r->data == target)
        {
            targetN = r;
            break;
        }

        if (r->left)
        {
            que.push(r->left);
        }

        if (r->right)
        {
            que.push(r->right);
        }
    }

    if (targetN == nullptr)
    {
        return ans;
    }

    // BFS to find nodes at distance k
    map<TreeNode<int> *, bool> vis;
    queue<TreeNode<int> *> q;
    q.push(targetN);
    vis[targetN] = true;
    int dist = 0;

    while (!q.empty())
    {
        if (dist == k)
            break;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode<int> *r = q.front();
            q.pop();

            if (r->left && !vis[r->left])
            {
                q.push(r->left);
                vis[r->left] = true;
            }

            if (r->right && !vis[r->right])
            {
                q.push(r->right);
                vis[r->right] = true;
            }

            if (parent[r] && !vis[parent[r]])
            {
                q.push(parent[r]);
                vis[parent[r]] = true;
            }
        }

        dist++;
    }

    // Collecting nodes at distance k
    while (!q.empty())
    {
        ans.push_back(q.front()->data);
        q.pop();
    }

    return ans;
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
    root->right->left->left = new TreeNode<int>(12);
    root->right->left->right = new TreeNode<int>(13);

    vector<int> ans = kDistance(root, 2, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}