#include<bits/stdc++.h>
using namespace std;
int main(){
 
return 0;
}

class Node{
    public:

        Node*left=NULL;
        Node*right=NULL;
      

   
    pair<bool,int> isBalancedFast(Node *root){
      //base case
      if(root==NULL)
      {
          pair<bool,int>p=make_pair(true,0);
          return p;
      }
      
      pair<bool, int>left= isBalancedFast(root->left);
      pair<bool,int>right=isBalancedFast(root->right);
      
      bool leftAns=left.first;
      bool rightAns=right.first;
      
      //for tree to be balanced the height of left sub tree and right should be <=1
      
      bool diff = abs(left.second - right.second) <=1;
      
      pair<bool,int>ans;
      ans.second=max(left.second, right.second)+1; //for height of tree
      
      if(leftAns && rightAns && diff){
          ans.first=true;
      }
      else{
          ans.first=false;
      }
      return ans;
    }
    
  
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return isBalancedFast(root).first;
    }
};