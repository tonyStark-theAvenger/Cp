#include <bits/stdc++.h>

using namespace std;

int main()
{

    int v, e;
    cin >> v >> e;
    vector<int> graph[v+1];

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < v; i++)
    {
        for (auto u : graph[i])
        {
            cout << u << "->";
        }
        cout << endl;
    }

    return 0;
}
