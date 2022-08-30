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

// #define MOD 1000000007
#define f(i, a, b) for (ll i = a; i < b; i++)
#define test(t) while (t--)
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define pob pop_back
#define pu push
#define po pop

/* 
 V.V.V Imp asked in most of the interviews.
 */
string factorial(int input)
{
    int a[200], n, counter, temp, i;
    a[0] = 1;
    counter = 0;

    for (int n = input; n >= 2; n--)
    {
        temp = 0;
        for (i = 0; i <= counter; i++)
        {
            temp = (a[i] * n) + temp;
            a[i] = temp % 10;
            temp = temp / 10;
        }
        while (temp > 0)
        {
            a[++counter] = temp % 10;
            temp = temp / 10;
        }
    }

    string ans = "";

    for (int i = counter; i >= 0; i--)
    {
        ans += to_string(a[i]);
    }

    return ans;
}

int main()
{
    start;
    int n;
    cin >> n;

    cout << factorial(n);
    return 0;
}