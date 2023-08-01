#include<iostream>
using namespace std;


int main(){
int n,m;
//Graph is stored here..in O(n)
cout<<"Enter the vertices and edges of the graph:\n";
cin>>n>>m; 
int adj[n+1][m+1];  //2d array / matrix.
for(int i=0;i<m;i++) {
    int u,v;
    cout<<"Enter the vertice and edge to be connected :\n ";
    cin>>u>>v;
    adj[u][v]=1; //connection is showm by one
    adj[v][u]=1;
}
return 0;
}