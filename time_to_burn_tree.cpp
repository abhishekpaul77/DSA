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

void parentMark(BinaryTreeNode<int> *root, map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent)
{
    if (root == nullptr)
        return;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *r = q.front();
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

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    if (root == nullptr)
        return 0;

    // Map to track parent nodes
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent;
    parentMark(root, parent);

    // Finding the target node
    BinaryTreeNode<int> *targetN = nullptr;
    queue<BinaryTreeNode<int> *> que;
    que.push(root);

    while (!que.empty())
    {
        BinaryTreeNode<int> *r = que.front();
        que.pop();

        if (r->data == start)
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
        return 0; // Start node not found
    }

    // BFS to calculate time to burn the entire tree
    map<BinaryTreeNode<int> *, bool> vis;
    queue<BinaryTreeNode<int> *> q;
    q.push(targetN);
    vis[targetN] = true;

    int timer = 0;

    while (!q.empty())
    {
        int size = q.size();
        bool burned = false;

        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *r = q.front();
            q.pop();

            if (r->left && !vis[r->left])
            {
                q.push(r->left);
                vis[r->left] = true;
                burned = true; // Node burns, so increment timer
            }

            if (r->right && !vis[r->right])
            {
                q.push(r->right);
                vis[r->right] = true;
                burned = true; // Node burns, so increment timer
            }

            if (parent[r] && !vis[parent[r]])
            {
                q.push(parent[r]);
                vis[parent[r]] = true;
                burned = true; // Node burns, so increment timer
            }
        }

        if (burned)
        {
            timer++; // Increment timer for each level where burning occurs
        }
    }

    return timer;
}
int main()
{
    // Create a tree
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    root->left->left = new BinaryTreeNode<int>(4);
    root->left->right = new BinaryTreeNode<int>(5);
    root->left->right->left = new BinaryTreeNode<int>(6);
    root->left->right->right = new BinaryTreeNode<int>(7);
    root->left->right->right->left = new BinaryTreeNode<int>(8);
    root->left->right->right->right = new BinaryTreeNode<int>(9);

    cout << timeToBurnTree(root, 5) << endl;

    
    return 0;
}