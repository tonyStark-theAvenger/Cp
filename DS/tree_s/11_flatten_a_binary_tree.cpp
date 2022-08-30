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

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* 

eg:-                           4
                                \
       4                         9
      /  \                        \
     9    5     --flatting--->     1
    / \    \                        \
   1   3    6                        3
                                      \
                                       5
                                        \
                                         6

 Refer :- https://www.youtube.com/watch?v=WR6-DrAsNpc&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=104

 */

void flatten(node *root)
{

    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->left != NULL)
    {
        flatten(root->left);
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *t = root->right;

        while (t->right != NULL)
            t = t->right;

        t->right = temp;
    }

    flatten(root->right);
}

int main()
{
    node *root = createTree();
    inorder(root);
    flatten(root);
    cout << endl;
    inorder(root);

    return 0;
}