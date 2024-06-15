#include<bits/stdc++.h>
using namespace std;

// Linked list is a data structure that stores a collection of elements, called nodes, each pointing to the next node by means of a pointer.
// It is a linear data structure, where elements are not stored at contiguous memory locations.
// The elements in a linked list are linked using pointers.

// Advantages of Linked List:
// 1. Dynamic Data Structure
// 2. Efficient Memory Allocation
// 3. Insertion and Deletion Operations

// Disadvantages of Linked List:
// 1. Random access is not allowed. We have to access elements sequentially starting from the first node.
// 2. Extra memory space for a pointer is required with each element of the list.
// 3. Not cache friendly. Since array elements are contiguous locations, there is locality of reference which is not there in case of linked lists. In simpler terms this means that the elements in an array are stored in contiguous locations, so whenever we access an element, the elements near it are also accessed and loaded into the cache memory. This is not the case with linked lists.

// Types of Linked List:
// 1. Singly Linked List
// 2. Doubly Linked List
// 3. Circular Linked List

// Singly Linked List:
// A singly linked list is a collection of nodes where each node stores a reference to an element and a reference to the next node of the list.
// The first node is called the head and the last node is called the tail.
// The tail node points to NULL, indicating the end of the list.

// Doubly Linked List:
// A doubly linked list is a collection of nodes where each node stores a reference to an element and a reference to the next node of the list and a reference to the previous node of the list.
// The first node is called the head and the last node is called the tail.
// The head node points to NULL in the previous part and the tail node points to NULL in the next part, indicating the end of the list.

// Circular Linked List:
// A circular linked list is a collection of nodes where each node stores a reference to an element and a reference to the next node of the list.
// The last node points to the first node, forming a circular chain.

// Operations on Linked List:
// 1. Insertion
// 2. Deletion
// 3. Traversal
// 4. Searching
// 5. Sorting
// 6. Merging


// Node Structure
class Node{
    public:
        int data;
        Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = NULL;
    }

};

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    //Ways to create a linked list
    // 1. Normal way
    // Node x=Node(1,nullptr);
    // Node* y=&x;
    // 2. Using new keyword
    Node* y=new Node(arr[0]);
    cout<<y->data<<endl; 
    return 0;
}