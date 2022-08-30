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
IMP

Refer:- https://www.youtube.com/watch?v=NIJN63astRc&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=107
 */

int maxPathSumUtil(node *root, int &ans)
{
    if (root == NULL)
        return 0;

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);

    return max(root->data, max(root->data + left, root->data + right));
}
int maxPathSum(node *root)
{
    int ans = INT16_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}

int main()
{
    node *root = createTree();
    cout << maxPathSum(root);

    return 0;
}
