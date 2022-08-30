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
  V.V.V Imp problem
  
 Problem Link :- https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

 Refer :- https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11

 */

int minDifference(int arr[], int n)
{
    int sum = 0;

    //if array length is 1
    if (n == 1)
        return arr[0];

    //taking sum of an array elements
    for (int i = 0; i < n; i++)
        sum += arr[i];

    //dp table for it's last row
    bool dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    //filling dp table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    /* for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    } */

    //calculating final answer from dp table's last row
    int ans = INT16_MAX;
    for (int j = 0; j <= sum; j++)
    {
        if (dp[n][j])
        {
            int c = abs(sum - 2 * j);
            ans = min(ans, c);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    f(i, 0, n)
    {
        cin >> arr[i];
    }
    cout << minDifference(arr, n);
}
