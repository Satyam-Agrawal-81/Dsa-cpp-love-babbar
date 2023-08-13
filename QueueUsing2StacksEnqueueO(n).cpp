#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;
public:
//enqueue operation order of n .... we have also done for dequeue operation order of n in leetcode ques

    void enqueue(int x) {
        
        //move all elements from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
           s1.pop();
            
        }
        
        //push item into s1
        s1.push(x);
        
        //push everything back to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue() {
         
        //if fist stack is empty
        if(s1.empty()){
            return -1;
        }
        
        int ans=s1.top();
        s1.pop();
        return ans;
        
    }
//LEETCODE enqueue order of n 
   
    // void push(int x) {
    //     while(!s1.empty()){
    //          s2.push(s1.top());
    //          s1.pop();
    //     }

    //     s1.push(x);

    //     while(!s2.empty()){
    //         s1.push(s2.top());
    //         s2.pop();
    //     }
    // }
    
    // int pop() {  //dequeeu is order of n
    //     if(s1.empty()){
    //           return -1;
    //     }

    //     int ans=s1.top();
    //     s1.pop();
    //     return ans;
    // }
    
    // int peek() {
    //     if(s1.empty()){
    //         return -1;
    //     }
    //     return s1.top();
    // }
    
    // bool empty() {
    //     if(s1.empty())
    //     return true;
    //     else
    //     return false;
    // }

};
int main(){
 
return 0;
}