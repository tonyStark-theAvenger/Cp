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

void topView(node *root)
{
    queue<pair<node *, int>> q;
    map<int, int> m;

    q.push({root, 0});

    while (!q.empty())
    {
        pair<node *, int> p = q.front();
        q.pop();
        node *temp = p.first;
        int level = p.second;
        if (m[level] == 0)
        {
            m[level] = temp->data;
        }

        if (temp->left != NULL)
        {
            q.push({temp->left, level - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, level + 1});
        }
    }

    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->second << " ";
    }
}

int main()
{

    node *root = createTree();
    cout << "Top view of given tree is : ";
    topView(root);
    cout << "\nBottom view of given tree is : ";
    // leftView(root);
    return 0;
}