#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node{
    public:
    int data;
    node*left=NULL;
    node*right=NULL;
//constructor
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1)
    return NULL;

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root){
queue<node*>q;
q.push(root);
q.push(NULL);

while(!q.empty()){

    node *temp=q.front();
    q.pop();
     if(temp==NULL){ //q.front=null tht is purana level is completed
        cout<<endl;
     if(!q.empty()){ // if q still has some child nodes..so agle level k liye cout<<endl; k liye q me NULL daldiya jo temp me dikhega next step me..
        q.push(NULL);
     }
     }
     else{
        cout<<temp->data<<" ";
    if(temp->left){
        q.push(temp->left);
    }
    if(temp->right)
    q.push(temp->right);
     }
}
}
void inorder(node *root){  // left root right
    //base case
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(node * root){  //root left right
  //base case
  if(root==NULL){
  return ;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
  
}

void postorder(node *root){  //left right root
    //base case
    if(root==NULL)
    return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}

void preorderIteration(node *root){
    if(root==NULL)
    return;
    //create an ampty stack and push the root node
    stack<node*>st;
    st.push(root);

    //loop still stack is empty
    while(!st.empty()){
        node* curr=st.top();
          st.pop();

          cout<<curr->data<<" ";

          //push the right child of the popped node into the stack
          if(curr->right)
          st.push(curr->right);

          if(curr->left)
          st.push(curr->left);

        //   the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}

void inorderIteration(node *root){
    if(root==NULL)
    return;
    //create an ampty stack and push the root node
    stack<node*>st;
  node* curr=root;

  while(curr!=NULL || st.empty()==false){
      // Reach the left most Node of the
        // curr Node
    while(curr!=NULL){
   // Place pointer to a tree node on
            // the stack before traversing
            // the node's left subtree
            st.push(curr);
            curr=curr->left;
  
    }
    //Current must be NULL at this point
    curr=st.top();
    st.pop();

    cout<<curr->data<<" ";

    // we have visited the node and its
        // left subtree.  Now, it's right
        // subtree's turn
        curr=curr->right;

  } 
}

void postorderIteration(node *root){
    if(root==NULL)
    return ;

    stack<node*>st;
    st.push(root);

    // create another stack to store postorder traversal
    stack<int> out;

    //loop till stack is empty
    while(!st.empty()){
         // pop a node from the stack and push the data into the output stack
        node* curr = st.top();
        st.pop();

        out.push(curr->data);
         // push the left and right child of the popped node into the stack
        if (curr->left) {
            st.push(curr->left);
        }
 
        if (curr->right) {
            st.push(curr->right);
        }
    }
//print postorder traversal
while(!out.empty()){
cout<<out.top()<<" ";
out.pop();
}

}

node *buildFromLevelOrderTraversal(node *&root){  //agar return nhi kara rahe ho function me so jo root node daloge argument me vo as a reference lelo isliye & use kara..

queue<node*>q;
cout<<"Enter data for the root: ";
int data;
cin>>data;
root=new node(data);
q.push(root);

while(!q.empty()){
    node*temp=q.front();
    q.pop();

    cout<<"Enter left node for "<<temp->data<<endl;
    int leftData;
    cin>>leftData;

    if(leftData!=-1){
        temp->left=new node(leftData);
        q.push(temp->left);
    }

     cout<<"Enter right node for "<<temp->data<<endl;
    int rightData;
    cin>>rightData;

    if(rightData!=-1){
        temp->right=new node(rightData);
        q.push(temp->right);
    }

}
}

int main(){
 node *root=NULL;

 //creating a tree
//  root=buildTree(root);

 //1 3 7 -1 -1 6 -1 -1 5 9 -1 -1 -1

buildFromLevelOrderTraversal(root);

 cout<<"Printing the level order traversal:\n";
 levelOrderTraversal(root); 

// for buildFromLevelOrderTraversal:
// 1 3 5 7 6 9 -1 -1 -1 -1 -1 -1 -1

//  cout<<"Inorder traversal: Left Root Right\n";
//  inorder(root);
//  cout<<endl;
// cout<<"Preorder traversal: Root Left Right\n";
// preorder(root);
// cout<<endl;
// cout<<"Postorder traversal: Left Right Root\n";
// postorder(root);
// cout<<endl;

cout<<"Builded tree from level order traversal given and traversal matched successfully..\n";
cout<<"Iterative preorder:\n";
preorderIteration(root);
cout<<"\nIterative Inorder:\n";
inorderIteration(root);
cout<<"\nIterative Postorder:\n";
postorderIteration(root);
return 0;
}