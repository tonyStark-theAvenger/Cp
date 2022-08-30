#include<bits/stdc++.h>

using namespace std;


int solve(int i, int j1, int j2, vector<vector<int>>& grid)
{
	if (j1 >= grid.size() || j2 >= grid.size() || grid[i][j1] == -1 || grid[i][j2] == -1)
		return -1e8;
	if (i == grid.size() - 1 && j1 == grid.size() - 1 && j2 == grid.size()) {
		if (j1 == j2) {
			return grid[i][j1];
		} else {
			return grid[i][j1] + grid[i][j2];
		}
	}

	int ans = -1;

	for (int d = 0; d <= 1; d++) {
		for (int d2 = 0; d2 <= 1; d2++) {
			if (j1 == j2) {
				ans = max(ans, grid[i][j1] + solve(i + 1, j1 + d, j2 + d2, grid));
			} else {
				int ans1 = grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + d, j2 + d2, grid);
				ans = max(ans, ans1);
			}
		}
	}

	return ans;
}

int cherryPickup(vector<vector<int>>& grid) {
	int n = grid.size();
	return   solve(0, 0, 0, grid);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];


	cout << cherryPickup(matrix) << endl;

	return 0;
}