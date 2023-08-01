#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size(); //size of column
        // {r,c},t  => pair<int , int >, int to store row column and time for rotten  given already
        queue<pair<pair<int,int>,int>>q;
        int cntfresh=0;
        int vis[n][m]; // visited array
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0}); // 0 unit time for already given rotten 
                    vis[i][j]=2; //assigning 2 will signify rotten orange at that posiition
                } 
                else vis[i][j]=0; // to initialize visited matrix if not assigned with rotten value 2
            
                
                if(grid[i][j]==1)  cntfresh++;
            }
        }
                int tm=0;
                 int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1}; // for getting neighbours
                int cnt=0; //to compare with fresh oranges count
                // bfs code
                while(!q.empty()){
                    int r=q.front().first.first;
                    int c =q.front().first.second;
                    int t=q.front().second;
                    tm=max(tm,t);
                    q.pop();
                    for(int i=0;i<4;i++){
                        int nrow = r+ drow[i]; //neighbouring row
                        int ncol = c+dcol[i]; //neighbouring column
                        //check if neighbouring rows and cols we get are valid or out of mtrix.
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                            // now checking doing operation only if these neighbours are not rotten(2) and are fresh(1)
                            if(vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                                q.push({{nrow,ncol},t+1});
                                vis[nrow][ncol]=2;
                                cnt++;
                            }
                        }
                    }
                }
                   
                   if(cnt!=cntfresh)
                   return -1;
                
               return tm;
        
    }
};

int main(){
  int n,m;
  cin>>n>>m;
  vector<vector<int>>grid(n,vector<int>(m,-1));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
    }
  }  
  Solution obj;
  int ans=obj.orangesRotting(grid);
  cout<<ans<<endl;

return 0;
}