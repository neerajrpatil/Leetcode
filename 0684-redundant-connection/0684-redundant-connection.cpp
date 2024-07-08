class Solution {
public:
    int dfs(int u,int target,vector<vector<int>>& g,vector<int>& vis){
        if(u==target)return 1;
        vis[u]=1;
        bool chk=false;
        for(int v:g[u]){
            if(vis[v]==0){
               chk= dfs(v,target,g,vis);
               if(chk)break;
            }
        }
        return chk;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>g(n);
        for(auto it:edges){
            int u=it[0]-1,v=it[1]-1;
            vector<int>vis(n,0);
            if(dfs(u,v,g,vis))return {u+1,v+1};
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return {-1,-1};


    }
};