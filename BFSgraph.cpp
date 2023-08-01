#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Breadth First Search Traversal Algo : based on Queue Data Structure..

// Question Link (GFG): https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution{
    public:
 vector <int> bfsGraph(int n, vector< int >adj[]){
     int vis[n]={0}; // visited array of n size and initially elements marked to zero 
     vis[0]=1;
     queue<int >q;
     q.push(0); //starting index
     vector<int>bfs;
     while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        // adjacency list is storing the neighbour nodes so we can add them too in our visited array and then in queue..
        for(auto it: adj[node]){  //Iterating the elements: the index node will be affected by this and its neighbours are stored in this index in list so we can traverse.. adj list k node wale index par jo jo honge sab ko traverse karegi and visted nahi hue to vis array me uski jagah 1 kar denge...
        if(!vis[it]){
             vis[it]=1;
             q.push(it);
        }

        }
     }
     return bfs;
 }  // space complexity : a queue , a visisted node and a adj list so O(3n) => O(n)
 //time complexity : node goes once into the bfs and runs on all its degrees ..thus for loop runs for all ndes then queue->O(n) + O(2E) for every node 


};

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
vector<int> ans= obj.bfsGraph(n,adj);
for(auto i: ans){
    cout<<ans[i]<<" ";
}
return 0;
}