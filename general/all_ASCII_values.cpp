#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    string small_alphabetes = "abcdefghijklmnopqrstuvwxyz", big_alphabetes = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 10; i++)
    {

        int a = i;
        cout << "ASCII value of " << a << " is " << int(a + '0') << endl;
    }

    for (int i = 0; i < big_alphabetes.size(); i++)
    {
        cout << "ASCII value of " << big_alphabetes[i] << " is " << int(big_alphabetes[i]) << endl;
    }

    for (int i = 0; i < small_alphabetes.size(); i++)
    {
        cout << "ASCII value of " << small_alphabetes[i] << " is " << int(small_alphabetes[i]) << endl;
    }

    return 0;
}