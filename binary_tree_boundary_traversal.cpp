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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};


/*
Time Complexity: O(N) where N is the number of nodes in the Binary Tree.

Adding the left boundary of the Binary Tree results in the traversal of the left side of the tree which is proportional to the the height of the three hence O(H) ie. O(log2N). In the worst case that the tree is skewed the complexity would be O(N).
For the bottom traversal of the Binary Tree, traversing the leaves is proportional to O(N) as preorder traversal visits every node once.
Adding the right boundary of the Binary Tree results in the traversal of the right side of the tree which is proportional to the the height of the three hence O(H) ie. O(log2N). In the worst case that the tree is skewed the complexity would be O(N).
Since all these operations are performed sequentially, the overall time complexity is dominated by the most expensive operation, which is O(N).

Space Complexity: O(N) where N is the number of nodes in the Binary Tree to store the boundary nodes of the tree. O(H) or O(log2N) Recursive stack space while traversing the tree. In the worst case scenario the tree is skewed and the auxiliary recursion stack space would be stacked up to the maximum depth of the tree, resulting in an O(N) auxiliary space complexity.
*/
bool isLeaf(TreeNode<int> *root)
{
    return (!root->left && !root->right);
}

void addLeft(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *r = root->left;
    while (r)
    {
        if (!isLeaf(r))
            ans.push_back(r->data);
        if (r->left)
            r = r->left;
        else
            r = r->right;
    }
}

void addLeaf(TreeNode<int> *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaf(root->left, ans);
    if (root->right)
        addLeaf(root->right, ans);
}

void addRight(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *r = root->right;
    vector<int> temp;
    while (r)
    {
        if (!isLeaf(r))
            temp.push_back(r->data);
        if (r->right)
            r = r->right;
        else
            r = r->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (root == nullptr)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->data);
    addLeft(root, ans);
    addLeaf(root, ans);
    addRight(root, ans);

    return ans;
}

int main()
{
    TreeNode<int> *root = new TreeNode<int>(20);
    root->left = new TreeNode<int>(8);
    root->right = new TreeNode<int>(22);
    root->left->left = new TreeNode<int>(4);
    root->left->right = new TreeNode<int>(12);
    root->left->right->left = new TreeNode<int>(10);
    root->left->right->right = new TreeNode<int>(14);

    vector<int> ans = traverseBoundary(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    delete root;

        return 0;
}