#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
space complexity
 -->O(1)
time complexities
-->best case
    O(n) with O(1) swaps
-->average case
    O(n^2) with O(n^2) swaps
-->worst case
    O(n^2) with O(n^2) swaps
*/

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]); //predefined function in c++ to swamp two numbers
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of an array to be soted" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of an array" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    cout << "\nArray before sorting is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    bubble_sort(arr, n);
    cout << "\nArray after sorting is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
