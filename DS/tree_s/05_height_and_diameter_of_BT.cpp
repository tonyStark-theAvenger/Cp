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

//time complexity O(n)
int height(node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

//Time complexity O(n*n)
int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    int currDia = lHeight + rHeight + 1;

    int lDia = diameter(root->left);
    int rDia = diameter(root->right);

    return max(currDia, max(lDia, rDia));
}

//Optimised diameter calculation in O(n) time
int optimisied_dia(node *root, int *height)
{
    if (root == NULL)
    {

        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDia = optimisied_dia(root->left, &lh);
    int rDia = optimisied_dia(root->right, &rh);

    int currDia = lh + rh + 1;

    *height = max(lh, rh) + 1;

    return max(currDia, max(lDia, rDia));
}

int main()
{

    node *root = createTree();
    // cout << "Height of this tree is : " << height(root) << " and it's diameter is : " << diameter(root);
    int h = 0;
    cout << " " << optimisied_dia(root, &h) << endl;
    return 0;
}