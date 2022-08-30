#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//function to reverse a number
int reverse_number(int n)
{
    int ones, ans = 0;

    while (n != 0)
    {
        ones = n % 10;
        ans = ans * 10 + ones;
        n = n / 10;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;

    int check = reverse_number(n);

    if (check == n)
    {
        cout << "Entered number is palindrome";
    }
    else
    {
        cout << "Entered number is not a palindrome";
    }

    return 0;
}