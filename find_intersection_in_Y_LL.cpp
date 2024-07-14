#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int num;
    node *next;
    node(int val)
    {
        num = val;
        next = NULL;
    }
};
// utility function to insert node at the end of the linked list
void insertNode(node *&head, int val)
{
    node *newNode = new node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

// utility function to print linked list created
void printList(node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}

// Brute force approach
// Time complexity: O(n*m), where n and m are the number of nodes in the two linked lists
// Space complexity: O(1)
node *findIntersection_BF(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    int cnt1 = 0, cnt2 = 0;
    while (temp1 != NULL)
    {
        cnt1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        cnt2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    int diff = abs(cnt1 - cnt2); // Here the abs is used to get the absolute value of the difference between the two counts.
    if (cnt1 > cnt2)
    {
        while (diff--)
            temp1 = temp1->next;
    }
    else
    {
        while (diff--)
            temp2 = temp2->next;
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 == temp2)
            return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return NULL;
}

// Better solution: Hashing approach
// Time complexity: O(N)
// Space complexity: O(N)
node *findIntersection_Better(node *head1, node *head2)
{
    unordered_map<node *, int> mp;
    node *temp = head1;
    while (temp != NULL)
    {
        mp[temp] = 1;
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL)
    {
        if (mp.find(temp) != mp.end())
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// optimal solution: Two pointer approach
// Time complexity: O(2max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))
// Reason: Finding the length of both lists takes max(length of list1, length of list2) because it is found simultaneously for both of them. Moving the head pointer ahead by a difference of them. The next one is for searching.
// Space complexity: O(1)
node* findIntersection_Optimal(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    while(temp1!=temp2)
    {
        // temp1 = temp1==NULL?head2:temp1->next;
        // temp2 = temp2==NULL?head1:temp2->next;
        //OR
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2)
            return temp1;
        if(temp1==NULL)
            temp1 = head2;
        if(temp2==NULL)
            temp2 = head1;
    }
    return temp1;
}


int main()
{
    node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    node *head1 = head;
    head = head->next->next->next;
    node *headSec = NULL;
    insertNode(headSec, 3);
    node *head2 = headSec;
    headSec->next = head;
    // printing of the lists
    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);

    node *intersection = findIntersection_Optimal(head1, head2);
    if (intersection == NULL)
        cout << "No intersection found" << endl;
    else
        cout << "Intersection found at: " << intersection->num << endl;

    return 0;
}