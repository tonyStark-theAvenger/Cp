/*
   -->This is program to 
   1)create a graph, 
   2)represent graph in adjancy list format and 
   3)perform a DFS traversal on it and application of DFS traversal
*/

#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;
vector<int> graph[10];
bool visited[10];

//DFS traversal function of graph
void dfs(int s)
{
    visited[s] = true;
    cout << s << " ";
    for (int i = 0; i < graph[s].size(); ++i)
    {
        if (visited[graph[s][i]] == false)
            dfs(graph[s][i]);
    }
}

int main()
{

    int nodes, edges, source, destination;
    cout << "Enter the number of nodes and edges \n";
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the source and destinaiton node\n";
        cin >> source >> destination;
        //for undirected graph
        graph[source].push_back(destination);
        graph[destination].push_back(source);

        /*
               -->for directed graphs<--
            graph[source].push_back(destination);
         
         */
    }

    //The Adjacency list representation of  the graph
    cout << "The Adjacency list representation of  the graph is \n";
    for (int i = 1; i <= edges + 1; i++)
    {
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

    //Aplication of DFS traversal is to find if the graph is connected or not below is the implementation of it
    int connected_components = 0;
    for (int i = 1; i <= edges; i++)
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
