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

TreeNode<int> *build(vector<int> &inorder, int inS, int inE, map<int, int> &mp,
                     vector<int> &preorder, int preS, int preE)
{
    if (preS > preE || inS > inE)
        return nullptr;
    TreeNode<int> *root = new TreeNode<int>(preorder[preS]);

    int inInd = mp[root->data];
    int left = inInd - inS;

    root->left = build(inorder, inS, inInd - 1, mp, preorder, preS + 1, preS + left);
    root->right = build(inorder, inInd + 1, inE, mp, preorder, preS + 1 + left, preE);

    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    TreeNode<int> *root = build(inorder, 0, inorder.size() - 1, mp, preorder, 0,
                                preorder.size() - 1);
    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<int> in(n), pre(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    TreeNode<int> *root = buildBinaryTree(in, pre);

    queue<TreeNode<int> *> q;
    q.push(root);



    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();
        cout << f->data << ":";
        if (f->left)
        {
            cout << "L:" << f->left->data << ",";
            q.push(f->left);
        }
        if (f->right)
        {
            cout << "R:" << f->right->data;
            q.push(f->right);
        }
        cout << endl;
    }

    return 0;
}