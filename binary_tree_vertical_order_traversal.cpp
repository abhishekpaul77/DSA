#include <bits/stdc++.h>
using namespace std;


template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};


vector<int> verticalOrderTraversal(TreeNode<int> *root)

{

    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, map<int, vector<int>>> nodes;

    // to fulfill this "If two nodes have the same position, then the value of the node that is added first will be the value that is on the left side."

    // we will use level order traversal

    queue<pair<TreeNode<int> *, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while (!q.empty())
    {

        pair<TreeNode<int> *, pair<int, int>> temp = q.front();

        q.pop();

        TreeNode<int> *frontNode = temp.first;

        int hd = temp.second.first; // hd = horizontal distance

        int lvl = temp.second.second; // lvl = level of node

        if (frontNode != NULL)
        {

            nodes[hd][lvl].push_back(frontNode->data);
        }

        if (frontNode->left)

            q.push({frontNode->left, {hd - 1, lvl + 1}});

        if (frontNode->right)

            q.push({frontNode->right, {hd + 1, lvl + 1}});
    }

    for (auto i : nodes)
    { // i will give <int,map<>>

        for (auto j : i.second)
        { // j will give <int, vector<>>

            for (auto k : j.second)
            { // k will give elements of vector

                ans.push_back(k);
            }
        }
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
    root->right->left->right = new TreeNode<int>(8);

    vector<int> ans = verticalOrderTraversal(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    delete root;
    return 0;
}