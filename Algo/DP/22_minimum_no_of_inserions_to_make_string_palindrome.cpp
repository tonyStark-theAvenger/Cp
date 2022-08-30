#include <bits/stdc++.h>

using namespace std;

/* 
Problem :- Count the minimum no of insertions required to make the given string palindrome

Refer:- https://www.youtube.com/watch?v=AEcRW4ylm_c&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=32

 */

int countMin(string s1)
{

    int n = s1.length();
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return n - dp[n][n];
}

int main()
{
    string s;
    cin >> s;
    cout << countMin(s) << endl;

    return 0;
}