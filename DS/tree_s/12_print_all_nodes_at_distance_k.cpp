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

/* 
Refer:- https://www.youtube.com/watch?v=f-oTsCUCiXk&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=105
 */

//case 1
/* To print the nodes at distace k in subtree of any given node "n". */
void nodesInSubtree(node *n, int k)
{
    if (n == NULL || k < 0)
        return;

    if (k == 0)
        cout << n->data << " ";

    nodesInSubtree(n->left, k - 1);
    nodesInSubtree(n->right, k - 1);
}
//case 2
/* 
 returns distance from given node to it's ancestor.
 */
int nodesAtK(node *root, node *target, int k)
{
    if (root == NULL)
        return -1;

    if (root == target)
    {
        nodesInSubtree(target, k);
        return 0;
    }

    int dl = nodesAtK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
            cout << root->data << " ";
        else
            nodesAtK(root->right, target, k - dl - 2);
        return 1 + dl;
    }

    int dr = nodesAtK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << " ";
        else
            nodesAtK(root->left, target, k - dl - 2);

        return 1 + dr;
    }

    return -1;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    nodesAtK(root, root, 1);

    return 0;
}