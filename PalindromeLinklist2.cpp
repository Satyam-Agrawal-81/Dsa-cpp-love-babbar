#include<iostream>
#include<vector>
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
    newnode->next=NULL;
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



Node * getMid(Node *&head){
    Node * slow=head;
    Node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
   //move fast with two steps and slow with one step (i.e. normal )
   fast=fast->next->next;
   slow=slow->next;

   //in this way when fast reaches NULL slow reaches to mid value...
    }
    return slow;
}

Node * reverse(Node *head){
    Node *current=head;
    Node *prev=NULL;
    Node *nextnode=head;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
//    head=prev;
return prev; //since prev would be recent head when reversed..
}


bool isPalin (Node *head){
    if(head==NULL || head->next==NULL)
    return true; //if empty LL or only one element is present..
    

    Node *middle=getMid(head);
    Node *temp=middle->next;
    middle->next=reverse(temp);

    Node *head1=head;
    Node *head2=middle->next;

    while(head2!=NULL){
        if(head1->data!=head2->data)
        return false;

        head1=head->next;
        head2=head2->next;
    }
    //jaisi input me aayi thi vesi bana do vapis>>
     temp=middle->next;
    middle->next=reverse(temp);
    return true;
}



void print(Node* &head){
    Node* temp=head;
 
    while(temp!=NULL){
        
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}


int main(){
    create();
    print(start);

    bool ans = isPalin(start);

   if(ans==true)
   cout<<"LinkedList is palindrome"<<endl;
   else
   cout<<"No!! LinkedList is not a palindrome!!\n";

    return 0;
}