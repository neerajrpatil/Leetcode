class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dp[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)dp[i][j]=0;
                else dp[i][j]=1e9;
            }
        }
        for(auto it:edges){
            int u=it[0],v=it[1],k=it[2];
            dp[u][v]=k;
            dp[v][u]=k;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int ans=n-1;
        int city=n-1;
        for(int u=0;u<n;u++){
            int cnt=0;
            for(int v=0;v<n;v++){
                if(u!=v){
                    if(dp[u][v]<=distanceThreshold){
                        cnt++; 
                    }
                }
            }
            if(cnt<=ans){
                ans=cnt;
                city=u;
            }
        }
        return city;
    }
};