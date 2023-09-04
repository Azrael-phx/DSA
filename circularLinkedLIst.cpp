#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }

    ~Node(){
        int value = this-> data;
         if(this->next != NULL) {
            delete next;
            next = NULL;
         }
         cout<<"Memory is free "<<" " << value << endl;
    }
};
//Code to remove duplicates from a sorted linked List
Node* removeDuplicates(Node* tail){
    Node* temp = tail;
    if(tail  == NULL)    
        return NULL;
    
    Node* curr = tail;
    while(curr && curr->next!=temp){
        while(curr->data == curr->next->data){
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }
    return tail;
}


void print(Node* &tail){
    Node* temp = tail;
    do{
        cout<< " "<< tail->data << " ";
        tail = tail->next;
    }
    while(tail!=temp);
    cout<<endl;
}

void insertNode(Node* &tail, int element , int d){
    
    if(tail == NULL){
        Node * newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;
        }

        //element found -- curr is representing element wala node

        Node* temp = new Node(d);
        temp ->next= curr->next;
        curr -> next = temp;
    }
}
int main(){
    Node* tail = NULL;
    
    insertNode(tail, 2, 4);
    insertNode(tail, 4, 5);
    insertNode(tail, 5, 6);
    insertNode(tail, 5, 5);
    insertNode(tail, 6, 6);
    print(tail);

    removeDuplicates(tail);
    print(tail);
}