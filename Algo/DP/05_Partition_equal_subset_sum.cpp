#include <bits/stdc++.h>

using namespace std;
/* 
Problem :- https://leetcode.com/problems/partition-equal-subset-sum/

Refer:- https://www.youtube.com/watch?v=obhWqDfzwQQ&list=PLEJXowNB4kPxBwaXtRO1qFLpCzF75DYrS&index=9
 */

bool Solve(int ar[], int n)
{
    int w = 0;
    for (int i = 0; i < n; i++)
        w += ar[i];

    if (w & 1)
        return false;

    w >>= 1;

    bool dp[n + 1][w + 1];
    dp[0][0] = true;

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int j = 1; j <= w; j++)
        dp[0][j] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (ar[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - ar[i - 1]]);
        }
    }

    return dp[n][w];
}

int main()
{
    int ar[] = {1, 6, 3};
    int n = sizeof(ar) / sizeof(ar[0]);
    cout << Solve(ar, n) << endl;
    return 0;
}