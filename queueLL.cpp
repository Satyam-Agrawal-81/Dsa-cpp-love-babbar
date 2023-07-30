#include<iostream>
using namespace std;
class queue{
    public:
int data;
queue* next;
//constructor
queue(int x){
    data=x;
    next=NULL;
}

};

class Solution{
   
    queue *front,*rear;
     public:
Solution(){
    front=NULL;
    rear=NULL;
}

void enQueue(int x){
queue*temp= new queue(x);
if(rear==NULL){
    front=rear=temp;
    return;
}
else{
    rear->next=temp;
    rear=temp;
}
}

int deQueue(){
if(front==NULL){
cout<<"Queue is Empty Already\n";
return -1;
}
else{
    queue * temp=front;
    front=front->next;

    if(front==NULL)
    rear=NULL; // kyuki rear ko null dene ki contion apan ne kahin rakhi nahi 
    int ans=temp->data;
    delete(temp);
    return ans;
}
}
};


int main(){
  Solution q;
    q.enQueue(10);
    q.enQueue(20);
    q.deQueue();
    cout<<q.deQueue()<<endl;
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    cout<<q.deQueue()<<endl;
    // cout << "Queue Front : " << ((front != NULL) ? (front)->data : -1)<< endl;
    // cout << "Queue Rear : " << ((rear != NULL) ? (rear)->data : -1);
return 0;
}
