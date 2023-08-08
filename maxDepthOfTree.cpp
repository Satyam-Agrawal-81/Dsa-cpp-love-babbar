#include<bits/stdc++.h>
using namespace std;
// int main(){
 
// return 0;
// }
class TreeNode {

    
public:
TreeNode*left=NULL;
TreeNode* right=NULL;
    int maxDepth(TreeNode* root) {
  if(root==NULL)
  return 0;

  int left=maxDepth(root->left);
  int right=maxDepth(root->right);

  int ans=max(left,right)+1;
  return ans;      
    }
};