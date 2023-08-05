#include<iostream>
#include<stack>
using namespace std;

int main(){
 string str="satyam";
 stack<char>s;
 for(int i=0;i<str.length();i++){
    char ch =str[i];
    s.push(ch);
 }
 string ans="";
 while(!s.empty()){
    char ch=s.top();
    ans.push_back(ch); //string also have push_back function..

    s.pop();
 }
// if using two pointers start and end to swap them to reverse string till start<=end then TC is O(n) and SC is O(1)..
// but we have used stack for reversing so TC and SC both are O(n)
cout<<"Answer is reversed string : "<<ans<<endl;

return 0;
}