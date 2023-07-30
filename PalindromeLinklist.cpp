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



bool checkPalin(vector<int>&arr){

    int len=arr.size();
    int s=0;
    int e=len-1;

    while(s<=e){
        if(arr[s]!=arr[e])
        return false;
        s++;
        e--;
       
    }
     return true;
}



bool convertToArray(Node * &head ){
    int len=length(head);
vector<int>arr;
Node *temp=head;
while(temp!=NULL){
    arr.push_back(temp->data);
    temp=temp->next;
}
return checkPalin(arr);
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

    bool ans = convertToArray(start);

   if(ans==true)
   cout<<"LinkedList is palindrome"<<endl;
   else
   cout<<"No!! LinkedList is not a palindrome!!\n";

    return 0;
}