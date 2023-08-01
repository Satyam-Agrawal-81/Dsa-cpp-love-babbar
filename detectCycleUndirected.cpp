#include<bits/stdc++.h>
using namespace std;
//undirected graph

class Solution {
    
  private:
  
  bool detect(int src,vector<int>adj[], int vis[]){
  vis[src]=1; //sorce vertex is visisted
  queue<pair<int,int>>q;
  q.push({src,-1});
  while(!q.empty()){
      int node=q.front().first;
      int parent=q.front().second;
      q.pop();
      
      for(auto adjNode : adj[node] ){
          if(!vis[adjNode]){
              vis[adjNode]=1;
              q.push({adjNode,node});
          }
          else if(parent !=adjNode){
              //it is a cycle  someone has touched it 
              return true;
          }
      }
  }
      
      return false;
  }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){   //will check all of the connected coponents ..
            if(!vis[i]){
                if(detect(i,adj,vis))
                return true;
            }
        }
      return false;
    }
};

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

    Solution obj;
    return 0;
}