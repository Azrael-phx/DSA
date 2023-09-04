#include <iostream>
#include<map>
#include<unordered_map>

using namespace std;

class Node{
        public:
        int data;
        Node*next;

        Node(int data){
            this->data = data;
            this ->next = NULL;
        }
};
//ye wala ni chlra
Node* removeUnsortedDuplicates(Node* &head){
    if(head == NULL)
        return NULL;

    Node* temp = head;
    map <Node*, bool> visited;

    while(temp && temp->next!=NULL){
        while(temp && temp->next && visited[temp] == true){
            temp->next = temp->next->next;
            temp = temp->next;
        }
        temp = temp->next;
    }
    return head;
}
//Unsorted Linked list
Node *removeDuplicates(Node *&head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    unordered_map<int, bool> map;
    while(curr != NULL){
        if(map.find(curr->data) == map.end()){
            //Element not found in map
            map.emplace(curr->data, true);
            prev = curr;
            curr = curr->next;
        }
        else if(map[curr->data] == true){
            // Element found in map
            prev->next = curr->next;
            curr = curr->next;
        }
    }
    return head;
}
//Aur acha code ==== BEST

Node * removeDuplicatesfinal( Node *head) 
    {
        if(head==NULL){
        return NULL;
    }
    Node* curr = head;
    map<int ,bool>  visited;
    visited[curr->data] = true;
    Node* prev = curr;
    curr = curr->next;
    while(curr!=NULL){   
        if(visited[curr->data]==true){
            prev->next = curr->next;
            free(curr);
        }else{
            visited[curr->data] = true;
            prev = curr;
        }
        curr = prev->next;
    }
    return head;

    }

void print(Node* &head){
    Node*temp = head;
    while(temp!=NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<< endl;
}

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    
    tail->next = temp;
    tail = tail ->next;
}

//Sorted linkedList 
Node* removeDuplicatess(Node* tail){
    Node* temp = tail;
    if(tail  == NULL)    
        return NULL;
    
    Node* curr = tail;
    while(curr && curr->next!=NULL){
        while(curr->next && curr->data == curr->next->data){
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }
    return tail;
}

int main(){
    Node *head = new Node(10);
    
        Node* tail = head;
    
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 40);
    insertAtTail(tail, 40);
    insertAtTail(tail, 20);
    print(head);
    removeDuplicates(head);
    print(head);
    return 0;
}


