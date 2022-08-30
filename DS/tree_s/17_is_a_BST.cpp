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

bool is_valid_BST(node *root, int minRange, int maxRange)
{
    if (root == NULL)
        return true;

    if (root->data > minRange && root->data < maxRange && is_valid_BST(root->left, minRange, root->data) && is_valid_BST(root->right, root->data, maxRange))
        return true;

    return false;
}

int main()
{

    cout << "SEE the function above\n";

    return 0;
}