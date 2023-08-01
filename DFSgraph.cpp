#include<iostream>
#include<stack>
#include<vector>
using namespace std;


// Depth First Search Traversal Algo :Recursion will be the algo used for DFS , we can do it with  Stack Data Structure..
class Solution{

    private:
    void dfsFunc(int node,vector<int> adj[],int vis[],vector<int> &dfs){
    vis[node]=1;
    dfs.push_back(node);
    //traverse all its nodes
    for(auto it: adj[node]){
        if(!vis[it]){
            dfsFunc(it,adj,vis,dfs);
        }
    }
    }
public:

vector<int> dfsGraph(int n, vector<int>adj[]){
      int vis[n]={0};
      int start=0;
      vector<int>dfs;
      dfsFunc(start,adj,vis,dfs);
   return dfs;
}
}; //space complexity = O(n)


int main(){
 int n,m;
 Solution obj;
//Graph is stored here..
cout<<"Enter the vertices and edges of the graph:\n";
cin>>n>>m; 
vector<int>adj[n+1];  //adj list
for(int i=0;i<m;i++) {
    int u,v;
    cout<<"Enter the vertice and edge to be connected :\n ";
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> ans=obj.dfsGraph(n,adj);
for(auto i: ans){
    cout<<ans[i]<<" ";
}
return 0;
}