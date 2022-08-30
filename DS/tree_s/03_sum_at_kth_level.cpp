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
/* 
//Leveorder traversal
void levelorder(node *root)
{
    queue<node *> q;
    q.push(root);

    while (q.size())
    {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }

} */

void leveOrder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
        {

            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}

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

//sum of values at specific level

int SumAtk(node *root, int k)
{
    if (root == NULL)
        return -1;

    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int ans = 0;
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            if (level == k)
                ans += temp->data;

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return ans;
}

int main()
{

    node *root = createTree();

    int k;
    cin >> k;
    cout << "\nSum at level " << k << " is " << SumAtk(root, k);

    return 0;
}
