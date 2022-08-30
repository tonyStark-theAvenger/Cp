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

void preOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//Time complexity O(n)
void sumReplacement(node *root)
{
    if (root == NULL)
        return;

    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left != NULL)
        root->data += root->left->data;

    if (root->right != NULL)
        root->data += root->right->data;
}

int main()
{
    /*         
           11
          /  \ 
         4     7
        / \   /  \
       2   5 6    3
   */

    node *root = new node(11);
    root->left = new node(4);
    root->left->left = new node(2);
    root->left->right = new node(5);
    root->right = new node(7);
    root->right->left = new node(6);
    root->right->right = new node(3);

    preOrder(root);
    sumReplacement(root);
    cout << endl;
    preOrder(root);

    return 0;
}