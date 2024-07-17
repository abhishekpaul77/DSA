#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

// Brute force approach: Hasing
// Time complexity:O(N * 2 * log(N) )The algorithm traverses the linked list once, performing hashmap insertions and searches in the while loop for each node. The insertion and search operations in the unordered_map have a worst-case time complexity of O(log(N)). As the loop iterates through N nodes, the total time complexity is determined by the product of the traversal (O(N)) and the average-case complexity of the hashmap operations (insert and search), resulting in O(N * 2 * log(N)).
// Space complexity: O(n)
int findLength_BF(Node *head)
{
    unordered_map<Node *, int> mp;
    int timer = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        if (mp.find(temp) != mp.end())
        {
            int value = mp[temp];
            return timer - value;
        }
        mp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

// Optimized approach: Tortoise and Hare algorithm
// Time complexity: O(N)
// Space complexity: O(1)

int length(Node* slow, Node* fast){
    int count = 1;
    fast=fast->next;
    while(slow != fast){
        count++;
        fast= fast->next;
    }
    return count;
}

int findLength(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return length(slow, fast); 
        }
    }
    return 0;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // Create a loop
    fifth->next = third;

    // Check if there is a loop
    // n the linked list
    if (findLength(head))
    {
        cout <<findLength(head) << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }

    // Clean up memory (free the allocated nodes)
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
