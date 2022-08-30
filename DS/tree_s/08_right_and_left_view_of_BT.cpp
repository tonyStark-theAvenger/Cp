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

// Reccursive finction to create tree
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

//My method in O(n) time complexity
void rightView_my(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    cout << root->data << " ";
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp != NULL)
        {
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
        else if (!q.empty())
        {
            cout << q.back()->data << " ";
            q.push(NULL);
        }
    }
}

//Function to calculate rightview of a BT in O(n) time complexity
void rightView(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {

        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
                cout << q.front()->data << " ";

            node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

//Function to calculate leftview of a BT in O(n) time complexity
void leftView(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {

        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                cout << q.front()->data << " ";

            node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main()
{
    node *root = createTree();
    cout << "Right view of given tree is : ";
    rightView(root);
    cout << "\nLeft view of given tree is : ";
    leftView(root);
    return 0;
}