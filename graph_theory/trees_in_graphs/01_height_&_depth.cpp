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

void inputGrpah(int v);


vector<int> g[100005];

//height and depth array's
int Height[100005], depth[100005];

//modified dfs for tree's that does not uses visited array
void dfs(int s, int par) {
	/*action on node after leaving the node*/

	for (int child : g[s]) {
		/*action on child before entering the child*/

		//at the time of going to child compute the depth

		depth[s] = 1 + depth[par];
		if (child == par) continue;
		dfs(child, s);
		Height[s] = max(Height[s], Height[child] + 1);
		/*action on child after leaving the child*/
		//at the time of returing compute the height
	}

	/*action on node after leaving the node*/
}

void solve() {
	int v;
	cin >> v ;

	inputGrpah(v);
	depth[0] = -1;
	dfs(1, 0);
	for (int i = 1; i <= v; i++)
		cout << i << "-->" << depth[i] << " " << Height[i] << endl;
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
		solve();
	}
	return 0;
}


void inputGrpah(int v) {

	v--;
	while (v--) {
		int s, d;
		cin >> s >> d;
		g[s].push_back(d);
		g[d].push_back(s);
	}
}