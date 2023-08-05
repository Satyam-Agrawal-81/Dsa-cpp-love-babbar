#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>arr, int n){
vector<int>ans(n);
    stack<int>s;
    s.push(-1);

    for(int i=n-1;i>=0;i--){
        while(s.top()>=arr[i]){
            s.pop();
        }
        //now ans is stack ka top
        ans[i]=s.top(); //since ulta loop therfore
        //  n-1 se 0 index par hi store hoga vector ans me ...
        s.push(arr[i]);
    }
return ans;
}