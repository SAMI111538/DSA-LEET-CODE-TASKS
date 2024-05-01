#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int value) {
        data = value;
        next = NULL;
    }
};

void InsertAtTail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

int length(node* &head)
{
    node* temp = head;
    int l = 0;
    while(temp !=NULL)
    {
        temp = temp ->next;
        l++;
    }
    return l;
}

void intersect(node* &head1,node* &head2,int pos)
{
    node* temp1 = head1;
    

    pos--;
    while(pos--)
    {
        temp1 = temp1->next;
    }

    node* temp2 = head2;

    while(temp2 ->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2-> next =  temp1;
}

int intersection(node* &head1,node* &head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    
    node* ptr1;
    node* ptr2;;

    int d = 0;

    if(l1>l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    if(l2>l1)
    {
        d = l2 - l1;
        ptr2= head1;
        ptr1 = head2;
    }

    while(d)
    {
        ptr1 = ptr1->next;

        if(ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while(ptr1->next !=NULL && ptr1->next !=NULL)
    {
        if(ptr1 == ptr2)
        {
            return ptr1 ->data;
        }
        ptr1 =ptr1->next;
        ptr2 =ptr2->next;
    }

    return -1;
}

void display(node* &head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl; 
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    InsertAtTail(head1,1);
    InsertAtTail(head1,2);
    InsertAtTail(head1,3);
    InsertAtTail(head1,4);
    InsertAtTail(head1,5);
    InsertAtTail(head1,6);
    InsertAtTail(head2,9);
    InsertAtTail(head2,10);

    display(head1);
    display(head2);
    intersect(head1,head2,5);
    cout<<intersection(head1,head2);
    return 0;
}