
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

#define MOD 1000000007
#define f(i, a, b) for (ll i = a; i < b; i++)
#define test(t) while (t--)
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define pob pop_back
#define pu push
#define wn po pop

vector<int> g[100001];
vector<int> visi(100001, 0);

//->bfs implementation in graph

// finding the single source shortest path using bfs
void bfs(ll v, ll n)
{

	vector<ll> dist(10001);
	queue<ll> q;

	q.push(v);
	visi[v] = 1;
	dist[v] = 0;
	ll level = 1;

	while (!q.empty())
	{
		ll node = q.front();
		q.pop();
		cout << node << " ";

		ll n = q.size();
		for (int i = 0; i < n; i++)
		{
			cout << "level " << level << endl;
		}

		for (ll child : g[node])
		{
			if (visi[child] == 0)
			{
				dist[child] = 1 + dist[node];
				q.push(child);
				visi[child] = 1;
			}
		}
	}

	cout << "\nNodes and their corresponding distance" << endl;

	for (int i = 1; i <= n; i++)
		cout << i << "-->" << dist[i] << endl;
}

// for practice refer to the this problem
//->  https://www.spoj.com/problems/PPATH/
//->  https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/

void enter_graph()
{
	ll n, m;
	cin >> n >> m;

	while (m--)
	{
		ll x, y;
		cin >> x >> y;
		g[x].push_back(y);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	start;

	enter_graph();

	cout << bfs(1, n) << endl;

	return 0;
}
