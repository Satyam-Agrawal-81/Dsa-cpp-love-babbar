#include<iostream>
using namespace std;

class deque{

int *arr;
int front;
int rear;
int size;
public:
//Initialze data structure
deque(int n){
size=n;
arr=new int[n];
front=rear=-1;
}

void push_front(int x){
 if((front==0 && rear==size-1)||((front !=0) && rear==(front-1)%(size-1)))
 {
    cout<<"The queue is full\n";
    return;
 }
 else if(front==-1){
  front=rear=0;
 }
 else if(front==0 && rear!=(size-1)){
    front=size-1;
 }
 else{
    front--;
 }
 arr[front]=x;

}
 bool isFull(){
    if((front==0 && rear==size-1)||(front!=0 && (rear==(front-1)%(size-1) )))
    return true;
    else
    return false;
 }

void push_rear(int x){
    // if((front==0 && rear==size-1)||((front!=0)&& rear==(front-1)%(size-1)))
    if(isFull())
 {
    cout<<"The queue is full\n";
    return;
 }
//  else if(front==-1)
else if(isEmpty())
 front=rear=0;
 else if(rear==size-1 && front!=0)
 rear=0;
 else 
 rear++;

 arr[rear]=x;
}

int pop_front(){
   if(front==-1){
    cout<<"Queue is empty!!\n";
    return -1;
   }
   int ans=arr[front];
   if(front==rear){ //single element
   front=rear=-1;
   }
   else if(front==size-1){
front=0;  //to maintain cyclic nature
   }
   else{
 front++;
   }
   return ans;
}

int pop_rear(){
    if(front==-1){
        cout<<"Queue is empty!!\n";
        return -1;
    }
    int ans=arr[rear];
    if(front==rear){//single element is present
  front=rear=-1;
    }
    else if(rear==0){
     rear=size-1; // to maintain cyclic flow..
    }
    else rear--;
    return ans;
}

bool isEmpty(){
    if(front==-1)
    return true;
    else 
    return false;
}

int getFront(){
    if(isEmpty()){
        cout<<"Sorry Queue is empty so cant get front.."<<endl;
        return -1;
    }
    else{
        return arr[front];
    }
}
int getRear(){
    if(isEmpty()){
        cout<<"Sorry Queue is empty so cant get rear.."<<endl;
        return -1;
    }
    else return arr[rear];
}

};
int main(){
 deque d(5);
 d.push_front(11);
 d.push_front(22);
 d.push_rear(81);
 d.push_rear(20);

cout<< d.pop_front()<<endl;
 cout<<d.pop_rear();
return 0;
}