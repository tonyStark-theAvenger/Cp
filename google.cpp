#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


/*

partition the given string of length 'n' consisting char's between '0' and '9' , give the no of ways to divide the given string into the exactly 'k' substring's with each substring of minimum length 'm' and each substring start's with even and end's with odd number

eg:-
	N = 9
	M = 2
	K = 3
	S = "232387421"
	ANS:- 3
		23 | 23 | 87421
		2323 | 87 | 421
		23 | 2387 | 421


	N = 6
	M = 3
	K = 2
	S = "21433"
	ANS:-1
		21 | 433


*/

vector<vector<int>> dp(2005, vector<int>(2005, -1));

ll so(int s, int e, int &n, int curr_k, int &maxi, int &m, string &str) {

	if (s >= e) return 0;
	// if((e-s+1)==m){
	//     int start = str[s]-'0',end = str[e]-'0';

	//     if(!(start&1) && (end&1)) return 1;

	//     return 0;
	// }

	// if(dp[s][curr_k]!=-1) return dp[s][curr_k];

	if (curr_k > maxi) return 0;

	int ans = 0;

	for (int k = s + 1; k < n; k++) {
		if ((str[k] - '0') & 1) {
			int length = k - s + 1;
			int curr_k = curr_k + 1;
			if (length >= m && curr_k < maxi) {
				cout << str.substr(s, length) << " " << curr_k << endl;
				ans = 1 + so(k + 1, e, n, curr_k, k, m, str);
			}
		}
	}
	return ans;
}


long long solve (int N, int M, int K, string S) {
	return so(0, N - 1, N, 0, K, M, S);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int M;
	cin >> M;
	int K;
	cin >> K;
	string S;
	cin >> S;

	long long out_;
	out_ = solve(N, M, K, S);
	cout << out_;
}