#include <bits/stdc++.h>

using namespace std;

vector<int> parent(100001);
vector<int> size(100001, 1);

void assign_parents()
{
    for (int i = 0; i < parent.size(); i++)
        parent[i] = i;
}

int super_parent(int n)
{
    if (parent[n] == n)
        return n;
    else
        return super_parent(parent[n]);
}

void make_union(int a, int b)
{

    int p_a = super_parent(a);
    int p_b = super_parent(b);

    parent[p_a] = p_b;
}
void kruskal(vector<pair<int, pair<int, int>>> edges, int v)
{
    int x, y, cost;
    int mst_cost = 0;

    int no_of_edges = 0;

    cout << "MST is : \n";

    for (int i = 0; i < edges.size(); i++)
    {
        if (no_of_edges == v - 1)
            break;
        x = edges[i].second.first;
        y = edges[i].second.second;
        cost = edges[i].first;
        if (super_parent(x) != super_parent(y))
        {
            make_union(x, y);
            cout << "Edge between " << x << "--" << y << " is with cost of " << cost << " is included in MST" << endl;
            mst_cost += cost;
            no_of_edges++;
        }
    }
    cout << "Cost of above mst is: " << mst_cost;
}
int main()
{
    assign_parents();
    int v, e;

    cout << "Enter the number of vertics in a graph: ";
    cin >> v;
    cout << "Enter the number of edges in a graph: ";
    cin >> e;

    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < e; i++)
    {
        int s, d, e_weight;
        cout << "Enter the source and destination vertex seperated by a space: ";
        cin >> s >> d;
        cout << "Enter the edge weight: ";
        cin >> e_weight;
        edges.push_back(make_pair(e_weight, make_pair(s, d)));
    }
    sort(edges.begin(), edges.end());
    cout << "------------------------------\n";
    kruskal(edges, v);
}