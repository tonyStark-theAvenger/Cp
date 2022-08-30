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

node *createTree()
{
    node *root = NULL;

    cout << "\nEnter data : ";
    int data;
    cin >> data;
    if (data == -1)
        return root;

    root = new node(data);

    cout << "Enter data for left of " << data;
    root->left = createTree();

    cout << "Enter data for right of " << data;
    root->right = createTree();

    return root;
}

int total_no_of_nodes(node *root)
{
    if (root == NULL)
        return 0;

    return total_no_of_nodes(root->left) + total_no_of_nodes(root->right) + 1;
}

int sum_of_nodes(node *root)
{
    if (root == NULL)
        return 0;

    return sum_of_nodes(root->left) + sum_of_nodes(root->right) + root->data;
}

int main()
{

    node *root = createTree();

    cout << "Total number of nodes in given tree are: " << total_no_of_nodes(root) << " and their sum is : " << sum_of_nodes(root);

    return 0;
}