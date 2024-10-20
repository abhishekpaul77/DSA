#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
TreeNode *solve(vector<int> &preOrder, int &i, int ub)
{
    if (i >= preOrder.size() || preOrder[i] > ub)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preOrder[i]);
    i++; // increment i to move to the next element

    root->left = solve(preOrder, i, root->data);
    root->right = solve(preOrder, i, ub);
    return root;
}

TreeNode *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int i = 0;
    int ub = INT_MAX;
    return solve(preOrder, i, ub);
}

int main()
{
    vector<int> preOrder = {8, 5, 1, 7, 10, 12};
    TreeNode *root = preOrderTree(preOrder);
    return 0;
}
