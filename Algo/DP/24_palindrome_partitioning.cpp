#include <bits/stdc++.h>

using namespace std;

/* 
 Problem:- https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
 */

/* 
 Recursive approach
 Refer:- https://www.youtube.com/watch?v=szKVpQtBHh8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=36
 */
bool is_pailndorme(string s, int i, int j)
{
    // cout << "in function " << endl;
    if (i == j)
        return true;

    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve_r(string s, int i, int j)
{
    if (i >= j)
        return 0;

    if (is_pailndorme(s, i, j))
        return 0;
    int ans = INT16_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = 1 + solve_r(s, i, k) + solve_r(s, k + 1, j);
        ans = min(ans, temp);
    }
    return ans;
}

/* 
 Memoized approach
 Refer:- https://www.youtube.com/watch?v=fOUlNlawdAU&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=37
 */
int dp[1001][1001];

int solve_m(string s, int i, int j)
{
    if (i >= j)
        return 0;

    if (is_pailndorme(s, i, j))
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT16_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int left, right;

        if (dp[i][k] != -1)
            left = dp[i][k];
        else
        {
            left = solve_m(s, i, k);
            dp[i][k] = left;
        }

        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
        {
            right = solve_m(s, k + 1, j);
            dp[k + 1][j] = right;
        }
        int temp = 1 + left + right;
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}

int main()
{
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    // cout << is_pailndorme(s, 0, s.length() - 1);
    cout << solve_r(s, 0, s.length() - 1) << endl;
    cout << solve_m(s, 0, s.length() - 1);

    return 0;
}