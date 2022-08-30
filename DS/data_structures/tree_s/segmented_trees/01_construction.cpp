#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int ar[100005], tree[4 * 100005];

//buid finction to build a segment tree
int construct_tree(int i, int l, int r)
{
  if (l == r)
  {
    tree[i] = ar[l];
    return tree[i];
  }
  int mid = (l + r) / 2;
  tree[i] = construct_tree(2 * i + 1, l, mid) + construct_tree(2 * i + 2, mid + 1, r);
  return tree[i];
}

//Query function to get sum of a query
int get_sum(int i, int low, int high, int l, int r)
{
  if (low >= l && high <= r)
    return tree[i];

  if (high < l || low > r)
    return 0;

  int mid = (low + high) / 2;

  return get_sum(2 * i + 1, low, mid, l, r) + get_sum(2 * i + 2, mid + 1, high, l, r);
}

//update function to update the node value in an segment tree
void update_tree(int i, int low, int high, int node, int val)
{
  if (low == high)
    tree[low] += val;
  else
  {
    int mid = (low + high) / 2;
    if (node <= mid && node >= low)
      update_tree(2 * i + 1, low, mid, node, val);
    else
      update_tree(2 * i + 2, mid + 1, high, node, val);
  }
}

int main()
{
  int n;
  cout << "Enter the size of an array: ";
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> ar[i];
  int ans = construct_tree(0, 0, n - 1);
  while (1)
  {
    int q;
    cout << "Query type: ";
    cin >> q;
    if (q == 1)
    {
      int l, r;
      cin >> l >> r;
      cout << get_sum(0, 0, n - 1, l, r);
    }
    else if (q == 2)
    {
      int x, v;
      cin >> x >> v;
      int dif = v - ar[x];
      update_tree(0, 0, n - 1, x, dif);
    }
  }
  return 0;
}