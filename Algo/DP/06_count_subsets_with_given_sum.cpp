#include <bits/stdc++.h>

using namespace std;

/* 
Refer :-  https://www.youtube.com/watch?v=MqYLmIzl8sQ&list=PLEJXowNB4kPxBwaXtRO1qFLpCzF75DYrS&index=10
 */

int Solve(vector<int> ar, int w)
{
    int n = ar.size();
    // int count = 0;
    int dp[n + 1][w + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= w; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (ar[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - ar[i - 1]]);
        }
    }
    /* 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    } */

    return dp[n][w];
}

int main()
{
    vector<int> ar = {1, 1, 2};
    int w = 3;

    cout << "No of subsets with sum " << w << " are " << Solve(ar, w);

    return 0;
}