#include <bits/stdc++.h>

using namespace std;

string print_LCS(string x, string y)
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

    string ans = "";
    int i = n, j = m;

    while (i > 0 && j > 0)
    {

        if (x[i - 1] == y[j - 1])
        {
            ans += x[i - 1];
            i -= 1;
            j -= 1;
        }
        else
        {
            int temp1 = dp[i - 1][j], temp2 = dp[i][j - 1];
            if (temp1 > temp2)
                i -= 1;
            else
                j -= 1;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



int main()
{
    string x, y;
    cin >> x >> y;
    cout << "LCS is :- " << print_LCS(x, y);

    return 0;
}