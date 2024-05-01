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

void display(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int length(node* &head) {
    node* temp = head;
    int l = 0;
    while (temp != NULL) {
        l++;
        temp = temp->next;
    }
    return l;
}

node* kappend(node* &head, int k) {
    node* newHead = NULL;
    node* newTail = NULL;
    node* tail = head;

    int l = length(head);

    k = k % l;
    int count = 1;
    while (tail->next != NULL) {
        if (count == l - k) {
            newTail = tail;
        }
        if (count == l - k + 1) {
            newHead = tail;
        }

        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    node* head = NULL;
    for (int i = 0; i < 6; i++) {
        InsertAtTail(head, arr[i]);
    }

    display(head);

    node* newhead = kappend(head, 3);
    display(newhead);

    return 0;
}
