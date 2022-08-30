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

//time complexity in Bst is O(log(n));
node *searchInBST(node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->data == key)
        return root;

    if (key > root->data)
        return searchInBST(root->right, key);

    return searchInBST(root->left, key);
}

/* 
-->Deletion functions
-> case 1:- When node is leaf
-> case 2:- When node has one child
-> case 3 :- When node has two childs
 */
node *inorderSucc(node *root)
{
    node *curr = root;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

node *delete_in_BST(node *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (root->data < key)
    {
        root->right = delete_in_BST(root->right, key);
        return root;
    }
    else if (root->data > key)
    {
        root->left = delete_in_BST(root->left, key);
        return root;
    }
    else
    {
        //now node has been found which is to be deleted;

        //case 1 :- leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        //case 2:- node with one child
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        //case 3:- node with two childs
        else
        {
            node *temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right = delete_in_BST(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    vector<int> ar = {9, 5, 1, 0, 6, 10, 22};

    node *root = NULL;
    for (int i = 0; i < ar.size(); i++)
        root = insert_in_BST(root, ar[i]);
    inOrder(root);
    /* 
  //Searching demo
    node *ans = searchInBST(root, 90);
    if (ans == NULL)
        cout << "No node with that value.";
    else
        cout << "Node with that value exists.";
         */
    root = delete_in_BST(root, 5);
    cout << endl;
    inOrder(root);
    return 0;
}