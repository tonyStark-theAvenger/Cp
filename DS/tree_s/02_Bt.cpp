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

int search(vector<int> in, int l, int r, int key)
{
    for (int i = l; i <= r; i++)
        if (in[i] == key)
            return i;

    return -1;
}

//Function to build tree from preorder and inorder
node *treeFromPreAndIn(vector<int> pre, vector<int> in, int l, int r)
{
    static int idx = 0;
    if (l > r)
        return NULL;

    int curr = pre[idx];
    idx++;
    node *newNode = new node(curr);
    if (l == r)
    {
        return newNode;
    }

    int pos = search(in, l, r, curr);

    newNode->left = treeFromPreAndIn(pre, in, l, pos - 1);
    newNode->right = treeFromPreAndIn(pre, in, pos + 1, r);

    return newNode;
}

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
}
void postOrder(node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

node *treeFromPostAndIn(vector<int> post, vector<int> in, int l, int r)
{
    static int idx = post.size() - 1;
    if (l > r)
        return NULL;

    int curr = post[idx];
    idx--;
    node *newNode = new node(curr);
    if (l == r)
    {
        return newNode;
    }

    int pos = search(in, l, r, curr);

    newNode->right = treeFromPostAndIn(post, in, pos + 1, r);
    newNode->left = treeFromPostAndIn(post, in, l, pos - 1);

    return newNode;
}
int main()
{
    node *root;
    vector<int> pre = {0, 1, 3, 4, 2, 5};
    vector<int> in = {3, 1, 4, 0, 5, 2};

    vector<int> post = {4, 2, 5, 3, 1};
    root = treeFromPreAndIn(pre, in, 0, in.size() - 1);
    // root = treeFromPostAndIn(post, in, 0, in.size() - 1);

    postOrder(root);

    return 0;
}
