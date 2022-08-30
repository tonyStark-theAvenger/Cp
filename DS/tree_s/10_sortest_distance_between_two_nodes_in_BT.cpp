#include <bits/stdc++.h>

using namespace std;

/* 
Problem:- to find sortest distance between two given nodes.

Approach :- The trick here is that the sortest path between two nodes always passes through their lowest common ancestor.
 so,
  step1: find their LCS
  step2: find distance of each given node from their LCS let say this are d1 & d2.
  step3: the ans is d1+d2.

 */

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Reccursive finction to create tree
node *createTree()
{

    node *root = NULL;

    cout << "Enter data : ";
    int data;
    cin >> data;
    if (data == -1)
        return root;

    root = new node(data);

    cout << "Enter data for left of " << data << endl;
    root->left = createTree();

    cout << "Enter data for right of " << data << endl;
    root->right = createTree();

    return root;
}

//funciton to get LCS

node *getLCA(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    node *lLCA = getLCA(root->left, n1, n2);
    node *rLCA = getLCA(root->right, n1, n2);

    if (lLCA && rLCA)
        return root;

    if (!lLCA)
        return rLCA;

    return lLCA;
}

int get_distance(node *root, int k, int dist)
{
    if (root == NULL)
        return -1;

    if (root->data == k)
        return dist;

    int left = get_distance(root->left, k, dist + 1);

    if (left != -1)
        return left;

    return get_distance(root->right, k, dist + 1);
}

int sortest_distance(node *root, int n1, int n2)
{
    node *LCA = getLCA(root, n1, n2);

    int d1 = get_distance(LCA, n1, 0);
    int d2 = get_distance(LCA, n2, 0);
    return d1 + d2;
}

int main()
{
    node *root = createTree();
    int n1, n2;
    cin >> n1 >> n2;
    cout << sortest_distance(root, n1, n2) << endl;

    return 0;
}