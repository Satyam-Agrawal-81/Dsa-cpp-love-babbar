#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
    stack<int>st;
    int cnt=0;
    for(auto it:s){
        if(it=='(')
          st.push(it);
        else if(it==')'){
            if(!st.empty()){
                st.pop();
            }
            else
               cnt++;
        }
    }
    
    return cnt+st.size();

    }
};