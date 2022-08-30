#include <bits/stdc++.h>

using namespace std;

typedef int ll;

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


//most optimal soution using 2 pointrs after sorting
/*
Q:- https://leetcode.com/problems/4sum/
ReferL- https://takeuforward.org/data-structure/4-sum-find-quads-that-add-up-to-a-target-value/
*/
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	int n = nums.size();

	vector<vector<int>> ans;
	if (n == 0) return ans;
	sort(nums.begin(), nums.end());
//-2 -1 0 1 2

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = target - (nums[i] + nums[j]);
			// cout << sum << endl;
			int l = j + 1, h = n - 1;


			while (l < h) {
				int temp = nums[l] + nums[h];

				if (temp < sum) {
					l++;
				} else if (temp > sum) {
					h--;
				} else {

					vector<int> t(4, 0);
					t[0] = nums[i];
					t[1] = nums[j];
					t[2] = nums[l];
					t[3] = nums[h];
					ans.push_back(t);


					while (l < h && nums[l] == t[2])
						l++;

					while (l < h && nums[h] == t[3])
						h--;
				}

			}

			while (j + 1 < n && nums[j + 1] == nums[j])j++;
		}
		while (i + 1 < n && nums[i + 1] == nums[i]) i++;
	}

	// cout << ans.size() << endl;
	return ans;
}



void solve() {
	ll n;
	cin >> n;
	vector<ll> ar(n);
	f(i, 0, n) cin >> ar[i];
	ll sum ; cin >> sum;

	vector<vector<ll>> ans = fourSum(ar, sum);

	for (auto itr : ans) {
		for (auto i : itr)
			cout << i << " ";
		cout << endl;
	}
}

int main()
{
	start;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t;
	// t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}