#include<iostream>
using namespace std;

class Node{

    public: //always do it public..
  int data;
  Node* next;

}*start=NULL;

Node*curr=start;
Node*pre=NULL;


void create(){
    char  ch;
    do{
    Node* newnode,*current;
    newnode=(Node*)malloc(sizeof(Node));
    cout<<"Enter the value in newnode: ";
    cin>>newnode->data;
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
        current=newnode;
    }
    else{
        current->next=newnode;
        current=newnode;
    }
    cout<<"Do you want to create more newnode- Y/N: ";
    cin>>ch;
    }while(ch!='N');
}

int length(Node *&start){
    int len=0;
        Node*temp=start;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
}

// void InsertAtBegin(Node* &head, int d){
//     // New node creation
//     Node *temp = new Node(d);
//       temp->next=head;
//       head=temp;   
// }

void InsertAtBegin(Node* &head){
    Node* beginnode=(Node*)malloc(sizeof(Node));
    cout<<"Enter the data in beginnode: ";
    cin>>beginnode->data;
   if(head==NULL){
    head=beginnode;
    beginnode->next=NULL;
   }
   else{
         Node*temp=head;
         beginnode->next=temp;
         head=beginnode;
   }
}

void InsertAtEnd(Node* &head){
Node*temp; //declaration of temp
Node*lastnode=(Node*)malloc(sizeof(Node));
cout<<"Enter the data of lastnode: ";
cin>>lastnode->data;

if(head==NULL){
head=lastnode;
lastnode->next=NULL;
}
else{
    temp=head;
    while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=lastnode;
lastnode->next=NULL;
}
}

void print(Node* &head){
Node* temp=head;
while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
}
cout<<"NULL"<<endl;
}

void insertAtPosition(Node* &head){
    Node *newnode=(Node*)malloc(sizeof(Node));
   

    if(head==NULL){
    cout<<"Enter the data in newnode to be inserted: ";
    cin>>newnode->data;
       head=newnode;
       newnode->next=NULL;
    }
    else{
        int pos;
        cout<<"Enter the position at which node is to be inserted: ";
        cin>>pos;
        if(pos<1 || pos>length(start)+1)
        cout<<"You have entered INVALID position!!!";
        else if(pos==1)
        InsertAtBegin(head);
        else if(pos==length(head)+1)
        InsertAtEnd(head);
        else{
             cout<<"Enter the data in newnode to be inserted: ";
             cin>>newnode->data;
            int cnt=1;
            Node*temp=head;
            while(cnt<pos-1){
               temp=temp->next;
               cnt++;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            
        }
    }
}


void DeleteAtBegin(Node*&head){
    if(head==NULL){
        cout<<"There is no data . List is already empty!!";
    }
    else{
        Node*temp=head;
        head=temp->next;
        //memory freeing start node
        delete temp;
    }
}

void DeleteAtEnd(Node* &head){
    if(head==NULL){
        cout<<"The linked list is already empty!!!";
    }
    else{
        Node * temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        Node*temp2=temp->next;
        temp->next=NULL;
        delete temp2;
    }
}

void DeleteAtPosition(Node* &head){
    
    if(head==NULL){
    cout<<"The linked list is already empty!!!";
    }
    else {
      int pos;
      cout<<"Enter the position at which the node is to be deleted: ";
      cin>>pos;
      if(pos==1)
      DeleteAtBegin(head);
      else if(pos==length(head))
      DeleteAtEnd(head);
      else{
        int cnt=1;
        Node*temp=head;
        while(cnt<pos-1){
            temp=temp->next;
            cnt++;
        }
        Node*temp2=temp->next;
        temp->next=temp2->next;
        temp2->next=NULL;
        delete temp2;
      }


    }
}

void reverse(Node* &head){
Node*nextnode,*prev,*current;
prev=NULL;
current=nextnode=head;
while(nextnode!=NULL){
    nextnode=nextnode->next;
    current->next=prev;
    prev=current;
    current=nextnode;
}
head=prev;
}


// void recursiveReverse(Node*&head,Node*&curr,Node* &prev){
// curr=head;
// prev=NULL;

// //basecase
// if(curr==NULL){
//     head=prev;
//     return;
// }
// Node*nextnode=curr->next;
// recursiveReverse(head,nextnode,curr);
// curr->next=prev;


// }

// int  getMiddleElement(Node *&head){
//     Node*fast=head->next;
//     Node*slow=head; //these are two pointers and we will use it is such that when fast moves two steps , slow moves one step and thus when fast reaches the end , slow reaches the middle in half the time complexicity as compare to normal traversing of whole list.. 

//     if(head==NULL || head->next==NULL)
//     return head->data;
//     if(head->next->next=NULL)
//     return head->next->data;

//     while(fast!=NULL){
//         fast=fast->next;
//         if(fast!=NULL)
//         fast=fast->next;

//         slow=slow->next;
//     }
//   return slow->data; //the middle element
// }

// Node *findMiddleElement(Node * &head){
//     // return getMiddleElement(head);
//     cout<<getMiddleElement(head);
// }

int main(){

    // Created a new node
//  Node* n1 = new Node(10);
//  cout<<n1->data<<endl;
//  cout<<n1->next<<endl;

// Head point to node n1
// Node * head=n1;
create();
print(start);

// InsertAtBegin(start,12);

InsertAtBegin(start);
InsertAtEnd(start);
print(start);
DeleteAtBegin(start);
DeleteAtEnd(start);
print(start);
insertAtPosition(start);
print(start);
DeleteAtPosition(start);
print(start);
// reverse(start);
// print(start);

// cout<<"Getting the middle element of the linked list:\n";
// print(start);
// cout<<"The middle element is : "<<getMiddleElement(start)<<endl;
// findMiddleElement(start);
// recursiveReverse(start,curr, pre);
// print(start);
return 0;
}