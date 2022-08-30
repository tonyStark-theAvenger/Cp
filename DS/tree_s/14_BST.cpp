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

void inOrder(node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

node *insert_in_BST(node *root, int val)
{
    if (root == NULL)
    {
        root = new node(val);
        return root;
    }

    if (root->data > val)
        root->left = insert_in_BST(root->left, val);
    else if (root->data < val)
        root->right = insert_in_BST(root->right, val);

    return root;
}

int main()
{
    vector<int> ar = {9, 5, 1, 0, 6, 10, 22};
    node *root = NULL;
    for (int i = 0; i < ar.size(); i++)
        root = insert_in_BST(root, ar[i]);

    inOrder(root);
    return 0;
}