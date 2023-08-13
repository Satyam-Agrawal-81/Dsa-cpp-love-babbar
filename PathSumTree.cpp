#include<bits/stdc++.h>
using namespace std;
int main(){
 
return 0;
}
//   Definition for a binary tree node.
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
   bool rootToLeafPathSum(TreeNode* root, int targetSum, int currSum){
     
     if(root==NULL)
     return false;

     if(root->left == NULL && root->right==NULL ){
         currSum=currSum + root->val;
         if(currSum==targetSum)
         return true;
     }

     return rootToLeafPathSum(root->left, targetSum, currSum+root->val)|| rootToLeafPathSum(root->right, targetSum, currSum+root->val);
   }



    bool hasPathSum(TreeNode* root, int targetSum) {
        //base case
        // if(root==NULL)
        // return false;
        int currSum=0;
        
      return rootToLeafPathSum(root,targetSum,currSum);;

    }
};