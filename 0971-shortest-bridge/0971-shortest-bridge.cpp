class Solution {
public:
    #define pii pair<int,int> 
    #define fi first
    #define se second
    int dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};
    int n;
    bool chk;
    bool valid(int i,int j){
        return i>=0&&j>=0&&i<n&&j<n;
    }
    void dfs(int i,int j, vector<vector<int>> &grid){
        if(!valid(i,j))return;
        if(grid[i][j]!=1)return;
        grid[i][j]=2;
        for(int k=0;k<4;k++){
            dfs(i+dx[k],j+dy[k],grid);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size();
        chk=1;
        for(int i=0;i<n&&chk;i++){
            for(int j=0;j<n&&chk;j++){
                if(grid[i][j]){
                    chk=0;
                    dfs(i,j,grid);
                }
            }
        }
        queue<pii>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int lvl=0;
        while(!q.empty()){
            //traverse through zeros to find two
            int temp=q.size();
            while(temp--){
                int i=q.front().fi , j=q.front().se;q.pop();
                for(int k=0;k<4;k++){
                    int x=i+dx[k],y=j+dy[k];
                    
                    if(valid(x,y) && grid[x][y]!=1){
                        if(grid[x][y]==2)return lvl;
                        grid[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            lvl++;
        }
        return lvl;
    }
};