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
   Refer:- https://www.youtube.com/watch?v=ot_XBHyqpFc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11
 */
int solve(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int temp = (sum + diff) / 2;

    int dp[n + 1][temp + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= temp; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= temp; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]);
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= temp; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[n][temp];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    f(i, 0, n)
    cin >>
        arr[i];
    cout << solve(arr, n, 1);
}
