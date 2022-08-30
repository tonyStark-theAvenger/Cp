#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

node *insert_at_end(node *&head, int val)
{

    node *n = new node(val);
    if (head == nullptr)
    {
        head = n;
        return head;
    }
    node *temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = n;
    return head;
}

void display(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//to find length of a list
int getLength(node *&head)
{
    node *temp = head;
    int ans = 0;

    while (temp != nullptr)
    {
        ans++;
        temp = temp->next;
    }
    return ans;
}

//funciton to append nodes
void append_K(node *&head, int k)
{
    node *temp = head;
    int l = getLength(head);

    int match = l - k - 1, count = 0;

    while (count != match)
    {
        temp = temp->next;
        count++;
    }
    cout << temp->data << endl;

    node *neawhead = temp->next;
    node *temp2 = temp->next;
    temp->next = NULL;

    while (temp2->next != nullptr)
        temp2 = temp2->next;

    temp2->next = head;
    head = neawhead;
}
int main()
{
    node *head = nullptr;
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        head = insert_at_end(head, x);
    }
    display(head);
    // cout << count(head);
    append_K(head, k);
    display(head);
    return 0;
}