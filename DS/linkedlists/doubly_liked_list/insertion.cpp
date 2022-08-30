#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == nullptr)
    {
        head = n;
        return;
    }

    head->prev = n;
    n->next = head;
    head = n;
}
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == nullptr)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = n;
    n->prev = temp;
}

void forward_print(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void reverse_print(node *&head)
{
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->prev;
    }
    cout << "NULL\n";
}
int main()
{
    int n;
    cin >> n;
    node *head = nullptr;

    while (n--)
    {
        int x;
        cin >> x;
        insertAtHead(head, x);
    }
    forward_print(head);
    reverse_print(head);
    return 0;
}