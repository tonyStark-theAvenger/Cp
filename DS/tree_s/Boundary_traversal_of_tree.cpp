#include <bits/stdc++.h>

using namespace std;

/* 
 This is a importent question for interviews there are two variations of it
  1) print in Anti-Clockwise order
  2) print in Clockwise order

  Refer:- https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
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

node *CreateTree()
{
    node *root = NULL;

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    if (data == -1)
        return root;
    root = new node(data);
    cout << "Enter data to the left of " << data << endl;
    root->left = CreateTree();
    cout << "Enter data to the right of " << data << endl;
    root->right = CreateTree();

    return root;
}

//Function to print leaf nodes in a tree form left to right
void printLeafNodes(node *root)
{
    if (root == NULL)
        return;

    printLeafNodes(root->left);
    if (root->left == NULL && root->right == NULL)
        cout << root->data << " ";
    printLeafNodes(root->right);
}

//Function to print left boundry in top down manner
void printLeftBoundary(node *root)
{
    if (root == NULL)
        return;

    if (root->left)
    {
        cout << root->data << " ";
        printLeftBoundary(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        printLeftBoundary(root->right);
    }
}

//Function to print Right Boundary node in bottom top manner

void printRightBoundary(node *root)
{
    if (root == NULL)
        return;

    if (root->right)
    {
        printRightBoundary(root->right);
        cout << root->data << " ";
    }
    else if (root->left)
    {
        printRightBoundary(root->left);
        cout << root->data << " ";
    }
}

void printBoundary(node *root)
{
    if (root == NULL)
        return;

    //To print root data first
    cout << root->data << " ";
    //Print leftmost nodes of left subtree in top down manner
    printLeftBoundary(root->left);
    //print leaf nodes of left subtree
    printLeafNodes(root->left);
    //print leaf nodes of right subtree
    printLeafNodes(root->right);
    //Print rightmost nodes of right subtree in top down manner
    printRightBoundary(root->right);
}

int main()
{
    // node *root = CreateTree();
    struct node *root = new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->left->right->left = new node(10);
    root->left->right->right = new node(14);
    root->right = new node(22);
    root->right->right = new node(25);

    printBoundary(root);
    return 0;
}