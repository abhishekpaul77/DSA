/*
Binary trees: It is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child.

Binary tree representation:
1. Array representation
2. Linked list representation

Binary tree traversal:
1. Inorder traversal
2. Preorder traversal
3. Postorder traversal
4. Level order traversal

Binary search tree: A binary tree in which for each node, all elements in the left subtree are less than the node and all elements in the right subtree are greater than the node.

Binary search tree operations:
1. Insertion
2. Deletion
3. Searching
4. Traversal

Binary search tree traversal:
1. Inorder traversal
2. Preorder traversal
3. Postorder traversal
4. Level order traversal

Binary search tree applications:
1. Searching
2. Sorting
3. Expression evaluation
4. Huffman coding
5. Memory allocation

Binary search tree complexity:
1. Time complexity
2. Space complexity

Binary search tree implementation:
1. Using arrays
2. Using linked lists

Example of binary tree:
1. Expression tree
2. Huffman tree
3. Binary search tree
4. AVL tree
5. Red-black tree
6. Splay tree
7. B-tree
8. B+ tree
9. Segment tree

Terms related to binary trees:
1. Root: The topmost node in the tree.
2. Parent: A node that has children.
3. Child: A node that has a parent.
4. Sibling: Nodes that share the same parent.
5. Leaf: A node that has no children.
6. Internal node: A node that has children.
7. Depth: The level of a node in the tree.
8. Height: The maximum depth of the tree.
9. Subtree: A tree that is part of a larger tree.
10. Binary tree: A tree in which each node has at most two children.
11. Binary search tree: A binary tree in which for each node, all elements in the left subtree are less than the node and all elements in the right subtree are greater than the node.
12. Complete binary tree: A binary tree in which all levels are completely filled except possibly for the last level, which is filled from left to right.
13. Full binary tree: A binary tree in which each node has either zero or two children.
14. Perfect binary tree: A binary tree in which all levels are completely filled.
15. Balanced binary tree: A binary tree in which the height of the left and right subtrees of any node differ by at most one.
16. Degenerate tree: A tree in which each parent node has only one child.
17. Expression tree: A binary tree used to represent expressions.
18. Huffman tree: A binary tree used in Huffman coding.
19. AVL tree: A self-balancing binary search tree.
20. Red-black tree: A self-balancing binary search tree.
21. Splay tree: A self-adjusting binary search tree.
22. B-tree: A self-balancing tree data structure.
23. B+ tree: A self-balancing tree data structure.
24. Segment tree: A tree data structure used for range queries.
25. Inorder traversal: A depth-first traversal in which the left subtree is visited first, followed by the root, and then the right subtree.
26. Preorder traversal: A depth-first traversal in which the root is visited first, followed by the left subtree, and then the right subtree.
27. Postorder traversal: A depth-first traversal in which the left subtree is visited first, followed by the right subtree, and then the root.
28. Level order traversal: A breadth-first traversal in which nodes are visited level by level from left to right.

*/


#include<bits/stdc++.h>
using namespace std;

// Binary tree implementation using linked lists
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data){
    Node *newNode = new Node();
    if(!newNode){
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Print the tree
void printTree(Node *root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}



int main(){
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    cout << "Binary tree created: ";
    printTree(root);
    cout << "\n";

    
    return 0;
}