#include <bits/stdc++.h>

using namespace std;

/*
      V.V.V Important question asked in most of the interviews.
      algorithm:- hair and tortoise algorithm
      Refer:- https://www.youtube.com/watch?v=Fj1ywT9ETQk&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=61
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

void makeCycle(node *&head, int pos)
{
    node *tmep = head;
    node *start;

    int count = 1;
    while (tmep->next != nullptr)
    {
        if (count == pos)
            start = tmep;
        tmep = tmep->next;
        count++;
    }
    tmep->next = start;
}

//Function to detect cycle(Hair and tortoise algorithm)
bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }
    return 0;
}


//function to return the start node from where cycle started of if no cycle return NULL

ListNode *detectCycle(ListNode *head) {

    ListNode * slow = head;
    ListNode * fast = head;

    bool is_cycle = false;

    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {

            //if cycle is found
            //1)make slow to head & do not do anything to fast
            //2) now move both at one place forward at a time
            //3) the node at which this two becomes same is a node where cycle started.
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }

    }
    return NULL;


//Finction to remove cycle
    node *removeCycle(node * head)
    {
        node *slow = head;
        node *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }


        //make fast to head and do not do anything to slow
        //now,move fast and slow at one step at one time
        //when they become equal 1)make slow->next = NULL.

        fast = head;

        while (fast->next != slow->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = nullptr;

        return head;
    }

    void display(node * head)
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
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
            head = insert_at_end(head, x);
        }
        makeCycle(head, 3);
        // display(head);
        cout << detectCycle(head) << endl;
        head = removeCycle(head);
        display(head);

        return 0;
    }