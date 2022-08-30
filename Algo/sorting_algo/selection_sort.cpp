#include <bits/stdc++.h>

using namespace std;
/*
space complexity
 -->O(1)
time complexities
-->best case
   O(n^2) with O(n) swaps
-->average case
   O(n^2) with O(n) swaps
-->worst case
   O(n^2) with O(n) swaps


note:-it is better by bubble sort in terms of number of swaps taking place i.e they are constant to be O(n) in every
case
*/

void selectionSort(int arr[], int n)
{
    int min_index;
    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
            swap(arr[min_index], arr[i]);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of an array to be sorted" << endl;
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

    selectionSort(arr, n);

    cout << "\nArray after sorting is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}