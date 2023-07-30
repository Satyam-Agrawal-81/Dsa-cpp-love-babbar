#include<iostream>
using namespace std;

//Sorting linked list of 0s 1s 2s .. with replacement of data ..

class Node{
    public:
    int data;
    Node *next;
}*start=NULL;

void create(){
    char ch;
    do{

    Node * newnode=(Node*)malloc(sizeof(Node));
     Node* current;
    cout<<"Enter the value of newnode: ";
    cin>>newnode->data;
    if(start==NULL){
      start=newnode;
      current=newnode;
      newnode->next=NULL;
    }
    else{
        current->next=newnode;
        current=newnode;
        newnode->next=NULL;
    }
    cout<<"Do you want to create more newnode- Y/N: ";
    cin>>ch;
    }while(ch!='N');

}

Node *print(Node *&head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
   cout<<"NULL"<<endl;
}

Node * sortLL(Node * &head){
int zerocnt=0;
int onecnt=0;
int twocnt=0;
Node *temp=head;

while(temp!=NULL){
    if(temp->data==0)
    zerocnt++;
    else if(temp->data==1)
    onecnt++;
    else
    twocnt++;

    temp=temp->next;
}



temp=head;
while(temp!=NULL){
  if(zerocnt!=0){
    temp->data=0;
    zerocnt--;
  }
  else if(onecnt!=0){
    temp->data=1;
    onecnt--;
  }
  else {//remaining for 2's
    temp->data=2;
  }

    temp=temp->next;
}
return head;
}

int main(){
 cout<<"Enter a  linkedlist with random values among 0 , 1 and 2 only :-\n";
 create();
 print(start);
 cout<<"Sorting the linklist and we get:\n";
 sortLL(start);
 print(start);
 
return 0;
}