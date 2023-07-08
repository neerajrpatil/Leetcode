//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        //for all nodes bfs mat dalo..wo traverse karne k liye tha
        
        queue<int>q;
        int arr[V]={0};
        arr[0]=1;
        
        vector<int>ans;
        q.push(0);
        ans.push_back(0);
        
        while(q.size()!=0){
            auto node=q.front();
            q.pop();
            auto v=adj[node];
            for(auto it:v){
                if(arr[it]==0){
                    arr[it]=1;
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends