
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


// MERGE   SORT     O(nlogn)
// class Solution {
    class ListNode{
        public:
        int val;
        ListNode* next;

        ListNode(){
            val=0;
            next=nullptr;
        }
        ListNode(int x){
            val=x;
            next=nullptr;
        }
        ListNode(int x,ListNode* nextnode){
            val=x;
            next=nextnode;
        }
    };
// public:

   ListNode* getMid(ListNode*&head){
      ListNode* slow=head;
      ListNode*fast=head->next;

      while(fast!=nullptr && fast->next!=nullptr){
          slow=slow->next;
          fast=fast->next->next;
      }
      return slow;
   }
//    merge two sorted linked list:
   ListNode* merge(ListNode*&left,ListNode*&right){
       if(left==nullptr)
       return right;
       if(right==nullptr)
       return left;
       ListNode* ans= new ListNode(-1); //dummy node
       ListNode* temp=ans;

       while(left!=nullptr && right!=nullptr){
           if(left->val<right->val){
               temp->next=left;
               temp=left;
               left=left->next;
           }
           else{
                temp->next=right;
                temp=right;
                right=right->next;
           }
       }

       while(left!=nullptr){
           temp->next=left;
           temp=left;
           left=left->next;
       }
       while(right!=nullptr){
           temp->next=right;
           temp=right;
           right=right->next;
       }
  ans=ans->next;
  return ans;
   }
    ListNode* sortList(ListNode* head) { //function for merge sort
    // ListNode* mergeSort(ListNode* head) { 
        if(head==nullptr || head->next==nullptr)
        return head;
//    break linklist into two halves
        ListNode *mid=getMid(head);

        ListNode *left=head;
        ListNode* right=mid->next;
        mid->next=nullptr;
// recursive calls to sort both halves
        left=sortList(left);
        right=sortList(right);

        // merge both left and right halves
        ListNode* result=merge(left,right);

        return result;

    }
// };