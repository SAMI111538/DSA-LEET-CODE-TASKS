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

void InsertAtHead(node* &head,int val)
{
    node* n = new node(val);
    
    if (head ==NULL){
        n->next = n;
        head = n;
    }
    node* temp = head;

    while(temp->next !=head)
    {
        temp = temp->next;
    }

    temp-> next = n;
    n->next = head;
    head = n;
}

void InsertAtTail(node* &head,int val)
{
    node* n = new node(val);
    node* temp = head;
    if(head==NULL)
    {
        InsertAtHead(head,val);
        return;
    }

    while(temp->next !=head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void display(node* &head)
{
    node* temp = head;

    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } 
    while (temp!=head);
    
}

void deletionAthead(node* &head)
{
    node* temp = head;
    while(temp->next !=head)
    {
        temp = temp->next;
    }

    node* todelete = head;
    temp->next= head->next;
    head = head->next;

    delete todelete;

}
void deletion(node* &head, int pos)
{
    if(pos ==1)
    {
        deletionAthead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while(count != pos-1)
    {
        temp = temp-> next;
        count ++;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;
}
int main()
{
    node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    display(head);
    
    InsertAtHead(head,5);
    display(head);
    cout<<"\n";
    deletion(head,5);
    display(head);
    cout<<"\n";
    deletionAthead(head);
    display(head);

    return 0;
}