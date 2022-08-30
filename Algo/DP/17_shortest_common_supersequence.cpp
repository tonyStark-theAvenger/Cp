#include <bits/stdc++.h>

using namespace std;

/* 
 Refer:- https://www.youtube.com/watch?v=823Grn4_dCQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=24

 Problem Link:- https://www.geeksforgeeks.org/shortest-common-supersequence/
 */

//function to print the supersequence
/* 
Refer:- https://www.youtube.com/watch?v=VDhRg-ZJTuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=28&t=353s
 */
void print(string x, string y)
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
    } /* 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << dp[i][j] << " ";

        cout << endl;
    } */

    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        // cout << "in while\n"
        //      << endl;
        if (x[i - 1] == y[j - 1])
        {
            ans += x[i - 1];
            i--;
            j--;
        }
        else
        {
            int up = dp[i - 1][j], left = dp[i][j - 1];

            if (up > left)
            {
                //add those which is less
                ans += x[i - 1];
                i--;
            }
            else
            {
                ans += y[j - 1];
                j--;
            }
        }
    }

    while (i > 0)
    {
        ans += x[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += y[j - 1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

// Function to get length of a supersequence
int length_SCS(string x, string y)
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
    return n + m - dp[n][m];
}

int main()
{
    string x, y;
    cin >> x >> y;
    cout << "Length of a Shortest Common SuperSequence is :- " << length_SCS(x, y);
    cout << " and it is ";
    print(x, y);

    return 0;
}