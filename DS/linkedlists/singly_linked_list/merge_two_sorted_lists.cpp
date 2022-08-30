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

//iterative finction of merging
node *merge_lists_iterative(node *&head1, node *&head2)
{
    node *ans = new node(-1);
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *ptr3 = ans;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }

        ptr3 = ptr3->next;
    }

    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
        ptr3->next = ptr1;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return ans->next;
}

//recursive finction to merge lists
node *merge_recursive(node *&head1, node *&head2)
{
    node *ans;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    if (head1->data < head2->data)
    {
        ans = head1;
        ans->next = merge_recursive(head1->next, head2);
    }
    else
    {
        ans = head2;
        ans->next = merge_recursive(head1, head2->next);
    }

    return ans;
}

int main()
{
    vector<int> l1 = {1, 4, 5, 7};
    vector<int> l2 = {2, 3, 6};
    node *head1 = NULL;
    node *head2 = NULL;
    for (int i = 0; i < l1.size(); i++)
        head1 = insert_at_end(head1, l1[i]);

    for (int i = 0; i < l2.size(); i++)
        head2 = insert_at_end(head2, l2[i]);

    cout << "Given two lists:\nL1: ";
    display(head1);
    cout << "L2: ";
    display(head2);
    cout << "New after merging this two lists is : \n";
    node *newnode = merge_recursive(head1, head2);
    display(newnode);
    return 0;
}