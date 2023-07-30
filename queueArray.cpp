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
    front=0;
    rear=0;
}
void enqueue(int data){
    if(rear==size)
    cout<<"queue is full\n";
    else{
        arr[rear]=data;
        rear++;
    }
}
int dequeue(){ //dequeue from front as queue follows FIFO
    if(front==rear)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else{
        int ans=arr[front];
        arr[front]=-1;
        front++;
        if(front==rear){
            front=0;
            rear=0;
        }
         return ans ;
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