#include<iostream>

using namespace std;

class KQueue{
    public:

        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freespot;
        int *next;

    public:
        KQueue(int n, int k){
            this -> n = n;
            this -> k = k;

            front = new int[k];
            rear = new int[k] ;

            for(int i = 0; i<n; i++){
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];

            for(int i = 0; i< n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;

            arr = new int[n];
            freespot = 0;
        }

        void enqueue(int data, int qn){
            //overflow
            if(freespot == -1){
                cout << "NO empty space available"<< endl;
            }
            //find first free first index
            int index = freespot;
            freespot = next[index];
            
            if(front[qn-1]==-1){
                front[qn - 1] = index;
            }
            else{
                //link a new element -- [5,4,3,4,-1,-1] link 5 to 3 ..... q1 = [5,3,4] q2 = [4,4]
                next[rear[qn-1]] = index;
            }
            //update next 
            next[index] = -1;
            //update rear
            rear[qn-1] = index;
            //push element
            arr[index] = data;
        }

        int dequeue(int qn){
            //underflow
            if(front[qn-1]==-1){
                cout << "No element to pop" << endl;
            }
            int index = front[qn - 1];
            front[qn-1] = next[index];

            next[index] = freespot;
            freespot = index;
            return arr[index];
        }

};


int main(){
    KQueue q(10,3);
    q.enqueue(25,1);
    q.enqueue(15,1);
    q.enqueue(50,2);
    q.enqueue(20,1);
    q.enqueue(35,1);

    cout<< q.dequeue(1) << endl;
    cout<< q.dequeue(2) << endl;
    cout<< q.dequeue(1) << endl;
    cout<< q.dequeue(1) << endl;


    return 0;

}
