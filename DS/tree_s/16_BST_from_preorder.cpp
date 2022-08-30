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

void in(node *root)
{
    if (root == NULL)
        return;

    in(root->left);
    cout << root->data << " ";
    in(root->right);
}

//Time complexity O(log(n));
node *BST_from_preorder(vector<int> pre, int *index, int key, int minRange, int maxRange, int n)
{

    if (*index >= n)
        return NULL;
    node *root = NULL;
    if (key > minRange && key < maxRange)
    {
        root = new node(key);
        *index = *index + 1;

        if (*index < n)
        {
            root->left = BST_from_preorder(pre, index, pre[*index], minRange, key, n);
        }
        if (*index < n)
        {
            root->right = BST_from_preorder(pre, index, pre[*index], key, maxRange, n);
        }
    }

    return root;
}

int main()
{
    vector<int> pre = {7, 5, 4, 6, 8, 9};
    int index = 0;
    node *root = BST_from_preorder(pre, &index, pre[0], INT_MIN, INT_MAX, pre.size());
    in(root);

    return 0;
}