#include <bits/stdc++.h>

using namespace std;
/* 
   https://www.youtube.com/watch?v=UA_Rmjfj4bw&t=172s
 */

int partation(int a[], int l, int h)
{
    int pivot = a[l];

    int i = l, j = h;

    while (i < j)
    {

        while (a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[l], a[j]);

    return j;
}

void QuickSort(int a[], int l, int h)
{

    if (l < h)
    {
        int pivot = partation(a, l, h);
        QuickSort(a, l, pivot - 1);
        QuickSort(a, pivot + 1, h);
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
