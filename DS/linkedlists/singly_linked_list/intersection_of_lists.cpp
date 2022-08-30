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

//function to get lenght of list
int getLength(node *&head)
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

//finction to find intersection point and return it's data
int getIntersection(node *&head1, node *&head2)
{
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    node *ptr1;
    node *ptr2;
    int d;

    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d--)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
            return -1;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
            return ptr1->data;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

int main()
{
    cout << "See the function in the code :)";

    return 0;
}