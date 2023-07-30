// Stack without using STL;
#include<iostream>
using namespace std;
// Stack can be implemented by array and linked list
// Stack through array:-
class Stack{
public:
int *arr;
int top;
int size;

//behaviour
Stack(int size){
    this->size=size;
    arr=new int[size];
    top=-1;
}

void push(int ele){
  if(size-top>1){  //at least one space is available
    top++;
    arr[top]=ele;
  }
  else{
    cout<<"Stack Overflow"<<endl;
  }
}

void pop(){
 if(top>=0){
    top--;
 }
 else{
    cout<<"Stack Underflow"<<endl;
 }
}

int peek(){
if(top>=0 && top<size)
return arr[top];
else
{
    cout<<"stack is empty"<<endl;
    return -1;
 }
 }



bool isEmpty(){
if(top==-1)
return true;

return false;
}

};
int main(){
 Stack st(5);

 st.push(2);
 st.push(5);
 st.push(3);

 cout<<st.peek()<<endl;
 st.pop();
 cout<<st.peek()<<endl;

 if(st.isEmpty()){
  cout<<"Stack is Empty!!\n";
 }
 else
 cout<<"Stack is not empty//"<<endl;
return 0;
}
