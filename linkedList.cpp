#include<iostream>
#include<list>
using namespace std;

class ListNode{
    public:
        int data;
        ListNode *next;

    ListNode(int data){
        this->data = data;
        next = NULL;
    }
};
ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward;

        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

int main(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    ListNode* temp = reverseList(head);
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}