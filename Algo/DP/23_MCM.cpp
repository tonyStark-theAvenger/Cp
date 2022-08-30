#include <bits/stdc++.h>

using namespace std;

/* 

-->V.V.V IMP

New format MCM :- https://www.youtube.com/watch?v=D7AFvtnDeMU&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=33
 */

/* 
Problem:- https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
 */

/* 
Recursive approach
Refer:-  https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=33&t=168s
 */
int MCM_R(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int temp;
    int ans = INT16_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int l_ans = MCM_R(arr, i, k);
        int r_ans = MCM_R(arr, k + 1, j);
        temp = l_ans + r_ans + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(temp, ans);
    }

    return ans;
}

/* 
Memoixation approach:- 

Refer:- https://www.youtube.com/watch?v=9uUVFNOT3_Y&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=35
 */

int dp[1001][1001];

int MCM_M(int arr[], int i, int j)
{

    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {

        int l_ans = MCM_M(arr, i, k);
        int r_ans = MCM_M(arr, k + 1, j);

        int temp = l_ans + r_ans + (arr[i - 1] * arr[k] * arr[j]);
        ans = min(temp, ans);
    }

    return dp[i][j] = ans;
}

int main()
{

    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    memset(dp, -1, sizeof(dp));
    cout << "Using plain recursion :- " << MCM_R(arr, 1, n - 1) << endl;
    cout << "Using dp:- " << MCM_M(arr, 1, n - 1);
    return 0;
}