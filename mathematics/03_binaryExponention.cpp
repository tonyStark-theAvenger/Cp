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

  Topic:- Binary Exponention(V.V.V IMP)

  Time Complexity:- "O(log(n))"  , where  n=power to which it is being calculated ;

  Applications :- To find x^y in efficient way;

 */


//Function to calculate power in log(n) time
ll bPower(ll n, ll power)
{
    ll res = 1;
    while (power)
    {
        if (power & 1)
            res = res * n % MOD;

        n = n * n % MOD;
        power >>= 1;
    }
    return res;
}


int main()
{

    start;

    ll n, power;
    cin >> n >> power;

    cout << n << " to the power of " << power << " is " << bPower(n, power);
    return 0;
}