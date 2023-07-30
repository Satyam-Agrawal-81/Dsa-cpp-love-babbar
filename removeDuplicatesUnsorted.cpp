#include<iostream>
#include<map>
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

Node * removeDuplicates(Node *&head){
    if(head=NULL)
    return NULL; //nullptr
Node *curr=head;
while(curr!=NULL){
    Node *temp=curr->next;
    while(temp!=NULL){
        if(curr->data==temp->data){
            Node *next_next=temp->next;
            
        Node * NodeToDelete = temp;
        delete NodeToDelete;
        curr->next=next_next;
        temp=curr->next;
        }
        else{
              temp=temp->next;
        }
      
    }
    curr=curr->next;
}
return head;
}

//We can go for second method to remove dupli from unsorted LL as sort it and apply method of remove dupli from sorted list.

//Third method is maps:O(n)
Node * removeDupliMaps(Node * &head){
    if(head==NULL)
    return NULL;
    // map<Node*,bool>visited;
    map<int,bool>visited;
    Node*curr=head;
    Node *prev=NULL;
    while(curr!=NULL){
        if(visited[curr->data]){ //deletion procedure
        prev->next=curr->next;
        delete curr;
        curr=prev->next;
        }
        else{
            visited[curr->data]=true;
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

int main(){
 cout<<"Enter a unsorted linkedlist:-\n";
 create();
 print(start);
 cout<<"Removing Duplicates\n";
//  removeDuplicates(start);
//  print(start);
removeDupliMaps(start);
print(start);
return 0;
}