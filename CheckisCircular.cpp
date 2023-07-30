#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    //by default memebers are private so we have to use public: there above...
}*start=NULL;
// }*start=NULL,*last=NULL;


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
        // last=current;
    }
    else{
        current->next=newnode;
        current=newnode;
        // last=current; //newnode->next=start set earlier...
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

void insertAtBegin(Node* &head , Node* &last){
Node * newnode=(Node*)malloc(sizeof(Node));
cout<<"Enter the value of newnode: ";
cin>>newnode->data;
// Node* temp=head;
newnode->next=head;
head=newnode;
last->next=head;
}


void insertAtEnd(Node* &head , Node* &last){
    Node *newnode=(Node*)malloc(sizeof(Node));
    cout<<"Enter the node value to be inserted: ";
    cin>>newnode->data;
    newnode->next=head;
    last->next=newnode;
    last=newnode;
}



bool isCircular(Node* &head){
    if(head==NULL)
    return true;
    Node*temp=head->next;
    while(temp!=NULL || temp!=head){
        temp=temp->next;
    }
    if(temp==head)
    return true;

    return false;
}

bool Detectloop(Node* &head){
    if(head==NULL)
    return false;

    map<Node*,bool>visited;
    Node *temp=head;

    while(temp!=NULL){
        //cycle is present
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
  return false;
}

Node *floydDetectLoop(Node * &head){
    if(head==NULL)
    return NULL;

    Node *slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL)
        fast=fast->next;

        slow=slow->next;
        if(slow==fast){
            cout<<"Present at"<<slow->data<<endl;
        return slow;
    }
    }
return NULL;
}

Node *getStartingNode(Node *head){
    if(head==NULL)
    return NULL;

    Node * intersection=floydDetectLoop(head);
    if(intersection==NULL)
    return NULL;
    Node*slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

Node *removeLoop(Node *head){
    if(head==NULL)
    return NULL;

    Node *startOfLoop=getStartingNode(head);
    if(startOfLoop)
    return head;

    Node *temp=startOfLoop;
    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
}

// void insertAtPosition(Node* &head,Node*&last){
//     int pos;
//     cout<<"Enter the position at which the node is to be inserted: ";
//     cin>>pos;
//     if(pos<1||pos>length(head)+1)
//     cout<<"You have entered INVALID position!!!";
//     else if(pos==1)
//     insertAtBegin(head,last);
//     else if(pos==length(head)+1)
//     insertAtEnd(head,last);
//     else{
//         Node * newnode=(Node*)malloc(sizeof(Node));
//    cout <<"Enter the value in newnode: ";
//    cin>>newnode->data;
//    Node*temp=head;
//    int cnt=1;
//    while(cnt<pos-1){
//     temp=temp->next;
//     cnt++;
//    }
//    newnode->next=temp->next;
//    temp->next=newnode;
   
//     }
    
// }

int main(){
    create();
    print(start);
    // insertAtBegin(start,last);
    // print(start);
    // insertAtEnd(start,last);
    // print(start);
// Check if it is circular linked list..
if(isCircular(start))
cout<<"Yes\n";
else cout<<"No\n";
if(Detectloop(start))
cout<<"YESS LOOPP";
else cout<<"NO\n";
if(floydDetectLoop(start))
cout<<"Loop is Present\n";
else
cout<<"No loop is present\n";
Node * loop=getStartingNode(start);
cout<<loop->data<<endl;

removeLoop(start);
print(start);

    // insertAtPosition(start,last);
    // print(start);
    return 0;
}