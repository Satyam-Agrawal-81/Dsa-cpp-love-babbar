//LINKLIST..
#include<iostream>
using namespace std;

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

Node * removeDuplicates(Node * &head){
    Node *curr=head;

    while(curr!=NULL){
    
    if((curr->next!=NULL) && curr->data==curr->next->data){
    Node* next_next=curr->next->next;
    Node* NodeToDelete=curr->next;
    delete(NodeToDelete);
    curr->next=next_next;
    
    }

    else{
    curr=curr->next;    
    }
    }
    return head;
}

int main(){
 cout<<"Enter a sorted linkedlist:-\n";
 create();
 print(start);
 removeDuplicates(start);
 print(start);
return 0;
}