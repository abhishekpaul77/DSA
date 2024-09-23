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

string serializeTree(TreeNode<int> *root)
{
    //    Write your code here for serializing the tree
    if (root == nullptr)
        return "";
    string s = "";

    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *r = q.front();
        q.pop();

        if (r == nullptr)
        {
            s.append("#,");
        }
        else
        {
            s.append(to_string(r->data) + ",");
        }

        if (r != nullptr)
        {
            q.push(r->left);
            q.push(r->right);
        }
    }

    return s;
}

TreeNode<int> *deserializeTree(string &serialized)
{
    //    Write your code here for deserializing the tree
    if (serialized.size() == 0)
        return nullptr;
    stringstream s(serialized);
    string ans;

    getline(s, ans, ',');
    TreeNode<int> *root = new TreeNode<int>(stoi(ans));
    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode<int> *r = q.front();
        q.pop();

        getline(s, ans, ',');
        if (ans == "#")
        {
            r->left = nullptr;
        }
        else
        {
            TreeNode<int> *node = new TreeNode<int>(stoi(ans));
            r->left = node;
            q.push(node);
        }

        getline(s, ans, ',');
        if (ans == "#")
        {
            r->right = nullptr;
        }
        else
        {
            TreeNode<int> *node = new TreeNode<int>(stoi(ans));
            r->right = node;
            q.push(node);
        }
    }

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

    string serialized = serializeTree(root);
    cout << serialized << endl;

    TreeNode<int> *deserialized = deserializeTree(serialized);
    queue<TreeNode<int> *> q;
    q.push(deserialized);

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