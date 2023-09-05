#include<iostream>
#include<list>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

        Node(int x) : data(x), next(nullptr) {}
};  

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forw;

    while(curr!=NULL){
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}

Node* middleOfLL(Node* head){
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* reverseKGroups(Node* head, int k){
    Node* curr = head;
    Node* prev = NULL;
    Node* forw = NULL;
    int count = 0;

    while(curr!=NULL && count<k){
        forw = curr->next;
        curr->next = prev;
        prev = curr; 
        curr = forw;
        count++;
    }
    
    while(forw != NULL){
        curr->next = reverseKGroups(forw, k);
    }
    return prev;
}

bool checkCircularLL(Node*head){
    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp = temp->next;
    }
    if(temp==head)
            return true;
    return false;
}

//FLOYD CYCLE DETECTION ALGO
//Get starting node of cycle
Node* FloydDetectLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(slow && fast->next && fast){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
            return slow;
    }   
    return NULL;
}
Node* getStartingNode(Node* head){
    Node* slow = head;
    Node* intersection = FloydDetectLoop(head);

    while(slow!=intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

Node* removeDuplicates(Node* head){
    if(head==NULL)
            return NULL;
    Node* curr = head;
    while(curr && curr->next!=NULL){
        if(curr->data == curr->next->data){
            Node* duplicate = curr->next;
            curr->next = curr->next->next;
            delete duplicate;
        }
        else        
            curr = curr->next;
    }
    return head;
}

Node* mergeTwoSortedLL(Node* n1, Node* n2){
    Node* curr1 = n1;
    Node* curr2 = n2;
    Node* next1 = curr1->next;
    Node* next2 = curr2->next;

    while(next1!=NULL && curr2!=NULL ){
        if(curr2->data >= curr1->data && curr2->data <= next1->data ){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1= curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            next1 = next1->next;
        }
        if(next1 == NULL){
            curr1 ->next = curr2;
            return n1;
        }
    }
    return n1;
}

Node* Sort0s1s2s(Node* head){
    if(head== NULL){
        return NULL;
    }
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    Node* temp = head;
    while(temp !=NULL){
        if(temp->data == 0){
            c0++;
        }
        else if(temp->data == 1)
            c1++;
        else 
            c2++;
        temp = temp->next;
    }
    temp = head;
    while(temp !=NULL){
        if(c0!=0){
            temp->data = 0;
            c0--;
        }
        else if(c1!=0){
            temp->data = 1;
            c1--;
        }
        else if(c2!=0){
            temp->data = 2;
            c2--;
        }

        temp = temp->next;
    }
    return head;
}

bool palindromeLL(Node* head){
    Node* mid = middleOfLL(head);
    Node* temp = mid->next;

   temp = reverse(temp);
   Node* head1 = head;
   Node* head2 = temp;
    while (head2 != NULL) {
        if (head2->data != head1->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* four = new Node(30);
    Node* five = new Node(10);
    Node* six = new Node(10);

    head->next = second;
    second->next = third;
    third->next = four;

    four->next = five;
    five->next = six;
    six->next = NULL;

    // head = reverse(head);
    // Node* temp = head;
    // while(temp!=NULL){
    //     cout << temp->data<< " ";
    //     temp = temp->next;
    // }

    // head = reverseKGroups(head, 2);
    // Node* temp = head;
    // while(temp!=NULL){
    //     cout << temp->data<< " ";
    //     temp = temp->next;
    // }
    // cout << checkCircularLL(head);
    // Node* temp = Sort0s1s2s(head);
    // while(temp!=NULL){
    //     cout << temp->data<< " ";
    //     temp = temp->next;
    // }
    cout << palindromeLL(head);
}