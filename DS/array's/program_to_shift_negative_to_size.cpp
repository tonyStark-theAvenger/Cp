#include <iostream>
#include <list>
#include <iterator>
#include <string.h>
#include <math.h>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

//This the program to shift negative numbers in an array to either right or left

using namespace std;

void negative_to_left(vector<int> arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            if (i != j)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void negative_to_right(vector<int> arr)
{
    int j = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            if (i != j)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr.at(i);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    negative_to_left(arr);

    negative_to_right(arr);

    return 0;
}
