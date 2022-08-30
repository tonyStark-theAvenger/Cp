#include <bits/stdc++.h>

using namespace std;

/* 
  Here,we are required to make the given amount using the minimum no of given coins.

  Refer:- https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16
  
 */

int solve(vector<int> &coins, int target)
{
    int n = coins.size();
    int dp[n + 1][target + 1];

    for (int j = 0; j <= target; j++)
        dp[0][j] = INT32_MAX - 1;

    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;

    // initiliziaing second row
    for (int j = 0; j <= target; j++)
    {
        if (j % coins[0] == 0)
            dp[1][j] = j / coins[0];
        else
            dp[1][j] = INT32_MAX - 1;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
        }
    }

    //target is not possible form given coins,so return -1
    if (dp[n][target] == INT32_MAX - 1)
        return -1;
    else
        return dp[n][target];
}

int main()
{
    vector<int> coins = {9, 6, 5, 1};
    int target = 11;

    cout << solve(coins, target);
    return 0;
}