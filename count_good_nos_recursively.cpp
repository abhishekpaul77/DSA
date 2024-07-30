#include <bits/stdc++.h>
using namespace std;

/*
Problem statement:A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.
A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
*/

// Optimal soltution
// Time complexity: O(logn)
// Space complexity: O(logn)
# define mod 1000000007
long long power(long long x, long long n)
{
    if (n == 0)
    {
        return 1;
    }
    long long ans = power(x, n / 2);
    ans *= ans;
    ans %= mod;
    if (n % 2)
        ans *= x;
    ans %= mod;
    return ans;
}
int countGoodNumbers(long long n)
{
    long long odd = n / 2;
    long long even = n / 2 + n % 2;
    return (power(5, even) * power(4, odd)) % mod;
}

int main()
{
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << countGoodNumbers(n) << endl;


    return 0;
}