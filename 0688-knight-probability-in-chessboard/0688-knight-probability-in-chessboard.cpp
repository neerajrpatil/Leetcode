class Solution {
public:
    int n;
    
    int dx[8] = { 2,  1, -1, -2, -2, -1,  1,  2};
    int dy[8] = { 1,  2,  2,  1, -1, -2, -2, -1};
    bool isValid(int i,int j){
        return i<n&&j<n&&i>=0&&j>=0;
    }
    double dp[25][25][101];
    double f(int i,int j,int k){
        if(!isValid(i,j))return 0;
        if(k==0)return 1.0;
        if(dp[i][j][k]!=-1.0)return dp[i][j][k];
       
        double ans=0;
        for(int x=0;x<8;x++){
            ans+=f(dx[x]+i,dy[x]+j,k-1)/8.0;
        }
        return dp[i][j][k]=ans;
    }
    double knightProbability(int m, int k, int x, int y) {
        for(int i=0;i<25;i++){
            for(int j=0;j<25;j++){
                for(int z=0;z<=100;z++){
                    dp[i][j][z]=-1.0;
                }
            }
        }
        this->n=m;
        return f(x,y,k);
    }
};