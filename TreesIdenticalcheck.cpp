
#include<bits/stdc++.h>
using namespace std;
int main(){
 
return 0;
}
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
          //base case
          if(r1==NULL && r2==NULL){
              return true;
          }
          if(r1==NULL || r2==NULL){
              return false;
          }
          
          bool left=isIdentical(r1->left,r2->left);
          bool right=isIdentical(r1->right,r2->right);
          
          bool value =  r1->data == r2->data;
          
          if(left && right && value)
          return true;
          
          return false;
    }
};