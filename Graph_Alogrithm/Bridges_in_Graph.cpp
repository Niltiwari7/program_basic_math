class Solution {
public:
     vector<int>tin;
     vector<int>low;
     int timer  = 1;
     vector<vector<int>>ans;
     void dfs(int node,int parent,vector<int>&vis,vector<int>adj[]){
        vis[node] = 1;
        tin[node]=low[node]=timer++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            if(vis[it]==0){
              dfs(it,node,vis,adj);
              low[node] = min(low[node],low[it]);
              //node----it
              if(low[it]>tin[node]){
                 ans.push_back({it,node});
              }  
            }else{
                low[node] = min(low[node],low[it]);
            }
        }
     }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        tin.resize(n,0);
        low.resize(n,0);
        dfs(0,-1,vis,adj);
        return ans;
    }
};