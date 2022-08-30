#include <bits/stdc++.h>

using namespace std;

//This is a plain recursion whose time compexity is 2^n i.e exponential
int Knapsack_expo(vector<int> wtArray, vector<int> prArray, int space, int index)
{
    //Base Case
    if (space == 0 || index < 0)
        return 0;
    int res;

    if (wtArray[index] > space)
        res = Knapsack_expo(wtArray, prArray, space, index - 1);
    else
        res = max(Knapsack_expo(wtArray, prArray, space, index - 1), prArray[index] + Knapsack_expo(wtArray, prArray, space - wtArray[index], index - 1));
    return res;
}

/*
//Dp optimization over plain recursion a plain recursion with memoization
Time complexity is O(w*n) and space complexity is O(w*n) ,where w is weight of a bag.
-->this memoization requires large stack memory and can result in stack overflow 
*/

int Knapsack_memo(vector<int> wtArray, vector<int> prArray, int space, int index, vector<vector<int>> &dp)
{
    //Base Case
    if (space == 0 || index < 0)
        return 0;

    if (dp[index + 1][space] != -1)
        return dp[index][space];

    int res;

    if (wtArray[index] > space)
        res = Knapsack_memo(wtArray, prArray, space, index - 1, dp);
    else
        res = max(Knapsack_memo(wtArray, prArray, space, index - 1, dp), prArray[index] + Knapsack_memo(wtArray, prArray, space - wtArray[index], index - 1, dp));

    return dp[index + 1][space] = res;
}

/* 
DP optimization using tabulation 
this is best approach then memoization as it takes heap memory insted of stack memory.
-->Tabulation is faster than recursion.
 */

int Knapsack_tabu(vector<int> wtArray, vector<int> prArray, int w)
{
    int n = wtArray.size();
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (wtArray[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = max(dp[i - 1][j], prArray[i - 1] + dp[i - 1][j - wtArray[i - 1]]);
            }
        }
    }

    /*     cout << endl;

    for (int i = 0; i <= wtArray.size(); i++)
    {
        for (int j = 0; j <= w; j++)
            cout << dp[i][j] << " ";

        cout << endl;
    }
 */
    return dp[n][w];
}

int main()
{
    vector<int> wt = {10, 20, 30};
    vector<int> pr = {60, 100, 120};
    int w = 50;

    cout << "Answer using plain recursion :- " << Knapsack_expo(wt, pr, w, wt.size() - 1);
    cout << endl;

    //dp table to for dp optimisation.
    vector<vector<int>> dp(wt.size() + 1, vector<int>(w + 1, -1));
    cout << "Answer using DP memoization optimisation :- " << Knapsack_memo(wt, pr, w, wt.size() - 1, dp);
    cout << endl;
    cout << "Answer using DP Tabulation optimisation :- " << Knapsack_tabu(wt, pr, w);
    cout << endl;
    return 0;
}

/* 
// vector<int> catlan(100001, -1);

// int nth_catalan(int n)
// {
//     if (catlan[n] == -1)
//     {
//         if (n == 0 || n == 1)
//         {
//             return 1;
//         }
//         int ans = 0;
//         for (int i = 0; i < n; i++)
//         {
//             ans += nth_catalan(i) * nth_catalan(n - i - 1);
//         }
//         catlan[n] = ans;
//     }
//     return catlan[n];
// }
 */
