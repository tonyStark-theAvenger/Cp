#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;
vector<pair<long long, long long>> graph[100001];

int main()
{

    int nodes, edges, source, destination, weight;
    cout << "Enter the number of nodes and edges \n";
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the source and destinaiton node and weight\n";
        cin >> source >> destination >> weight;
        pair<long long, long long> p1, p2;
        p1 = make_pair(destination, weight);
        p2 = make_pair(source, weight);

        graph[source].push_back(p1);
        graph[destination].push_back(p2);
    }

    //The Adjacency list representation of  the graph
    cout << "The Adjacency list representation of  the graph is \n";
    for (int i = 1; i <= nodes; i++)
    {
        cout << "for vertex " << i << " ";
        for (auto &&u : graph[i])
        {
            cout << u.first << " weigth is " << u.second << "\n";
        }

        cout << "-----------------------------------------\n";
        cout << endl;
    }

    return 0;
}
