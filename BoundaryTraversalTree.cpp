#include<bits/stdc++.h>
using namespace std;
int main(){
 
return 0;
}



class Node {

public:
 int data;
 
 Node*left=NULL;
 Node*right=NULL;


    void traversalLeft(Node *root,vector<int>&ans){
        if(root==NULL)
        return ;
        
        if(root->left==NULL && root->right==NULL)
        return ;
        
        ans.push_back(root->data);
        
        if(root->left)
        traversalLeft(root->left,ans);
        
        else
        traversalLeft(root->right,ans);
    }

    void traversalLeaf(Node * root, vector<int>&ans){
        if(root==NULL)
        return ;
        
        if(root->left==NULL && root->right==NULL)
        ans.push_back(root->data);
        
        
        traversalLeaf(root->left,ans);
        traversalLeaf(root->right,ans);
        
        
    }


    void traversalRight(Node*root, vector<int>&ans){
        if(root==NULL)
        return ;
        if(root->left==NULL && root->right==NULL)
        return ;
        
        if(root->right)
        traversalRight(root->right,ans);
        else
        traversalRight(root->left,ans);
        
        //wapas aa gye 
        ans.push_back(root->data);
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL)
        return ans;
        
        ans.push_back(root->data);
        //left part print/store
        traversalLeft(root->left,ans);
        
        //leaf node traversal
        // left part
        traversalLeaf(root->left,ans);
        //right part
        traversalLeaf(root->right,ans);
        
        //right part print/store
        traversalRight(root->right,ans);
    
        
        return ans;
    }
};