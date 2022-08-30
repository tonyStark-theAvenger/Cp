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

  used to calculate GCD of two numbers.

 */

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> ar(n);
    f(i, 0, n)
    {
        cin >> ar[i];
    }

    ar[0] = 1;
    f(i, 1, n)
    {
        ar[i] = __gcd(ar[i], ar[i - 1]);
    }
    f(i, 0, n)
    {
        cout << ar[i] << " ";
    }
    // int l, r;
    // while (q--)
    // {
    //     cin >> l >> r;
    // }
}

int main()
{
    // int t;
    // cin >> t;
    // test(t);
    // solve();

    cout << __gcd(9, 6);

       return 0;
}