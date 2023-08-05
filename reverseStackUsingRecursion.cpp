#include<bits/stdc++.h>
using namespace std;


void InsertAtBottom(stack<int>&s,int ele){
    //base case
    if(s.empty()){
        s.push(ele);
        return;
    }
    int num=s.top();
    s.pop();

    //recursive call
    InsertAtBottom( s, ele);

    s.push(num);

}

void reverseStack(stack<int> &s) {
    // Write your code here
     //base case
     if(s.empty()){
         return;

     }

     int num=s.top();
     s.pop();

     //recusion
     reverseStack(s);

     InsertAtBottom( s,num);
}