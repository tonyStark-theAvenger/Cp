#include <bits/stdc++.h>

using namespace std;

/* 
  Here,we need to count the total no of way's to to make the given amount using the given coins.
  Refer:- https://www.youtube.com/watch?v=I4UR2T6Ro3w&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=15

*/

int solve(vector<int> coins, int target)
{
    int n = coins.size();
    int dp[n + 1][target + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int j = 1; j <= target; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
        }
    }

    return dp[n][target];
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int target = 5;
    cout << solve(coins, target);
    return 0;
}