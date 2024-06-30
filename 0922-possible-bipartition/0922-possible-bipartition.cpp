class Solution {
public:
//chk if a graph is bipartite
    bool dfs(int u,int color,vector<int>& vis,vector<int> adj[]){
        vis[u]=color;
        bool chk=true;
        for(int v:adj[u]){
//defination : if a node and its neigh have same color then conflict
//no need to visit that neigh
            if(vis[v]==0){
                bool chk=dfs(v,(color==1)?2:1,vis,adj);
                if(!chk)return chk;
            }
            else if(vis[v]==color)return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>vis(n+1,0);
        vector<int>adj[n+1];
        for(auto it:dislikes){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool chk=true;
        for(int node=1;node<=n;node++){
            if(vis[node]==0){
                chk=dfs(node,1,vis,adj);
                if(!chk)return chk;
            }
        }
        return chk;
    }
};