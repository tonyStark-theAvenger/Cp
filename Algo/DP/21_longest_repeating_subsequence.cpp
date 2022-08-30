#include <bits/stdc++.h>

using namespace std;

/* 
 Refer:- https://www.geeksforgeeks.org/longest-repeated-subsequence/

 Refer:- https://www.youtube.com/watch?v=hbTaCmQGqLg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=30
*/

int solve(string s)
{
    int n = s.length();
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            //vaiation in if condition from standered LCS
            else if (s[i - 1] == s[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

int main()
{

    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}