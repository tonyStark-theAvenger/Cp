#include <bits/stdc++.h>

using namespace std;

/*
 Refer:-https://www.youtube.com/watch?v=4Urd0a0BNng&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=21

 To find the longest common subsequence of given two strings.

 */

//Recursive code
int LCS_R(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (x[n - 1] == y[m - 1])
        return 1 + LCS_R(x, y, n - 1, m - 1);
    else
        return max(LCS_R(x, y, n, m - 1), LCS_R(x, y, n - 1, m));
}

//memoization dp
int LCS_M(string x, string y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return dp[n][m] = 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    else
    {
        if (x[n - 1] == y[m - 1])
            return dp[n][m] = 1 + LCS_M(x, y, n - 1, m - 1, dp);
        else
            return dp[n][m] = max(LCS_M(x, y, n, m - 1, dp), LCS_M(x, y, n - 1, m, dp));
    }
}

//bottom-up dp
int LCS_B(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}
int main()
{
    string x, y;
    cin >> x >> y;
    int n = x.length(), m = y.length();
    cout << LCS_R(x, y, n, m) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << LCS_M(x, y, n, m, dp) << endl;
    cout << LCS_B(x, y, n, m) << endl;

    return 0;
}