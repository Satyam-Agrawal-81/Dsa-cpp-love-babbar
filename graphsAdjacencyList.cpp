#include<iostream>
#include<vector>
using namespace std;


int main(){
int n,m; // vertices and edges
//Graph is stored here..
cout<<"Enter the vertices and edges of the graph:\n";
cin>>n>>m; 
vector<int>adj[n+1]; //adjacency list 
for(int i=0;i<m;i++) {
    int u,v;
    cout<<"Enter the vertice and edge to be connected :\n ";
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u); 
}
    //space complexity is much lesser now O(2E)


    //case of directed graph :
    // O(E)
// for(int i=0;i<m;i++) {
//     int u,v;
//     cout<<"Enter the vertice and edge to be connected :\n ";
//     cin>>u>>v;
//     adj[u].push_back(v);
//     // adj[v].push_back(u); this line is not given since directed have arrows so not reverse traversing we have to give u and v as per directio of edge to the vertice  
// }

return 0;
}