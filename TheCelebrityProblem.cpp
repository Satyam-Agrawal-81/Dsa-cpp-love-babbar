#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    
    bool knows(vector<vector<int>> & M, int a,int b){
        
            if(M[a][b]==1)
            return true;
            else return false;
        }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int>s;
        //push all elements in the stack // elements/persons are defined as n in number
        // starting from 0th person so we take 0 to n-1
        for(int i=0;i<n;i++){
            s.push(i);
        }
        
        //step2  get two elements to compare anyone  knows each other or not
        while(s.size()>1){
            int a = s.top();
            s.pop();
            
            int b=s.top();
            s.pop();
            
            if(knows(M,a,b)) //knows(a,b) checks if a knows b then a  cant be celebrity so push b;
            s.push(b);
            else 
            s.push(a);
        }
        
        int candidate=s.top();
        //step3 : single element remaining in stack can be potential celebrity .. 
        //so check for celebrity that element full row is 0 and full coloumn is 1 except the diagonal part of col.
        bool rowCheck=false;
        int zeroCount=0;
        for(int i=0;i<n;i++){
            if(M[candidate][i]==0)
            zeroCount++;
        }
        //if all zeroes then rowCheck is true 
        if(zeroCount==n)
        rowCheck=true;
        
        bool colCheck=false;
        int oneCount=0;
        
        for(int i=0;i<n;i++){
            if(M[i][candidate]==1)
            oneCount++;
        }
        
        //if all 1 except the diagonal wala element as candidate to candidate should not be one
        // in order to be celebrity. So,
        if(oneCount==n-1)
        colCheck=true;
        
        if(rowCheck && colCheck)
        return candidate;
        
        //else
        return -1;
        
    }
};

// int main(){
    // return 0;
// }