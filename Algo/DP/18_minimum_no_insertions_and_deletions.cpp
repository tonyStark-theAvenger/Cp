#include <bits/stdc++.h>

using namespace std;

/* 
  Refer:- https://www.youtube.com/watch?v=-fx6aDxcWyg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25&t=329ss
 */

void minOperations(string x, string y)
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
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int a = dp[n][m];

    int d = n - a;
    int i = m - a;

    cout << "Total insertions :- " << i << endl;
    cout << "Total deletions :- " << d << endl;
}

int main()
{
    string x, y;
    cin >> x >> y;
    minOperations(x, y);
    return 0;
}