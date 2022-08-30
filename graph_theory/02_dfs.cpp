/*
   -->This is program covers all the necessary dfs applications in graph questions
*/

#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;
vector<int> graph[100001];
bool visited[100001];

// DFS traversal function of graph
/*time complexity = O(n+m)
 where,n = no of vertices and m = no of edges
 -->Stack data structure is used
*/
void dfs(int s)
{
    if (visited[s])
        return;

    visited[s] = true;
    cout << s << " ";
    for (int i = 0; i < graph[s].size(); ++i)
    {
        if (visited[graph[s][i]] == false)
            dfs(graph[s][i]);
    }
}

/*

vector<int> g[100001];
vector<int> visi(100001, 0);

-->use full dfs implementations from condencode playlist

// --> checking graph is bipatriate or graph coloring problem

vector<int> color(100001, 0);

bool dfs(int v, int c) {
    visi[v] = true;
    color[v] = c;

    for (int child : g[v]) {
        if (visi[child] == false) {
            if (dfs(child, c ^ 1) == false)
                return false;
        } else {
            if (color[child] == color[v] )
                return false;
        }
    }
    return true;
}

----------------------------------------------------------------------

// -->cycle detection for undirected graph

bool check_cycle(ll v, ll p)
{
    cout << v << " ";
    visi[v] = true;


    for (ll child : g[v]) {
        if (visi[child] == false) {
            if(check_cycle(child, v)==true)
                return true;
        }
        else {
            if (child != p)
                return true;
        }
    }
    return false;
}

----------------------------------------------------------------------

// -->cycle detection for directed graph
bool is_cycle(ll v)
{
    visi[v] = 1;


    for (ll child : g[v]) {
        if (visi[child] == 0) {
            if (is_cycle(child) == true)
                return true;
        }
        else {
            if (visi[child] == 1)
                return true;
        }
    }

    visi[v] = 2;
    return false;
}

----------------------------------------------------------------------

//-> in out time of a node
vector<ll> In(100001);
vector<ll> Out(100001);
ll Time = 1;

void in_out_time(ll v)
{
    visi[v] = 1;
    In[v] = Time;
    Time++;
    for (ll child : g[v]) {
        if (visi[child] == 0)
            in_out_time(child);
    }

    Out[v] = Time;
    Time++;

}

----------------------------------------------------------------------

--> to find the distance of each node from root(single source sorthest path (on tress))

vector<ll> distance(100001);

void dfs(ll v,ll dist){
    visi[v] = 1;
    distance[v] = dist;

    for(ll child: g[v])
    {
        if(visi[child]==0)
            dfs(child,dist+1);
    }

}

//call from function -> dfs(root_node,0);

--> for finding the diameter
    -> call this dfs from random node
    -> find the farthest node from that random node
    -> now call the this dfs again from found farthest node
    -> now,at last the farthest distance obtained from second dfs is the diameter of the tree

----------------------------------------------------------------------

--> to find the sub-tree size of a node in a tree

vector<ll> subtree(10001, 0);

ll dfs(ll v) {

    visi[v] = 1;
    ll curr = 1;

    for (ll child : g[v]) {
        if (visi[child] == 0)
            curr += dfs(child);
    }
    subtree[v] = curr;
    return curr;
}

*/

int main()
{

    int nodes, edges, source, destination;
    cout << "Enter the number of nodes and edges \n";
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the source and destinaiton node\n";
        cin >> source >> destination;
        // for undirected graph
        graph[source].push_back(destination);
        graph[destination].push_back(source);

        /*
               -->for directed graphs<--
            graph[source].push_back(destination);

         */
    }

    // The Adjacency list representation of  the graph
    cout << "The Adjacency list representation of  the graph is \n";
    for (int i = 1; i <= nodes; i++)
    {
        // cout << i << " ";
        cout << "for vertex " << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "-->" << graph[i][j];
        }
        cout << endl;
    }

    /*
       Use of Dfs function;
        cout<< "DFS Traversal of this graph is \n";
        dfs(5);
    */

    // Aplication of DFS traversal is to find if the graph is connected or not below is the implementation of it
    int connected_components = 0;
    for (int i = 1; i <= nodes; i++)
    {
        if (visited[i] == false)
        {
            dfs(i);
            connected_components++;
        }
    }

    if (connected_components > 1)
    {
        cout << "\nThe graph is dis-connected and number of dis-connected components are " << connected_components;
    }
    else
    {
        cout << "\nThe graph is not dis-connected";
    }

    return 0;
}

/*
V.V.V IMP

-->to detect a cycle in a graph

  If a component contains c nodes and no cycle, it must contain exactly c − 1 edges (so it has to be a tree). If there arec or more edges, the component surely contains a cycle.


*/