#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//To count the no of 1's in a binary representation of a given number

int noOfSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main()
{

    int n;
    cin >> n;
    cout << noOfSetBits(n) << endl;

    return 0;
}
