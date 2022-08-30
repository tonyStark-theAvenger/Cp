// Program to illustrate Euclid's ALgorithm to find the GCD of numbers
//it's time complexity is O(logmin(a,b)).

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{

    return b == 0 ? a : gcd(b, a % b);

    // if (b == 0)
    // {
    //     return a;
    // }
    // else
    // {
    //     return gcd(b, b % a);
    // }
}
int main()
{
    int a, b;
    cout << "Enter the two numbers whose gcd you want.\n";
    cin >> a >> b;

    int GCD = gcd(a, b);

    cout << "GCD of " << a << " and " << b << " is " << GCD << " and LCM is " << (a * b) / GCD;

    return 0;
}
