#include<iostream>
using namespace std;

class stack{
    public:
    int data;
    stack*next;
   
    //Constructor
    stack(int val){
        this->data=val;
        this->next=NULL;
       
    }
    
};
class answer{
    stack* top;
    public:
    answer(){
        top=NULL;
    }
void push(int val){
    stack* temp=new stack(val);

    // if stack(heap ) is full then inserting will lead stack overfloew..
    if(temp==NULL){
        cout<<"Stack Overflow\n";
        return ; //or can give exit(1);
    }
    temp->data=val;
    temp->next=top;
    top=temp;
}

bool isEmpty(){
    if(top==NULL)
    return true;
    else 
    return false;

}

int peek(){
    if(!isEmpty()){
        return top->data;

    }
    else { cout<<"The stack is empty so can't peek!"<<endl;
        exit(1);
        }
}

void pop(){
    stack * temp;
    if(top==NULL){
        cout<<"Stack undeflow"<<endl;
        exit(1); // or return;

    }
    else{
        temp=top;
        top=top->next;//that is point to the lower element below top in stack.
        
            // This will automatically destroy
            // the link between first node and second node
 
            // Release memory of top node
            // i.e delete the node
            free(temp);
    }
}

void display(){
    stack*temp;
    if(top==NULL)
    {
        cout<<"stack underflow"<<endl;
        return ;

    }
    else{
        temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
            // if(temp!=NULL)
            // cout<<"->";
        }
        cout<<endl;
    }
}

};

int main(){
 answer s;

 //push
 s.push(11);
 s.push(22);
 s.push(81);
 s.push(25);
 //display
 s.display();
 //top element
 cout<<s.peek()<<endl;
 //delete top elements
 s.pop();
 s.pop();
 //display again
 s.display();
 //top elemenmt now 
 cout<<s.peek()<<endl;
//  check for empty or not 

 if(s.isEmpty())
 cout<<"The stack is empty\n";
 else 
 cout<<"The stack is not empty!!\n";

return 0;
}

