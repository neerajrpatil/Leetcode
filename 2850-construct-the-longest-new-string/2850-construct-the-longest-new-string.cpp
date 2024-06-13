class Solution {
public:
    int dp[51][51][51][4];
    int f(int i,int j,int k,int prev){
        if(i==0&&j==0&&k==0)return 0;
        if(dp[i][j][k][prev]!=-1)return dp[i][j][k][prev];
        int cnt=0;
        if(i>0&&prev!=1){
            cnt=f(i-1,j,k,1)+2;
        }
        if(j>0 && prev!=3&&prev!=2){
            int cur=f(i,j-1,k,2)+2;
            cnt=max(cnt,cur);
        }
        if(k>0 && prev!=1){
            int cur=f(i,j,k-1,3)+2;
            cnt=max(cnt,cur);
        }   
        return dp[i][j][k][prev]=cnt;
    }
    int longestString(int x, int y, int z) {
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){
                for(int k=0;k<51;k++){
                    for(int l=0;l<4;l++){
                        dp[i][j][k][l]=-1;
                    }
                }
            }
        }
        return f(x,y,z,0);
    }
};