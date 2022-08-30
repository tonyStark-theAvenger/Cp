#include <bits/stdc++.h>

using namespace std;

/*
   Balanced tree :- is a tree where difference between the height of each node's left and right subtree is <=1;

eg:-
          A
         / \
        B   C
       /
      D
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

// Reccursive finction to create tree

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

int getHeight(node *root)
{
    if (root == NULL)
        return 0;

    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

//time compexity O(n^2)
bool isBalancedTree(node *root)
{
    if (root == NULL)
        return true;

    if (!isBalancedTree(root->left))
        return false;
    if (!isBalancedTree(root->right))
        return false;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    if (abs(lh - rh) <= 1)
        return true;

    return false;
}

//optimized time compexity of O(n)
bool opitimizedIsBalanced(node *root, int *height)
{
    if (root == NULL)
        return true;

    int lh = 0, rh = 0;

    if (!opitimizedIsBalanced(root->left, &lh))
        return false;

    if (!opitimizedIsBalanced(root->right, &rh))
        return false;

    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
        return true;

    return false;
}

int main()
{
    node *root = createTree();
    int height = 0;
    if (opitimizedIsBalanced(root, &height))
        cout << "Given tree is a Balanced height tree.";
    else
        cout << "Given tree is a not a Balanced height tree.";

    return 0;
}