#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define start                \
    ios::sync_with_stdio(0); \
    cin.tie(0);

#define f(i, a, b) for (ll i = a; i < b; i++)

#define DEBUG(x) cout << x << endl;

#define iarr(arr, n, m) f(i, 0, n) f(j, 0, m) cin >> arr[i][j];
#define parr(arr, n, m)                      \
    f(i, 0, n)                               \
    {                                        \
        f(j, 0, m) cout << arr[i][j] << " "; \
        cout << endl;                        \
    }

#define iar(ar, n) f(i, 0, n) cin >> ar[i];
#define par(ar, n) f(i, 0, n) cout << ar[i] << " ";

#define MOD 1000000007
// by default priority queue is greater one in cpp



//calulating the pi function in O(N)
vector<ll> piFunction(string s) {
	ll n  = s.length();
	vector<ll> pi(n, 0);
	pi[0] = 0;
	for (ll i = 1; i < n; i++) {
		ll j = pi[i - 1];
		while (j > 0 && s[i] != s[j])w {
			j = pi[j - 1];
		}

		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}

	return pi;
}

int main()
{
	start;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		vector<ll> pi = piFunction(s);
		par(pi, pi.size());
	}
	return 0;
}