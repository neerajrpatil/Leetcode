class Solution {
public:
    int m,n;
    bool isPacific(int i,int j){
            return i<0 || j<0;
    }
    bool isAtlantic(int i,int j){
            return i>=n || j>=m;
    }
    bool valid(int i,int j){
            return i<n && i>=0 && j<m && j>=0;
    }
    vector<pair<int,int>> moves={{0,1},{0,-1},{-1,0},{1,0}};
    void dfs(int i,int j,int &pacific,int &atlantic,unordered_map<int,unordered_map<int,int>>& vis,vector<vector<int>>& heights){
        if(!valid(i,j)){
            if(isPacific(i,j))pacific=1;
            if(isAtlantic(i,j))atlantic=1;
            return;
        }
        vis[i][j]=1;
        if(pacific&&atlantic)return;
        for(auto it:moves){
            int x=it.first+i;int y=it.second+j;
            if(!valid(x,y)|| (vis[x][y]==0 && heights[x][y]<=heights[i][j]))
            dfs(x,y,pacific,atlantic,vis,heights);
            
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         n=heights.size();
         m=heights[0].size();
        
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int pacific=0,atlantic=0;
                unordered_map<int,unordered_map<int,int>>vis;
                dfs(i,j,pacific,atlantic,vis,heights);
                if(pacific && atlantic)ans.push_back({i,j});
            }
        }
        return ans;
    }
};