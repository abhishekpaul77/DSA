#include <bits/stdc++.h>
using namespace std;

/*
Problem statement
You are given a string ‘s’ of length 'n'.
Implement the atoi(string s) function, which converts a given string into a 32-bit signed integer, following similar principles as the atoi function in C/C++.
Here's the step-by-step algorithm for myAtoi(string s):
1. Discard any leading whitespaces.
2. If the next character (if not at the end of the string) is '-' or '+', consider it to determine the sign of the result. If neither is present, assume the result is positive.
3. Read and accumulate digits until a non-digit character is encountered or the end of the input is reached.
4. Convert the collected digits into an integer (e.g., "123" becomes 123, "0032" becomes 32). If no digits were read, the integer is 0. Adjust the sign as needed (as determined in step 2).
5. If the integer falls outside the range of a 32-bit signed integer [-2^31, 2^31 - 1], constrain it to stay within the range. For instance, if the integer is less than -2^31, set it to -2^31; if it's greater than 2^31 - 1, set it to 2^31 - 1.
6. Return the resulting integer.
Note :
1. Only the space character ' ' is treated as a whitespace.
2. All characters other than leading whitespace or digits are considered.
*/


// Optimal approach
// Time Complexity: O(N) where N is the number of characters in the string. The string is traversed only once.
// Space Complexity: O(N) where N is the number of characters in the string. The recursive stack space is O(N) due to the recursive calls.
long atoi(string s, int sign, int i, long result)
{

    if (sign * result >= INT_MAX)
    {

        return INT_MAX;
    }

    if (sign * result <= INT_MIN)
    {

        return INT_MIN;
    }

    if (i >= s.size() || s[i] < '0' || s[i] > '9')
    {

        return sign * result;
    }

    result = atoi(s, sign, i + 1, (result * 10 + (s[i] - '0')));

    return result;
}

int createAtoi(string s)
{

    int i = 0, n = s.size(), sign = 1;

    while (i < n && s[i] == ' ')
    {

        i++;
    }

    if (s[i] == '-')
    {

        sign = -1;
        i++;
    }

    else if (s[i] == '+')
    {
        i++;
    }

    return atoi(s, sign, i, 0);
}

int main()
{
    // Test cases
    cout << createAtoi("42") << endl; // Output: 42
    cout << createAtoi("   -42") << endl; // Output: -42
    cout << createAtoi("4193 with words") << endl; // Output: 4193
    cout << createAtoi("words and 987") << endl; // Output: 0
    cout << createAtoi("-91283472332") << endl; // Output: -2147483648
    cout << createAtoi("91283472332") << endl; // Output: 2147483647
    

    return 0;
}