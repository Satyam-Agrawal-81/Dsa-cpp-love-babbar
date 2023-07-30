#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
}*start=NULL;

Node * create(Node * &head){
    char ch;
    do{

    Node * newnode=(Node*)malloc(sizeof(Node));
     Node* current;
    cout<<"Enter the value of newnode: ";
    cin>>newnode->data;
    if(head==NULL){
      head=newnode;
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
return head;
}

Node *print(Node *&head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
   cout<<"NULL"<<endl;
}

Node * sortList(Node * &head){
    if(head==NULL)
    return NULL;
    Node *temp=head->next;
    Node *curr=head;
    // while(curr!=NULL){
    while(temp!=NULL){
        if(temp->data<curr->data)

        {    
            // If temp is smaller than curr, 
        // then it must be moved to head

        // Detach temp from linked list
          curr->next=temp->next;
          
            // Move temp node to beginning
          temp->next=curr;
          temp=curr->next;
          
          // Update temp
        //   temp=curr;

           // Nothing to do if temp 
        // element is at right place   
           
        }
       else {
        // curr=temp;
         temp=temp->next;
       }
      


    //    temp=temp->next;
        }
        // curr=curr->next;
    // }
  return head;
    }
   




int main(){

    create(start);
    print(start);
   sortList(start);
   print(start);
    return 0;
}