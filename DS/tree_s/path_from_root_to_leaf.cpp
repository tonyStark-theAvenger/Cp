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

//function prints path form node to it's leaf nodes.
void path(node *root, vector<int> &p)
{
    if (root == NULL)
        return;

    p.push_back(root->data);

    if (root->left == NULL && root->right == NULL)
    {
        cout << "Path from root " << p[0] << " to leaf " << p[p.size() - 1] << " : ";
        for (int i = 0; i < p.size(); i++)
            cout << p[i] << " ";
        cout << endl;
    }

    path(root->left, p);
    path(root->right, p);

    p.pop_back();
}

int main()
{
    node *root = createTree();
    vector<int> p;
    path(root, p);
    return 0;
}