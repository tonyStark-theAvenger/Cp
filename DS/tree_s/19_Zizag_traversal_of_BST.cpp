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

void ZizagTraversal(node *root)
{
    if (root == NULL)
        return;

    stack<node *> curr, next;
    bool LtoR = true;

    curr.push(root);

    while (!curr.empty())
    {
        node *temp = curr.top();
        curr.pop();
        if (temp)
        {
            cout << temp->data << " ";

            if (LtoR)
            {
                if (temp->left)
                    next.push(temp->left);
                if (temp->right)
                    next.push(temp->right);
            }
            else
            {
                if (temp->right)
                    next.push(temp->right);
                if (temp->left)
                    next.push(temp->left);
            }
        }
        if (curr.empty())
        {
            LtoR = !LtoR;
            swap(curr, next);
        }
    }
}

int main()
{
    node *root = CreateTree();
    ZizagTraversal(root);
    return 0;
}