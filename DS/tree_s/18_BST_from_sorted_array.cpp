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

void pre(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}

/* 
Approach:- get the middle of array and make it root of a BST and do the same recursively for lefft and right side of an array
 */

node *sortedArrayToBST(vector<int> ar, int l, int h)
{

    if (l > h)
        return NULL;

    int mid = ((l + h) / 2);

    node *root = new node(ar[mid]);

    root->left = sortedArrayToBST(ar, l, mid - 1);
    root->right = sortedArrayToBST(ar, mid + 1, h);

    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    sort(ar.begin(), ar.end());

    node *root = sortedArrayToBST(ar, 0, ar.size() - 1);

    pre(root);

    return 0;
}