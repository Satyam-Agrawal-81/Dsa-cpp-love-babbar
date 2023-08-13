#include<bits/stdc++.h>
using namespace std;


class MyQueue {
public:
stack<int>s1,s2;
    MyQueue() {
        
    }
    
  void push(int x) {
       s1.push(x);
    }
    
    int pop() {  //dequeeu is order of n
        if(s2.empty()){
              while(!s1.empty()){
                  s2.push(s1.top());
                  s1.pop();
              }
        }
              int ans=s2.top();
              s2.pop();
              return ans;
        }
    
    
    int peek() {
              if(s2.empty()){
              while(!s1.empty()){
                  s2.push(s1.top());
                  s1.pop();
              }
              }
              int ans=s2.top();
            //   s2.pop();
              return ans;
        }
    

    bool empty() {
        if(s2.empty()&& s1.empty())
        return true;
        else
        return false;
    }
};

int main(){
 
return 0;
}