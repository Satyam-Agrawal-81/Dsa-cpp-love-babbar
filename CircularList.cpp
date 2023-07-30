#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //by default memebers are private so we have to use public: there above...
}*start=NULL,*last=NULL;


void create(){
    char  ch;
    do{
    Node* newnode,*current;
    newnode=(Node*)malloc(sizeof(Node));
    cout<<"Enter the value in newnode: ";
    cin>>newnode->data;
    newnode->next=start;
    if(start==NULL)
    {
        start=newnode;
        current=newnode;
        last=current;
    }
    else{
        current->next=newnode;
        current=newnode;
        last=current; //newnode->next=start set earlier...
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

void print(Node* &head){
    Node* temp=head;
    cout<<temp->data<<"->";
    temp=temp->next;
    while(temp!=head){
        
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

void insertAtBegin(Node* &head,Node*&last){
Node * newnode=(Node*)malloc(sizeof(Node));
cout<<"Enter the value of newnode: ";
cin>>newnode->data;
// Node* temp=head;
newnode->next=head;
head=newnode;
last->next=head;
}

void insertAtEnd(Node * &head,Node*&last){
    Node *newnode=(Node*)malloc(sizeof(Node));
    cout<<"Enter the node value to be inserted: ";
    cin>>newnode->data;
    newnode->next=last->next;
    last->next=newnode;
    last=newnode;
}

void insertAtPosition(Node* &head,Node*&last){
    int pos;
    cout<<"Enter the position at which the node is to be inserted: ";
    cin>>pos;
    if(pos<1||pos>length(head)+1)
    cout<<"You have entered INVALID position!!!";
    else if(pos==1)
    insertAtBegin(head,last);
    else if(pos==length(head)+1)
    insertAtEnd(head,last);
    else{
        Node * newnode=(Node*)malloc(sizeof(Node));
   cout <<"Enter the value in newnode: ";
   cin>>newnode->data;
   Node*temp=head;
   int cnt=1;
   while(cnt<pos-1){
    temp=temp->next;
    cnt++;
   }
   newnode->next=temp->next;
   temp->next=newnode;
   
    }
    
}

int main(){
    create();
    print(start);
    insertAtBegin(start,last);
    print(start);
    insertAtEnd(start,last);
    print(start);
    insertAtPosition(start,last);
    print(start);
    return 0;
}