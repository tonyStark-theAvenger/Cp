#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef stack<ll> sl;
typedef vector<ll> vl;
typedef queue<ll> ql;
typedef set<ll> sel;
typedef vector<vl> dvl;
typedef pair<ll, ll> pll;

#define start                \
    ios::sync_with_stdio(0); \
    cin.tie(0);

#define file                                     \
    input_file = fopen("input.txt", "r", stdin); \
    output_file = fopen("output.txt", "w", stdout);

#define MOD 1000000007
#define f(i, a, b) for (ll i = a; i < b; i++)
#define test(t) while (t--)
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define pob pop_back
#define pu push
#define wn po pop

/* 
Problem :- https://leetcode.com/problems/target-sum/

Refer:- https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12

 */

int solve(vector<int> &nums, int s, int z)
{

    int n = nums.size();

    int dp[n + 1][s + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= s; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {

            if (nums[i - 1] == 0)
                dp[i][j] = dp[i - 1][j];
            else if (nums[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
        }
    }

    return pow(2, z) * dp[n][s];
}
int findTargetSumWays(vector<int> &nums, int target)
{

    int sum = 0, n_z = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (nums[i] == 0)
            n_z++;
    }

    if (target > sum)
        return 0;

    int tar = sum + target;
    if (tar & 1)
        return 0;
    else
        tar >>= 1;
    return solve(nums, tar, n_z);
}

int main()
{
    int n, tar;
    cin >> n >> tar;
    vector<int> arr(n);
    f(i, 0, n)
            cin >>
        arr[i];

    cout << findTargetSumWays(arr, tar) << endl;
}
