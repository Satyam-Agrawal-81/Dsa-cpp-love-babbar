// Binary Search Tree
#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;

    //constructor
    node(int data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
    }
};


node* buildBST(node*&root,int data){
//insertToBST  O(logn) insertion
//base case
if(root==NULL){
    root=new node(data);
    return root;
}
if(data > root->data) //means right part me insert karna he 
root->right=buildBST( root->right , data);

if(data < root->data)  // this is the else case or say we have given if condition for left part so run accordingly to else only...
root->left=buildBST( root->left , data);
    
    
    return root;
}
void levelOrderTraversal(node *&root){
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

void PreSuc(node * root, node*&pre,node*&suc,int key){
//base case
if(root==NULL) return ;

    // If key is present at root
    if (root->data== key)


// the maximum value in left subtree is predecessor
if(root->left!=NULL){
    node * temp=root->left;

    while(temp->right)
    temp=temp->right;

    pre=temp;
}
//  the minimum value in right subtree is successor
  if(root->right!=NULL){
    node *temp=root->right;
    while(temp->left)
    temp=temp->left;

    suc=temp;
  }
  return;

    // If key is smaller than root's data, go to left subtree
    if (root->data > key)
    {
        suc = root ;
        PreSuc(root->left, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
        PreSuc(root->right, pre, suc, key) ;
    }
}

node* minValueBST(node*root){
node*temp=root;
while(temp->left!=NULL){
    temp=temp->left;
}
return temp;
}

node* maxValueBST(node *root){
node*temp=root;
while(temp->right!=NULL){
    temp=temp->right;
}
return temp;
}

node * DeletionBST(node * root,int val){
//base case
if(root==NULL)
return root;

if(root->data==val){
    //0 child
    if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }

    //1 child
     //left->child
     if(root->left!=NULL && root->right==NULL){
        node*temp=root->left;
        delete root;
        return temp;
     }

     //right child
     if(root->left==NULL && root->right!=NULL){
        node*temp=root->right;
        delete root;
        return temp;
     }

     //2 child
     if(root->left !=NULL && root->right!=NULL){
        int mini= minValueBST(root->right)->data;
        root->data=mini;
        root->right=DeletionBST(root->right,mini);
        return root;
     }
}
else if(root->data>val){
    //left part me jao
    root->left=DeletionBST(root->left,val);
    return root;
}
else{
    //right part me jao
    root->right=DeletionBST(root->right,val);
    return root;
}
}

void takeInput(node*  &root){
    int data;
    cin>>data;

    while(data!=-1){
        buildBST(root,data);
        cin>>data;
    }
}


void inorder(node *root){
    //base case
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node *root){
    //base case
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    
    preorder(root->right);
}
void postorder(node *root){
    //base case
    if(root==NULL)
    return;
    postorder(root->left);
    
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
 
node*root=NULL;

cout<<"Enter the data values ot create BST:\n";
takeInput(root);
cout<<"The level order traversal of the BST:\n";
levelOrderTraversal(root);

 cout<<"Inorder traversal: Left Root Right\n";
 inorder(root);
 cout<<endl;
cout<<"Preorder traversal: Root Left Right\n";
preorder(root);
cout<<endl;
cout<<"Postorder traversal: Left Right Root\n";
postorder(root);
cout<<endl;
// cout<<"Min value of BST: "<<minValueBST(root)<<endl;
// cout<<"Max value of BST: "<<maxValueBST(root)<<endl;
return 0;
}