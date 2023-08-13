//LEETCODE

#include<bits/stdc++.h>
using namespace std;



class TreeNode {

public:
        TreeNode* left=NULL;
        TreeNode* right=NULL;


    int heightHelper(TreeNode* root){
        if(root==NULL)
        return 0;

        int left = heightHelper(root->left);
        int right = heightHelper(root->right);

        if(left == -1 || right == -1)
        return -1;

        if(abs(left-right) > 1)
        return -1;

        return max(left, right)+1;
    }


    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;

        if(heightHelper(root)==-1)
        return false;

        return true;
    }
};

int main(){
 
return 0;
}