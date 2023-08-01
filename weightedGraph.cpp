#include<iostream>
using namespace std;


int main(){
int n,m;
//Graph is stored here..in O(n)
cout<<"Enter the vertices and edges of the graph:\n";
cin>>n>>m; 
int adj[n+1][m+1];  //2d array / matrix. weighted graph k liye 
for(int i=0;i<m;i++) {
    int u,v;
    cout<<"Enter the vertice and edge to be connected :\n ";
    cin>>u>>v;
    int wt;
    cout<<"Enter the weight of the graph edge: ";
    cin>>wt;

    adj[u][v]=wt; //weighted graph
    adj[v][u]=wt;
}
return 0;
}