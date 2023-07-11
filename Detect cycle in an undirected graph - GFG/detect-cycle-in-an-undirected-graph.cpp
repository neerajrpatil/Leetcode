//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int bfs(int source, vector<int> adj[],int visited[]){
      queue<pair<int,int>>q;
      
      int ans=0;
      visited[source]=1;
      q.push({source,-1});
      while(q.size()!=0){
          auto node=q.front();
          vector<int>temp=adj[node.first];
          for(auto it:temp){
              if(visited[it]==0){
                  visited[it]=1;
                  q.push({it,node.first});
              }
              else if(visited[it]==1 && it!=node.second)return 1;
          }
          q.pop();
      }
      
      return ans;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        int visited[V]={0};
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                int ans=bfs(i,adj,visited);
                if(ans==1)return 1;
            }
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends