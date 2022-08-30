#include <bits/stdc++.h>

using namespace std;

/* 
objective : Binary search using iterarive and recursive method
 */

//Iterative method
int binary_search_i(vector<int> arr, int key)
{
    int s = 0, e = arr.size() - 1;

    while (s <= e)
    {
        int mid = s + (e - 1) / 2;
        // cout << mid;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

//recursive method
int binary_search_r(vector<int> arr, int l, int r, int key)
{

    if (l <= r)
    {
        int mid = l + (r - 1) / 2;

        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return binary_search_r(arr, l, mid - 1, key);
        else
            return binary_search_r(arr, mid + 1, r, key);
    }
    return -1;
}

int main()
{
    int n, ele;
    cout << "Enter the no of elements in an array: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the array : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the element to be serched : ";
    cin >> ele;

    sort(arr.begin(), arr.end());

    cout << "Answer using iterative method.\n-----------------------\n";
    if (binary_search_i(arr, ele) == -1)
        cout << ele << " is not present in an array.\n";
    else
        cout << ele << " is present at index " << binary_search_i(arr, ele) << " in an array.\n";
    cout << "------------------------\n----------------------\n";
    cout << "Answer using recursive method.\n-----------------------\n";
    if (binary_search_r(arr, 0, arr.size() - 1, ele) == -1)
        cout << ele << " is not present in an array.\n";
    else
        cout << ele << " is present at index " << binary_search_r(arr, 0, arr.size() - 1, ele) << " in an array.\n";
    return 0;
}