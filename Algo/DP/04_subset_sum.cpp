#include <bits/stdc++.h>

using namespace std;
/*
-->This is a subset sum problem which is a variation of 0/1 knapsack
-->Time Complexity O(n*w)
--> Space Comlexity :- O(n*w)
 ,where n is total number of elements in an set and w is given sum.
*/

bool subetSum(int set[], int sum, int n)
{
    bool dp[n + 1][sum + 1];

    //Making first row values to false;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    //Making first column values to true;
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (set[i - 1] > j)
            {
                //if element is not included in an subset
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - set[i - 1]]);
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
            cout << dp[i][j] << " ";

        cout << endl;
    }

    return dp[n][sum];
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 30;
    if (subetSum(set, sum, n))
        cout << "Given set has a subset whose sum of elements is equal to " << sum << endl;
    else
        cout << "No subset with sum equal to " << sum << endl;

    return 0;
}