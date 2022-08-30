// Program to ilustrate pairs in C++ STL

/*
Important functions to work on Pair

-->1) make_pair();

-->2)swap();

-->3)tie();
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    pair<int, char> bag(25, 'V');

    pair<string, int> my("vaibhav", 05);

    pair<string, int> sun;

    pair<int, char> sum(55, 'S');

    //Using make_pair() to make pair
    sun = make_pair("This is pair tutorial ", 23);

    // tie() function
    // --> it unpackes the elements of pair into sepreate variables

    pair<int, char> te(100, 'T');
    int a;
    char c;

    // Using the tie() function
    tie(a, c) = te;

    cout << "Variables after using tie() function " << endl;
    cout << a << "\t" << c << endl;

    cout << "Before swamping elements in pair bag and sum" << endl;

    cout << "Elements of pair 'bag' are " << bag.first << "\t" << bag.second << endl;

    cout << "Elements of pair 'my' are " << my.first << "\t" << my.second << endl;

    cout << "Elements of pair 'sun' are " << sun.first << "\t" << sun.second << endl;

    cout << "Elements of pair 'sum' are " << sum.first << "\t" << sum.second << endl;

    //using the swap() function
    bag.swap(sum);

    cout << "After swamping elements in pair bag and sum" << endl;

    cout << "Elements of pair 'bag' are " << bag.first << "\t" << bag.second << endl;

    cout << "Elements of pair 'sum' are " << sum.first << "\t" << sum.second << endl;

    return 0;
}
// i||||
// j------