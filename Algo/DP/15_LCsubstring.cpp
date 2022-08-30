#include <bits/stdc++.h>
using namespace std;

/*
Refer:- https://www.youtube.com/watch?v=HrybPYpOvz0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=22
 */

int LCs(string x, string y)
{
    int n = x.length(), m = y.length();

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
                dp[i][j] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            ans = max(ans, dp[i][j]);

    return ans;
}
int main()
{
    string x, y;
    cin >> x >> y;
    cout << LCs(x, y);

    return 0;
}