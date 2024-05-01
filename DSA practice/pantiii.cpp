#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

void InsertAtHead(node* &head,int value)
{
    node* n = new node(value);
    n-> next = head;
    head = n;
}
void InsertAtTail(node* &head,int value)
{
    //is function main sb se pahly ak 2 parametres pass karny hai
    //jis k baad hum ny node ka ak object bna gya hai jis main constructor pass karaya tha
    node* n = new node(value);
    if(head == NULL)
    {
        head = n;
        return;
    }
    //ak temperature object bnaya gya t ha jis main head pointer pass karaya hai 
    node*temp = head;
    while(temp->next != NULL)
    {
        //jb tak null ni ata hai hum ny temp ko tempnext wala assign kar  dena hai
        temp= temp->next;
    }
    // jb null a jaye ga to hum ny us next ko wo wala temp ki value de deni hai 
    temp->next = n;
}

void display(node* &head)
{
    node* temp = head;
    while(temp != NULL)  // Fix: Change temp->next != NULL to temp != NULL
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node* &head, int key)
{
    node* temp = head;
    while(temp-> next != NULL)
    {
        if(temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

node* reversek(node* head,int k)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count=0;
    while(currptr!=NULL && count<k)
    {
        nextptr = currptr->next;
        currptr-> next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr!=NULL)
    {
        head->next = reversek(nextptr,k);
    }
    return prevptr;
}
void deletionAtHead(node* &head)
{
    node* todelete = head;
    head = head->next;

    delete todelete;
}
void deletion(node* &head, int value)
{
    if(head == NULL)
    {
        return;
    }
    if(head->next == NULL)
    {
        deletionAtHead(head);
        return;
    }
    node* temp = head;

    while(temp->next->data != value)
    {
        temp = temp-> next;
    }
    node* todelete = temp->next;
    temp-> next = temp->next->next;
    delete todelete;
}

node* reverse(node* &head)
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL)
    {
        nextptr = currptr->next;
        currptr-> next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

bool detectCycle(node* &head)
{
    node* slow = head;
    node* fast = head;
    while(fast !=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast ==slow)
        {
            return true;
        }
    }
    
    return false;
}

void makeCycle(node* &head, int pos)
{
    node* temp = head;
    node* startNode;
    int count = 1;

    while(temp->next != NULL)
    {
        if(count == pos)
        {
            startNode = temp ;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

void removeCycle(node* head)
{
    node* fast = head;
    node* slow = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;

    } while (fast!=slow);
    fast = head;
    while(slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
    
}
node* reverseRecursive(node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}
int main()   
{
    node* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);

    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    // display(head);
    // InsertAtHead(head,5);  
    // display(head);
    // cout<<search(head,3);
    // deletion(head,2);
    // deletionAtHead(head);
    // node* newhead = reverse(head);
    // node* newhead = reverseRecursive(head);
    // int k =2;
    // node* newhead = reversek(head,k);
    // display(newhead );
    makeCycle(head, 3);    
    //display(head);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);
    return 0;
}