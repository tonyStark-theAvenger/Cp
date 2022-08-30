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

void evenAfterOdd(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenStart = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;

    if (odd->next != NULL)
    {
        even->next = NULL;
    }
}

int main()
{
    node *head = nullptr;

    for (int i = 1; i <= 10; i++)
        head = insert_at_end(head, i);

    display(head);
    evenAfterOdd(head);
    display(head);
    return 0;
}