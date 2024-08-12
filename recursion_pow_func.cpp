#include <bits/stdc++.h>
using namespace std;

// Optimal soltution
// Time complexity: O(logn)
// Space complexity: O(logn)
double power(double x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }
    if (n % 2 == 0)
    {
        return power(x * x, n / 2);
    }
    else
    {
        return x * power(x, n - 1);
    }
}
double myPow(double x, int n)
{
    return power(x, n);
}

int main()
{

    double x;
    int n;
    cout << "Enter the value of x and n: ";
    cin >> x >> n;
    cout << myPow(x, n) << endl;

    return 0;
}