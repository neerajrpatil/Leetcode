class Solution {
public:
    map<int,int>vis;
    void dfs(int u,int &cnt,vector<vector<pair<int,int>>> &adj){
        vis[u]=1;
        for(auto it: adj[u]){
            int v=it.first,dir=it.second;
            if(vis[v]!=0)continue;
            if(dir)cnt++;
            dfs(v,cnt,adj);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        int cnt=0;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:connections){
            adj[it[0]].push_back({it[1],0});
            adj[it[1]].push_back({it[0],1});
        }
        dfs(0,cnt,adj);
        return (n-1)-cnt;
    }
};