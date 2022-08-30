
//This is the program to  ilustrate the Disjoint set union(DSU) concept in graph with all optimization applied

#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

//globel declearation
int size[1001];
int parent[1001];

void make_set()
{
    for (int i = 0; i <= 1001; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
}

//--->Function to find super parent of a node<---

/*
 -->without any optimization<--

// int find_super_parent(int a)
// {
//     if (parent[a] == a)
//     {
//         return a;
//     }
//     else
//     {
//         return find_super_parent(parent[a]);
//     }
// }
*/

//-->with path optimization<--
int find_super_parent(int a)
{
    if (parent[a] == a)
    {
        return a;
    }
    else
    {
        int super_parent = find_super_parent(parent[a]);
        parent[a] = super_parent;

        return super_parent;
    }
}
/*
ll super_parent(ll n)
{
    if (parent[n] == n)
        return n;
    else
        return super_parent(parent[n]);
}

void make_union(ll a, ll b)
{

    ll p_a = super_parent(a);
    ll p_b = super_parent(b);

    if (p_a == p_b)
        cout << a << " and " << b << " already belongs to same set.\n";
    else
    {
        if (size[p_a] < size[p_b])
        {
            parent[p_a] = p_b;
            size[p_b] += size[p_a];
        }
        else
        {
            parent[p_b] = p_a;
            size[p_a] += size[p_b];
        }
    }
*/


/*---------------------------------------------------------------------------*/

//--->Function to make union of two elements/sets<---
//-->without any optimization
// void make_union(int a, int b)
// {
//     int pa = find_super_parent(a);
//     int pb = find_super_parent(b);

//     if (pa != pb)
//     {
//         cout << a << " " << b << endl;
//         parent[pa] = pb;
//         cout << "The set consisting entered elements has been merged" << endl;
//     }
//     else
//     {
//         cout << "Entered elements already belongs to same set" << endl;
//     }
// }

//-->with size optimization
void make_union(int a, int b)
{
    int pa = find_super_parent(a);
    int pb = find_super_parent(b);

    if (pa == pb)
    {
        cout << "Entered elements already belongs to same set" << endl;
    }

    else
    {
        if (size[pa] < size[pb])
        {
            parent[pa] = pb;
            size[pb] += size[pa];
        }
        else
        {
            parent[pb] = pa;
            size[pa] += size[pb];
        }
    }
}

int main()
{
    int n;
    int a, b;
    make_set();
    cout << "How many elements set do you want " << endl;
    cin >> n;
    int s;
    if (n % 2 == 0)
    {
        s = n / 2;
    }
    else
    {
        s = ((n / 2) + 1);
    }

    for (int i = 0; i < s; i++)
    {
        cin >> a >> b;
        cout << "Before union :-\nparent of " << a << " is " << parent[a] << " and " << b << " is " << parent[b] << endl;
        make_union(a, b);
        cout << "After union :-\nparent of " << a << " is " << parent[a] << " and " << b << " is " << parent[b] << endl;
    }

    return 0;
}
