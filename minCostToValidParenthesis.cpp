#include <bits/stdc++.h> 
using namespace std;

int findMinimumCost(string str) {
  // Write your code here

   int len=str.length();
   
   if(len%2!=0) //that is odd length
   return -1;

   //else
   stack<char>s;

   for(int i=0;i<len;i++){
     char ch=str[i];

     if(ch=='{')
     s.push(ch);

     else{
       //ch is closed bracket
       if(  !s.empty() && s.top()=='{'){
         s.pop(); //ie removed valid bracket open one to remove whole valid pair
       }
       else{
           s.push(ch);
       }
     }
   }


   //stack contains invalid expression

     int a=0,b=0;
     while(!s.empty()){
       if(s.top()=='{')
       b++;
       else
       a++;

       s.pop();
     }

     int ans=(a+1)/2 + (b+1)/2;
   return ans;


}