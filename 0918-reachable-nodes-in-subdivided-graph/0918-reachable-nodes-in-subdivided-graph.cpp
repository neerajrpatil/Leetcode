class Solution {
public:
    #define pii pair<int,int>
    #define fi first
    #define se second
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        unordered_map<int,unordered_map<int,int>>val;
        vector<pii> g[n];
        for(auto it:edges){
            int u=it[0],v=it[1],d=it[2];
            g[u].push_back({v,d});
            g[v].push_back({u,d});
        }

        priority_queue<pii,vector<pii>,greater<pii>>pq;

        pq.push({0,0});
        vector<int>dis(n,1e9);
        dis[0]=0;
        int ans=0;
        while(!pq.empty()){
            auto node=pq.top();pq.pop();
            int u=node.se;
            int d=node.fi;
            if(d>dis[u])continue;
            ans++;
            for(auto [v,d2]:g[u]){

                val[u][v]=min(maxMoves-d,d2);

                if(d+d2+1<dis[v] && d+d2+1<=maxMoves){
                    dis[v]=d+d2+1;
                    pq.push({dis[v],v});
                }
            }
        }
        for(auto it:edges){
            int u=it[0],v=it[1],d=it[2];
            ans+=min(d,val[u][v]+val[v][u]);
        }
        return ans;
    }
};