#include <bits/stdc++.h>

using namespace std;

/* 
      V.V.V Important question asked in most of the interviews.w
 */

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

node *reverse_k_node(node *&head, int k)
{
    node *prev = nullptr;
    node *curr = head;
    node *forward = nullptr;

    int count = 0;

    while (curr != nullptr && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != nullptr)
        head->next = reverse_k_node(forward, k);

    return prev;
}

int main()
{
    int n, k;
    cin >> n >> k;
    node *head = nullptr;
    while (n--)
    {
        int x;
        cin >> x;
        head = insert_at_end(head, x);
    }
    cout << "Given list is: \n";
    display(head);
    head = reverse_k_node(head, k);
    cout << "After reversing k nodes the list is: \n";
    display(head);

    return 0;
}