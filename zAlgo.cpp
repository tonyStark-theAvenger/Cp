#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define start                \
    ios::sync_with_stdio(0); \
    cin.tie(0);

#define f(i, a, b) for (ll i = a; i < b; i++)

#define DEBUG(x) cout << x << endl;

#define iarr(arr, n, m) f(i, 0, n) f(j, 0, m) cin >> arr[i][j];
// #define parr(arr, n, m)
// f(i, 0, n)
// {
// 	f(j, 0, m) cout << arr[i][j] << " ";
// 	cout << endl;
// }

#define iar(ar, n) f(i, 0, n) cin >> ar[i];
#define par(ar, n) f(i, 0, n) cout << ar[i] << " ";

#define MOD 1000000007
// by default priority queue is greater one in cpp


//naive approach to build the z array which runs in O(N^2)
vector<ll> buildZarray(string s) {
	ll n  = s.length();
	vector<ll> z(n);
	z[0] = 0;


	for (int i = 1; i < n; i++) {

		ll count = 0;
		for (int j = i; j < n; j++) {
			if (s[j] != s[j - i] )
				break;
			count++;
		}
		z[i] = count;
	}
	return z;
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

		ll n;
		cin >> n;
		vector<ll> a(n);
		iar(a, n);

		bool flag = true;

		f(i, 0, n - 1) {
			if (a[i] > a[i + 1])
			{
				// cout << a[i] << endl;
				if ((a[i] + a[i + 1] & 1))
					swap(a[i], a[i + 1]);
				else {
					flag = false;
					break;
				}
			}
		}

		flag ? cout << "YES" << endl : cout << "NO" << endl;

	}
	return 0;
}