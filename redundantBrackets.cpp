#include <bits/stdc++.h> 
using namespace std;
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char>st;
    for(int i=0;i<s.length();i++){
    char ch=s[i];
       if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
           st.push(ch);
       }
       else{
           //either ch is ) or any lowecase alphabet..
           if(ch==')'){
               bool isRedundant=true;
               while(st.top() !='('){
                   char top=st.top();
                    if( top=='+' || top=='-' || top=='*' || top=='/')
                            isRedundant=false;
                    st.pop();
               }
               if(isRedundant)
               return true;
               st.pop();
           }
       }

    }
    return false;
}
