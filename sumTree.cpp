#include<bits/stdc++.h>
using namespace std;
int main(){
 
return 0;
}
//Tree Node
struct Node
{
    int data;
    Node* left, * right;
};

// Should return true if tree is Sum Tree, else false
class Solution
{
    public:
    
    pair<bool,int>isSumTreeFast(Node * root){
        if(root==NULL)
        {
            pair<bool,int>p= make_pair(true,0); //int sum is 0 as no node but true for null
            return p;
        }
        
        if(root->left==NULL && root->right==NULL){
            pair<bool,int>p = make_pair(true,root->data);
            return p;
        }
        pair<bool,int>leftAns= isSumTreeFast(root->left);
        pair<bool,int>rightAns= isSumTreeFast(root->right);
        
        bool isleftSumTree=leftAns.first;
        bool isrightSumTree=rightAns.first;
        
        int leftSum=leftAns.second;
        int rightSum=rightAns.second;
        
        bool checkSum = root->data == leftSum + rightSum;
        
        
        pair<bool,int>ans;
        if(isleftSumTree && isrightSumTree && checkSum){
            ans.first=true;
        //   ans.second=root->data + leftAns.second + rightAns.second;
        ans.second= 2* root->data;
        }
        else{
            ans.first=false;
        }
        
        
        return ans;
        
    }    
    
    
    bool isSumTree(Node* root)
    {
         // Your code here
         //base case
        //  if(root==NULL)
        //  return NULL;
         
        //  left=isSumTree(root->left);
        //  right=isSumTree(root->right);
        return isSumTreeFast(root).first;
    }
};