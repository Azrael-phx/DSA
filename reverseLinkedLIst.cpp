#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next; 
};
void reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;

    Node* forward=NULL;

    while(curr!=NULL){
        forward =  curr->next; 
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}
void print(Node* &head)
    {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* forth = new Node();

    head->data = 10;
    head ->next = second;

    second->data = 20;
    second->next = third;

    third->data = 25;
    third->next = forth;

    forth->data = 30;
    forth->next = NULL;


    print(head);
    cout<<endl;
    reverse(head);
    print(head);

    return 0;
}

