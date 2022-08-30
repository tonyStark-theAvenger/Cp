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
  Usually iterative methods are faster than recursive one's.
 */

//recursive function to find preorder traversal
void preorder(node *root)
{
  if (root == nullptr)
    return;
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

//iterative function to find preorder traversal
void preorder_i(node *root)
{
  if (root == NULL)
    return;
  stack<node *> s;
  s.push(root);
  while (!s.empty())
  {
    node *temp = s.top();
    s.pop();
    cout << temp->data << " ";
    if (temp->right != NULL)
      s.push(temp->right);
    if (temp->left != NULL)
      s.push(temp->left);
  }
}

//recursive function to find inorder traversal
void inorder(node *root)
{
  if (root == nullptr)
    return;
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

//iterative function to find inorder traversal
void inorder_i(node *root)
{
  if (root == NULL)
    return;
  stack<node *> s;
  node *curr = root;

  while (!s.empty() || curr != NULL)
  {
    while (curr != NULL)
    {
      s.push(curr);
      curr = curr->left;
    }
    node *temp = s.top();
    s.pop();
    cout << temp->data << " ";
    if (temp->right != NULL)
      curr = temp->right;
  }
}

//recursive function to find postorder traversal
void postorder(node *root)
{
  if (root == nullptr)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

//iterative function to find postorder traversal
void postorder_i(node *root)
{
  if (root == NULL)
    return;
  stack<node *> s;
  stack<node *> ans;

  s.push(root);

  while (!s.empty())
  {
    node *temp = s.top();
    s.pop();
    ans.push(temp);
    if (temp->left != NULL)
      s.push(temp->left);
    if (temp->right != NULL)
      s.push(temp->right);
  }

  while (!ans.empty())
  {
    cout << ans.top()->data << " ";
    ans.pop();
  }
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

//finction to find if given key present in an tree
bool find(node *root, int key)
{
  if (root == NULL)
    return NULL;

  if (root->data == key || find(root->left, key) || find(root->right, key))
    return true;

  return false;
}

// Recursive finction to create tree
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

int main()
{

  node *root = createTree();
  cout << "Preorder traversal of tree is : ";
  preorder(root);
  cout << "\nInorder traversal of tree is : ";
  inorder(root);
  cout << "\nPostorder traversal of tree is : ";
  postorder(root);
  cout << "\nLevelorder traversal of tree is : ";
  levelorder(root);
  cout << endl;
  postorder_i(root);
  vector<int> ans;
  ans.push_back()

      /* 
  // struct Node *root = new Node(10);
  // root->left = new Node(11);
  // root->left->left = new Node(7);
  // root->right = new Node(9);
  // root->right->left = new Node(15);
  // root->right->right = new Node(8);
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  
  Given binary tree is :
                      10
                   /     \ 
                  11       9
                 /        / \
                7        15  8

  

  cout << "Preorder is: " << endl;
  preorder(root); //10 11 7 9 15 8
  cout << "\nInorder is : " << endl;
  inorder(root); //7 11 10 15 9 8
  cout << "\nPostorder is: " << endl;
  postorder(root); //7 11 15 8 9 10
  cout << "\nlevelorder is: " << endl;
  levelorder(root); //
  // cout << root->left->right->data;
  cout << "\nHeight of tree is: " << height(root) << endl;
  */

      return 0;
}
