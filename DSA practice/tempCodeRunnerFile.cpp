#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

void insertAthead(node* &head,  int value)
{
    node* n = new node(value);
    n->next = head;
    if (head !=NULL)
    {
        head->prev = n;
    }
    head =  n;
}
void insertAtTail(node* &head,  int value)
{
    node* n = new node(value);
    node* temp = head;

    if (head==NULL)
    {
        insertAthead(head,value);
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void deletionAtHead(node* &head)
{
    node* todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}
void deletion(node* &head, int pos)
{
    node* temp = head;
    int count = 0;

    if(pos==1)
    {
        deletionAtHead(head);
    }
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if(temp->next !=NULL)
    {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;

    delete temp;
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
    node* head = NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAthead(head,5);
    display(head);
    deletion(head,5);
    display(head);
    // deletionAtHead(head);
    // display(head);
    return 0;
}

