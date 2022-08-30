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
#define po pop

/* 
Refer:- https://www.youtube.com/watch?v=2eNnuR0vlFA&list=PL2q4fbVm1Ik4ktv2_1O1atXoeV7whMAy_&index=2

problem:- https://www.codechef.com/problems/JAM11
 */

vector<int> ar(100001, -1);

//Iterative approach
/* void solve()
{
    ar[1] = 1;
    ar[2] = 2;
    ar[3] = 4;

    for (ll i = 4; i <= 100000; i++)
    {
        ar[i] = (ar[i - 1] + ar[i - 2] + ar[i - 3]) % MOD;
    }
} */

//Recursive approach
int solve(int n)
{
    if (n == 1 || n == 2)
        return n;
    if (ar[n] == -1)
    {

        int res = 0;
        res = (solve(n - 1) + solve(n - 2));
        ar[n] = res;
    }
    return ar[n];
}

int main()
{
    start;

    ar[0] = 0;
    ar[1] = 1;
    ar[2] = 2;
    int t;
    cin >> t;
    test(t)
    {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}