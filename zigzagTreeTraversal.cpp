#include<bits/stdc++.h>
using namespace std;
int main(){
 
return 0;
}
// /User function Template for C++
// Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>res;
    	
    	if(root==NULL)
    	return res;
    	
    	queue<Node*>q;
    	q.push(root);
    	
    	bool leftToRight=true;
    	
    	while(!q.empty()){
    	    int n=q.size();
    	    vector<int>ans(n); //temporary vector answer
    	    //level process
    	    for(int i=0;i<n;i++){
    	        Node *temp=q.front();
    	        q.pop();
    	    
    	    
    	   int index= leftToRight ? i : n-i-1;
    	   //agar left to right nahi he to fhir right to left push karenge so n-i-1
    	   ans[index]=temp->data;
    	   
    	   if(temp->left)
    	   q.push(temp->left);
    	   
    	   if(temp->right)
    	   q.push(temp->right);
    	   
    	   
    	}
    	
    	//direction change
    	leftToRight=!leftToRight;
    	
    	
    	for(auto i : ans)
    	{
    	    res.push_back(i);
    	}
    	}
    	return res;
    }
};
