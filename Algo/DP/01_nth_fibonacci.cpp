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

vector<int> fib(1000, -1);

int solve(int n)
{

    if (fib[n] == -1)
    {

        if (n == 1 || n == 0)
            return 1;
        else
        {
            int nu = solve(n - 1) + solve(n - 2);
            fib.at(n) = nu;
            return nu;
        }
    }
    return fib[n];
}

int main()
{
    start;
    fib.at(0) = fib.at(1) = 1;
    int t;
    cin >> t;
    test(t)
    {
        int n;
        cin >> n;
        cout << n << "th fibonacci is " << solve(n) << endl;
    }

    return 0;
}