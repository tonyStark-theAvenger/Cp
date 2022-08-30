#include <bits/stdc++.h>

using namespace std;

/* 
The below mentioned funcition uses O(n) time complexity and O(1) space.

another approach is to use stack which uses O(n) space;

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

//to get length of list
int getLength(node *head)
{
    node *temp = head;
    int ans = 0;
    while (temp != NULL)
    {
        ans++;
        temp = temp->next;
    }

    return ans;
}

//to reverse the list
node *reverse(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *nextptr = NULL;

    while (curr != NULL)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }

    return prev;
}

//Function to check palindrome
bool isPalindrome(node *head)
{
    int l = getLength(head);

    if (l == 1)
        return true;
    bool is_odd = false;
    if (l & 1)
        is_odd = true;

    node *temp = head;

    l = l / 2 - 1;

    while (l--)
        temp = temp->next;

    node *newhead;
    if (is_odd)
    {
        newhead = temp->next->next;
        temp->next = NULL;
    }
    else
    {
        newhead = temp->next;
        temp->next = NULL;
    }

    newhead = reverse(newhead);
    while (newhead != NULL)
    {
        if (head->data != newhead->data)
            return false;

        newhead = newhead->next;
        head = head->next;
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