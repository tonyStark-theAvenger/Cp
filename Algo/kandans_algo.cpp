#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int kandane(vector<int> arr)
{
    int max_so_far = 0, max_ending_here = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    int n;
    cout << "Enter the size of an array: \n";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr.at(i);
    }
    cout << "max sum of an array is " << kandane(arr);

    return 0;
}