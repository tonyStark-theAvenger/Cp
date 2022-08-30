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

vector<pair<int, int>> dirs = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}, { -1, -1}, { -1, 1}, {1, -1}, {1, 1}};
int c ;


bool is_valid(int i, int j, vector<vector<int>> &grid) {
	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return false;

	if (grid[i][j] != 1) return false;

	return true;
}

void dfs(int i, int j, vector<vector<int>> &grid) {

	if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
	if (grid[i][j] != 1) return;

	grid[i][j] = -1;
	c++;
	for (int d = 0; d < 8; d++) {
		int new_x = i + dirs[d].first, new_y = j + dirs[d].second;
		dfs(new_x, new_y, grid);
	}


}

int findMaxArea(vector<vector<int>>& grid) {
	int n = grid.size(), m = grid[0].size();




	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1) {
				c = 0;
				dfs(i, j, grid);
				for (int i = 0; i < n; i++)
					ans = max(ans, c);
			}
		}
	}

	return ans;
}
void solve() {
	int n, m; cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	cout << findMaxArea(a) << endl;

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