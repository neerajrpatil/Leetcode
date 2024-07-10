/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    map<int,int>imp;
    void dfs(int u,int &res, map<int,int>& vis, map<int,vector<int>>& adj){
        vis[u]=1;
        res+=imp[u];

        for(int v:adj[u]){
            if(!vis[v]){
                dfs(v,res,vis,adj);
            }
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        
        map<int,vector<int>>adj;
        for(auto it:employees){
            int uid=it->id;
            imp[uid]=it->importance;
            for(int v:it->subordinates){
                adj[uid].push_back(v);
            }
        }
        int res=0;
        map<int,int>vis;
        dfs(id,res,vis,adj);
        return res;
    }
};