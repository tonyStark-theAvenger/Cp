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
   Refer:- https://unacademy.com/class/mastering-backtracking-i/TFDXYYKM
*/

//Time coplexity :- 2^n.
void generate_paranthesis(string s, int o, int c, int n)
{
    if (s.length() == (2 * n))
    {
        cout << s << endl;
        return;
    }

    if (o < n)
    {
        //do something
        s += '(';

        //recurse
        generate_paranthesis(s, o + 1, c, n);

        //backtrack
        s.pop_back();
    }
    if (c < o)
    {
        //do something
        s += ')';

        //recurse
        generate_paranthesis(s, o, c + 1, n);

        //backtrack
        s.pop_back();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s = "";
        generate_paranthesis(s, 0, 0, n);
    }
    return 0;
}