#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Brute force approach
// Time complexity: O(N^2)
// Space complexity: O(1)
vector<pair<int,int>> findPairsWithGivenSum_BF(Node *head, int sum){
    Node* first = head;
    Node* second=head->next;
    vector<pair<int,int>> res;
    while(first->next!=NULL){
        while(second!=NULL){
            if(first->data+second->data==sum){
                res.push_back({first->data,second->data});
            }
            second=second->next;
        }
        first=first->next;
        second=first->next;
    }
    return res;
}

// Optimized approach
// Time complexity: O(2N)
// Space complexity: O(1)
Node* getTail(Node* head){
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;
}

vector<pair<int,int>> findPairsWithGivenSum(Node *head, int sum){
    Node* tail = getTail(head);
    Node* first = head;
    Node* second = tail;
    vector<pair<int,int>> res;
    while(first->data<second->data){
        if(first->data+second->data==sum){
            res.push_back({first->data,second->data});
            first=first->next;
            second=second->prev;
        }
        else if(first->data+second->data<sum){
            first=first->next;
        }
        else{
            second=second->prev;
        }
    }
    return res;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->prev = head->next->next->next;

    printLinkedList(head);
    vector<pair<int,int>> res = findPairsWithGivenSum(head,5);
    for(auto i:res){
        cout<<i.first<<" "<<i.second<<endl;
    }

    
    return 0;
}