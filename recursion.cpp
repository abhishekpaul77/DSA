#include <bits/stdc++.h>
using namespace std;

// 1. Basic recursion example
int cnt = 0;
void fun()
{
    if (cnt == 3)
    {
        return;
    }
    cout << cnt << endl;
    cnt++;
    fun();
}

// 2. Print name N times using recursion
// void printName(int n){
//     if(n==0){
//         return;
//     }
//     cout<<"Sourav"<<endl;
//     printName(n-1);
// }
// OR
void printName(int i, int n)
{
    if (i > n)
    {
        cout << " Print name function end" << endl;
        return;
    }
    cout << "Paul" << endl;
    printName(i + 1, n);
}

// 3. Print linearly from 1 to N using recursion
// void printNumber(int n){
//     if(n==0){
//         return;
//     }
//     printNumber(n-1);
//     cout<<n<<endl;
// }
// OR
void printNumber(int i, int n)
{
    if (i > n)
    {
        cout << " Print number function end" << endl;
        return;
    }
    cout << i << endl;
    printNumber(i + 1, n);
}

// 4. Print sum of first n natural numbers using recursion
// a. Parameterized recursion
void printSum(int n, int sum)
{
    if (n == 0)
    {
        cout << "Sum of first n natural numbers is: " << sum << endl;
        return;
    }
    printSum(n - 1, sum + n);
}
// b. Functional recursion
int printSumfunctional(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + printSumfunctional(n - 1);
}

// 5. Reverse array
// a. Using for loop
void reverseArray(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - i - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*Explanation of above code:

    1. We are using for loop to iterate through the first half of the array.
    2. We are swapping the first element with the last element, second element with second last element and so on.
    3. We are printing the reversed array.

    Example with dry run:
    arr[] = {1,2,3,4,5}
    n=5 (size of array)
    i=0, arr[0] and arr[5-0-1] are swapped => arr[] = {5,2,3,4,1}
    i=1, arr[1] and arr[5-1-1] are swapped => arr[] = {5,4,3,2,1}
    arr[] = {5,4,3,2,1}
*/

// b. Using parameterised recursion
void reverseArray(int arr[], int start, int end)
{
    if (start >= end)
    {
        for (int i = 0; i <= 5; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    swap(arr[start], arr[end]);
    reverseArray(arr, start + 1, end - 1);
}

// c. Using functional recursion
void reverseArrayFunctional(int i, int arr[], int n)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reverseArrayFunctional(i + 1, arr, n);
}

// 6. Check if a given string is palindrome using recursion
bool isPalindrome(string str, int i){
    if(i>=str.size()/2){
        return true;
    }
    if(str[i]!=str[str.size()-i-1]){
        return false;
    }
    return isPalindrome(str, i+1);
}

// 7. Printing fibonacci series
// a. Using for loop
void printFibonacciForLoop(int n)
{
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++)
    {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

// b. Using recursion
int printFibonacciRecursion(int n){
    if(n<=1){
        return n;
    }
    
    int last=printFibonacciRecursion(n-1);
    int secondLast=printFibonacciRecursion(n-2);
    return last+secondLast;
}

int main()
{
    // 1. fun();
    // 2. printName(1,5);
    // 3. printNumber(1,5);
    // 4-> a.printSum(5,0);
    // 4-> b.cout<<printSumfunctional(5)<<endl;
    // 5-> a.int arr[] = {1, 2, 3, 4, 5};
    //     reverseArray(arr, 5);
    // 5-> b.int arr[] = {1, 2, 3, 4, 5};
    //     reverseArray(arr, 0, 4);
    // 5-> c.int arr[] = {1, 2, 3, 4, 5};
    // reverseArrayFunctional(0, arr, 5);
    // for (int i=0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // 6 string str="madam";
    // cout<<isPalindrome(str,0)<<endl;
    // 7-> a.printFibonacciForLoop(5);
    // 7-> b.cout<<printFibonacciRecursion(4);


    return 0;
}