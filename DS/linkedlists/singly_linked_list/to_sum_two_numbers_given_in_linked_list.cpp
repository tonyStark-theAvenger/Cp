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
        next = NULL;
    }
};

node *insert_at_end(node *head, int val)
{

    node *newNode = new node(val);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }

    node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void printList(node *head)
{
    if (head == NULL)
    {
        cout << "head is NULL\n";
        return;
    }
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node *solve(node *head1, node *head2)
{
    node *final_ans = new node(-1);
    node *ans = final_ans;
    int carry = 0, reminder;
    while (head1 != NULL && head2 != NULL)
    {
        int sum = head1->data + head2->data + carry;
        carry = sum / 10;
        reminder = sum % 10;
        // cout << sum << " " << reminder << endl;
        node *temp = new node(reminder);
        ans->next = temp;
        head1 = head1->next;
        head2 = head2->next;
        ans = ans->next;
    }

    while (head1 != NULL)
    {
        int sum = head1->data + carry;
        carry = sum / 10;
        reminder = sum % 10;
        node *temp = new node(reminder);
        ans->next = temp;
        head1 = head1->next;
        ans = ans->next;
    }
    while (head2 != NULL)
    {
        int sum = head2->data + carry;
        carry = sum / 10;
        reminder = sum % 10;
        node *temp = new node(reminder);
        ans->next = temp;
        head2 = head2->next;
        ans = ans->next;
    }

    if (carry)
    {
        node *temp = new node(carry);
        ans->next = temp;
        ans = ans->next;
    }

    return final_ans->next;
}

int main()
{
    start;

    node *head1 = NULL;
    node *head2 = NULL;
    head1 = insert_at_end(head1, 7);
    head1 = insert_at_end(head1, 5);
    head1 = insert_at_end(head1, 9);
    head1 = insert_at_end(head1, 4);
    head1 = insert_at_end(head1, 6);

    head2 = insert_at_end(head2, 8);
    head2 = insert_at_end(head2, 4);
    node *ans = solve(head1, head2);
    printList(ans);

    return 0;
}