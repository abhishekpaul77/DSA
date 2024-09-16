#include <bits/stdc++.h>
using namespace std;

// Morris traversal is a way to traverse the tree without using any extra space.
// It is a way to traverse the tree in O(n) time complexity and O(1) space complexity.

// 1. Inorder Traversal
// 2. Preorder

// Class for the node of the tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Inorder Traversal
vector<int> morrisInorderTraversal(Node *root)
{
    vector<int> inorder;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

// Preorder
vector<int> morrisPreorderTraversal(Node *root)
{
    vector<int> preorder;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                preorder.push_back(curr->data);
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preorder;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> inorder = morrisInorderTraversal(root);
    vector<int> preorder = morrisPreorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl

                cout
         << "Preorder Traversal: ";
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
    }
    cout << endl;

    return 0;
}