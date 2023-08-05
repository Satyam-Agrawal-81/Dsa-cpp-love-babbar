#include<bits/stdc++.h>
using namespace std;
// int main(){
 
// return 0;
// }
class Solution {

    // void insertElement(stack<int>&s,vector<int>&temp,vector<string>&str,vector<int>&target,int n){
    //      for(int i=1;i<=n;i++){
    //          if(temp==target){
    //          str.push_back("Push");
    //          return;
    //          }
    //          s.push(i);
    //          temp.push_back(i);
    //         //  if(target[i-1]==temp[i-1]){
    //         //      str.push_back("Push");
                 
    //         //  }
    //          if(target[i-1]!=temp[i-1] && !s.empty()){
    //              s.pop();
    //              temp.pop_back();
    //              str.push_back("Pop");
    //          }
    //          else{
    //              if(i+1==target.size()){
    //                  str.push_back("Push");
    //                  break;
    //              }
    //              str.push_back("Push");
    //          }
             
    //      }
    // }
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // stack<int>s;
        vector<string>str;
        // vector<int>temp(n);
            //  insertElement(s,temp,str,target,n);
        int j=0;
        for(int i=1;i<=n;i++){
            if(target[j]==i){
                str.push_back("Push");
                 j++;
                if(j==target.size())
                break;
            }
            else{
                str.push_back("Push");
                str.push_back("Pop");
            }
        }

        return str;
    }
};