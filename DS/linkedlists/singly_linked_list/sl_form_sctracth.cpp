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

node *insert_at_begin(node *&head, int val)
{
    node *n = new node(val);
    if (head == nullptr)
    {
        head = n;
        return head;
    }
    n->next = head;
    head = n;
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

// //function to find middle of list
// int getMiddle(node *head)
// {
//     if (head == NULL)
//         return -1;

//     node *slow = head;
//     node *fast = head;

//     while (fast != NULL && fast->next != NULL)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }

//     return slow->data;
// }

node *getMiddle(node *head)
{
    if (head == NULL)
        return NULL;

    node *fast = head;
    node *slow = head;
    node *prev_slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }
    return prev_slow;
}

node *reverse(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;

    while (curr)
    {

        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool isPalindrome(node *head)
{

    node *middle = getMiddle(head);

    node *newhead = middle->next;
    cout << newhead->data << endl;
    middle->next = NULL;

    newhead = reverse(newhead);

    while (head && newhead)
    {
        if (head->data != newhead->data)
            return false;

        head = head->next;
        newhead = newhead->next;
    }

    return true;
}
int main()
{
    node *head = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        head = insert_at_end(head, x);
    }
    display(head);
    cout << isPalindrome(head);
    return 0;
}