
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


vector<ll> g[100001];
vector<ll> visi(100001, false);
vector<ll> in(100001), low(100001);
int timer = 0;


//finding the bridge in a graph-->V.V.V IMP
//concept of dfs tree and concept of back edge
void dfs(ll v, ll p) {
	visi[v] = true;
	in[v] = low[v] = timer;
	timer++;

	for (ll child : g[v]) {

		if (child == p)
			continue;
		else {
			if (visi[child] == true)
			{
				//this is a back edge so change the low time of current node
				low[v] = min(low[v], in[child]);
			} else {
				//this is a front edge so call dfs
				dfs(child, v);
				//condition to check if the edge is a bridge or not

				if (low[child] > in[v])
				{
					cout << v << "-->" << child << " is a bridge\n";
				}

				//while backtrack change the low time of curr
				low[v] = min(low[v], low[child]);
			}
		}

	}
}



void enter_graph() {
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
