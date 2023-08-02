//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
typedef pair<pair<int,int>,int> p;
class Solution {
  public:
  int isValid(int m,int n,int x,int y){
      return x>=0 && y>=0 && x<n && y<m; 
  }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0)return -1;
        queue<p>q;
        vector<vector<int>>visited(N,vector<int>(M,-1));
            q.push({{0,0},0});
            visited[0][0]=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int level=node.second;
            //for all unvi adj 
            int dx[4]={-1,1,0,0};
            int dy[4]={0,0,-1,1};
            for(int k=0;k<4;k++){
                int x=node.first.first+dx[k];
                int y=node.first.second+dy[k];
                if(isValid(M,N,x,y) && visited[x][y]==-1 && A[x][y]==1){
                    
                    visited[x][y]=level+1;
                    
                    
                    q.push({{x,y},level+1});
                    
                }
            }
        }
            // if(X==0 && Y==0)return 0;
             return visited[X][Y];
            
        }
        
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends