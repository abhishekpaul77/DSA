#include<bits/stdc++.h>
using namespace std;


// Optimal approach
// Time complexity: O(n^2)
// Space complexity: O(n)
void insertAtBottom(stack<int>& s, int element) {
    // Base case: If stack is empty, push the element
    if (s.empty()) {
        s.push(element);
        return;
    }

    // Pop the top element and recursively call insertAtBottom
    int topElement = s.top();
    s.pop();
    insertAtBottom(s, element);

    // Push the top element back
    s.push(topElement);
}

// Recursive function to reverse the stack
void reverseStack(stack<int>& s) {
    // Base case: If stack is empty, return
    if (s.empty()) {
        return;
    }

    // Pop the top element and store it
    int topElement = s.top();
    s.pop();

    // Recursively reverse the remaining stack
    reverseStack(s);

    // Insert the popped element at the bottom of the reversed stack
    insertAtBottom(s, topElement);
}

// Function to print the stack (for testing purposes)
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
      stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Original stack: ";
    printStack(s);

    // Reverse the stack
    reverseStack(s);

    cout << "Reversed stack: ";
    printStack(s);

    return 0;
}