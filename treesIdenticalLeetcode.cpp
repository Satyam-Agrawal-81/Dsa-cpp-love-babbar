#include<bits/stdc++.h>
using namespace std;
int main(){
 
return 0;
}
//  * Definition for a binary tree node.
 struct TreeNode {
 int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

vector<int> levelOrder(TreeNode* &root){
vector<int>ans;
vector<int>faltu;
TreeNode* exit;
queue<TreeNode*>q;
if(root==nullptr){
    q.push(exit);
}
q.push(root);
while(!q.empty()){
    if(q.front()==exit)
    return faltu;
    TreeNode* temp=q.front();
    q.pop();
    ans.push_back(temp->val);
    if(temp->left)
    q.push(temp->left);
    if(temp->right)
    q.push(temp->right);
}
return ans;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p==NULL && q==NULL)
       return true; //if both empty then identical
       
       //the below condition is after the above condition so it is checking just one of the nodes is NULL out of p and q
       if(p==NULL || q==NULL)
       return false; 

//        if(p->val==q->val){
//            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
//        }
 
//  return false; //if values not equal it will come here

vector<int> ansp=levelOrder(p);
vector<int> ansq=levelOrder(q);
if(ansp==ansq)
return true;
else
return false;
    }
};