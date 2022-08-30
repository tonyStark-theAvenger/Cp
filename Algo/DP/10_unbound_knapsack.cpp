#include <bits/stdc++.h>

using namespace std;
/*
  Here,the element can have multiple instances
Refer:- https://www.youtube.com/watch?v=aycn9KO8_Ls&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=13&t=890s

 */

int unbound_knapsack(vector<int> &w, vector<int> &v, int target)
{
  int n = w.size();
  int dp[n + 1][target + 1];

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= target; j++)
    {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (w[i - 1] > j)
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(v[i - 1] + dp[i][j - w[i - 1]], dp[i - 1][j]);//just change is while taking element we are taking dp[i]
    }
  }
  return dp[n][target];
}

int main()
{
  vector<int> weight = {1, 50};
  vector<int> values = {1, 30};
  int target = 100;
  cout << unbound_knapsack(weight, values, target);

  return 0;
}