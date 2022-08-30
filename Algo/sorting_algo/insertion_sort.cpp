#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
space complexity
 -->O(1)
time complexities
-->best case
    O(n) 
-->average case
    O(n^2)
-->worst case
    O(n^2) 
*/

void insertion_sort(int arr[], int n)
{
    int j, i, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; j--)
            arr[j + 1] = arr[j];

        arr[j + 1] = temp;
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

    insertion_sort(arr, n);
    cout << "\nArray after sorting is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
