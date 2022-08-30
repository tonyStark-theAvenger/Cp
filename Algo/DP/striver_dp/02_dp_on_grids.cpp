#include<bits/stdc++.h>

using namespace std;

/*
-->for recursion
	->express in terms of index i&j
	->write base case
	->do some operation
	->return min,max,etc as defined by question


-->memoization of this using dp


--->basically there are 3 types of grid dp problems
1)fixed starting & ending point
2)fixed starting but variable ending point
3)variable starting but variable ending point
eg:-https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998




IMP NOTE:-
->if recursion is from n-1---->0 then tablulation will from 0----->n-1 & vice-versa.
->also,not in all condition answer will present the last of dp table.



TO SPACE OPTIMIZE:-
->if the current state is only dependent on previous state then we can optimize the space by single variable 0r single array depending on the question.
*/

//BELLOW IS THE SOLUTION FOR THIS QUESITON IN ALL POSSIBLE WAYS:- www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998


//memoization dp solution(TOP-DOWN)
int solveMemoization(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {

	if (i == 0)
		return dp[i][j] = matrix[i][j];
	if (j < 0 || j >= matrix[0].size())
		return -1e9;

	if (dp[i][j] != -1)
		return dp[i][j];
	int up = matrix[i][j] + solveMemoization(i - 1, j, matrix, dp);
	int ldia = matrix[i][j] + solveMemoization(i - 1, j - 1, matrix, dp);
	int rdia = matrix[i][j] + solveMemoization(i - 1, j + 1, matrix, dp);
	return dp[i][j] = max(up, max(ldia, rdia));
}


//tablutation dp solution(BOTTOM-UP)
int solveTabulation(vector<vector<int>> &matrix) {
	int n = matrix.size(), m = matrix[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));

	for (int j = 0; j < m; j++) {
		dp[0][j] = matrix[0][j];
	}

	int ans = -1e9;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int up = dp[i - 1][j], ldia, rdia;
			if ((j - 1) >= 0)
				ldia =  dp[i - 1][j - 1];
			else
				ldia = -1e9;

			if ((j + 1) <= m - 1)
				rdia = dp[i - 1][j + 1];
			else
				rdia = -1e9;

			dp[i][j] = matrix[i][j] + max(up, max(ldia, rdia));
		}
	}

	for (int j = 0; j < m; j++)
		ans = max(ans, dp[n - 1][j]);
	return ans;
}

//space optimized tablutation
int solveSpaceOptimized(vector<vector<int>> &matrix)
{	int n = matrix.size(), m = matrix[0].size();
	vector<int> dp(m, 0);

	for (int j = 0; j < m; j++) {
		dp[j] = matrix[0][j];
	}

	int ans = -1e9;

	for (int i = 1; i < n; i++) {
		vector<int> temp(m);
		for (int j = 0; j < m; j++) {
			int up = dp[j], ldia, rdia;
			if ((j - 1) >= 0)
				ldia =  dp[j - 1];
			else
				ldia = -1e9;

			if ((j + 1) <= m - 1)
				rdia = dp[j + 1];
			else
				rdia = -1e9;

			temp[j] = matrix[i][j] + max(up, max(ldia, rdia));
		}
		dp = temp;
	}

	for (int j = 0; j < m; j++)
		ans = max(ans, dp[j]);
	return ans;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
	int n = matrix.size(), m = matrix[0].size();
	vector<vector<int>> dp(n, vector<int>(m, -1));

//calling memoization dp function
	int memoSolution  = solveMemoization(n - 1, m - 1, matrix, dp) ;

//calling tabulation dp function
	int tabuSolution  = solveTabulation(matrix);

//calling space optimized tabulation dp function
	int spaceSolution  = solveSpaceOptimized(matrix);


	return spaceSolution;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];

	cout << getMaxPathSum(matrix) << endl;
	return 0;
}