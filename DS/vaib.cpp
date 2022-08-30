#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

int main()
{

    SinglyLinkedListNode *head1 = new SinglyLinkedListNode(1);

    return 0;
}