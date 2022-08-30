#include <bits/stdc++.h>

using namespace std;

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

/* 
V.V.V Imp-topic

Given two nodes of BT we have to find there lowest common ancestor

eg:- 
    given tree is:
                    A
                   / \                  
                  B   C
                 / \  
                D   E 

    here,LCA of D & E is B.

 */

// Recursive finction to create tree
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

//Function to get path of given form root to given key
bool getPath(node *root, vector<int> &ans, int key)
{
    if (root == NULL)
        return false;

    ans.push_back(root->data);

    if (root->data == key)
        return true;

    if (getPath(root->left, ans, key) || getPath(root->right, ans, key))
        return true;

    ans.pop_back();

    return false;
}

//In this approach we are traversing tree 2 times
//time complexity :- O(N) and space Complexity :- O(N)
int LCA(node *root, int n1, int n2)
{

    vector<int> path1;
    vector<int> path2;

    if (!getPath(root, path1, n1) || !getPath(root, path2, n2))
        return -1;

    for (int i = 0; i < path1.size() && path2.size(); i++)
        if (path1[i] != path2[i])
            return path1[i - 1];

    return -1;
}

//In this approach we are traversing tree 1 time
//time complexity :- O(N) and space Complexity :- O(1)
node *LCA_o(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    node *leftLCA = LCA_o(root->left, n1, n2);
    node *rightLCA = LCA_o(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    if (leftLCA == NULL)
        return rightLCA;
    return leftLCA;
}

int main()
{

    node *root = createTree();
    int LCa = LCA(root, 2, 3);
    if (LCa != -1)
        cout << "LCA : " << LCa;
    else
        cout << "\nAny of the node is not in the tree.";
    node *Lca = LCA_o(root, 2, 3);
    if (!Lca)
        cout << "\nAny of the node is not in the tree.";
    else
        cout << "\nLCA : " << Lca->data;
    return 0;
}