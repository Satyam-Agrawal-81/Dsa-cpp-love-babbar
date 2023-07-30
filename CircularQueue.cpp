#include<iostream>
using namespace std;
// enqueue->push  , dequeue->pop
class queue{
public:
    int front;
    int rear;
    int *arr;
    int size;
queue(int size){
    this->size=size;
    arr=new int[size];
    front=-1;
    rear=-1;
}
void enqueue(int data){
    if((front==0 && rear==size-1)||(rear==(front-1)%(size-1)))
    cout<<"queue is full\n";

    if(front==-1){  //first element to push..
        front=rear=0;
        arr[rear]=data;
    }
    else if(rear==size-1 && front!=0){
        rear=0;  //to maintain cycle nature
        arr[rear]=data;
    }
    else{ //normal flow
        rear++;
        arr[rear]=data;
    }
}
int dequeue(){ //dequeue from front..
    if(front==-1 )// front==-1 && rear==-1
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(front==rear){    //single elment in queue
    int ans=arr[front];
    front=rear=-1;
    return ans;
     
    }
    else if(front==size-1){
      int ans=arr[front];
      front=0;  // to maintain cycle nature
      return ans;
    }
   else{
    int ans=arr[front];
    front++;
    return ans;
   }
}

int frontElement(){  //to get the front element
if(front==rear){
    cout<<"queue is empty\n";
    return -1;
}
else{
    return arr[front];
}
}

bool isEmpty(){
    if(front==rear){
        return true;
    }
    else 
    return false;
}

};

int main(){
 queue q(8);
 q.enqueue(25);
 q.enqueue(10);
 cout<<"Front: "<<q.frontElement()<<endl;
 q.dequeue();
 cout<<"Front: "<<q.frontElement()<<endl;
if(q.isEmpty())
cout<<"queue is empty\n";
else
cout<<"Queue is not empty\n";

return 0;
}