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

#define inf 1e18
#define ninf -1e18

#define MOD 1000000007
// by default priority queue is greater one in cpp

void clear(queue<int> &q) {
	while (!q.empty()) q.pop();
}
void solve() {
	queue<int> q;

	for (int i = 0; i < 10; i++) {
		q.push(rand());
	}
	cout << q.size() << endl;
	clear(q);

	cout << q.size() << endl;
}

int main()
{
	start;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t = 1;
	while (t--) {
		solve();
	}
	return 0;
}