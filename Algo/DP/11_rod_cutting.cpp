#include <bits/stdc++.h>

using namespace std;

/* 
Refer:- https://www.youtube.com/watch?v=SZqAQLjDsag&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=14
 */
int cut_rod(vector<int> &length, vector<int> &price, int L)
{
    int n = length.size();
    int dp[n + 1][L + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= L; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (length[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
        }
    }
    /* 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= L; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    } */
    return dp[n][L];
}

int main()
{
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int L = 8;
    cout << cut_rod(length, price, L);

    return 0;
}