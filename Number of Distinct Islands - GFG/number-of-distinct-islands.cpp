//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool isValid(int x,int y,int m ,int n){
      return x>=0 && x<m && y>=0 && y<n;
  }
  void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,int si,int sj,vector<pair<int,int>>&temp){
      visited[i][j]=1;
      temp.push_back({i-si,j-sj});
      int m=grid.size();
      int n=grid[0].size();
      int dx[4]={0,0,-1,1};
      int dy[4]={-1,1,0,0};
      for(int k=0;k<4;k++){
          //3 cond
          //1 mis
          int x=i+dx[k];
          int y=j+dy[k];
          if(isValid(x,y,m,n)&&visited[x][y]==0&&grid[x][y]==1){
              
              dfs(x,y,grid,visited,si,sj,temp);
          }
      }
      
      
      
      
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        //speak as if u are in interview and break problems into smalller tasks
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        set<vector<pair<int,int>>>s;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0&&grid[i][j]==1){
                    //vis mark recursion me hora hai
                    vector<pair<int,int>>temp;
                    dfs(i,j,grid,visited,i,j,temp);
                    s.insert(temp);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends