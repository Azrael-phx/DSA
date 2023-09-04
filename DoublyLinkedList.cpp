#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //Constructor
    Node(int data){
        this -> data = data;
        this->next = NULL;
        this -> prev = NULL;
    }
};

void insertAtHead(Node* &head, int d){

    Node* temp = new Node(d);
    temp ->next = head;
    head ->prev = temp;
    head = temp;

}

void insertAtTail(Node* &tail, int d){

    Node* temp = new Node(d);
    tail ->next = temp;
    temp -> prev = tail;
    tail = temp;
}

void insertAtAnyPosition(Node* &tail, Node* &head, int pos, int d){

    if(pos == 1){
        insertAtHead(head, d);
    }

    Node* newNode = new Node(d);
    Node* temp = head;
    int cnt = 1;

    while(cnt < pos - 1){
        temp = temp ->next;
        cnt++;
    }
    // last pos pe aagye
    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    newNode ->next = temp->next;
    temp->next -> prev = newNode;
    temp ->next = newNode;
    newNode -> prev = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp->data << " ";
        temp = temp -> next;
    }
    cout << endl;
} 
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = head;

    print(head);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    print(head);

    insertAtTail(tail, 5);
    print(head);

    insertAtTail(tail, 0);
    print(head);

    insertAtAnyPosition(tail, head, 2, 100);
    print(head);
}