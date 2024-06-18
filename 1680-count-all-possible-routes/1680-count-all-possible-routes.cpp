class Solution {
public:
    #define mod 1000000007
    int f(int i,int fuel,int finish,vector<int>& locations){
        int cnt=(i==finish);
        int n=locations.size();
        for(int j=0;j<n;j++){
            int cost=abs(locations[i]-locations[j]);
            if(j!=i && fuel-cost>=0){
                cnt+=f(j,fuel-cost,finish,locations);
            }
        }
        return cnt;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        //return f(start,fuel,finish,locations);
        int n=locations.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,0));
       // for(int i=0;i<=fuel;i++)dp[finish][i]=1;
        //dp[finish][0]=1;
        for(int i=0;i<=fuel;i++){
            for(int j=0;j<n;j++){
                int cnt=(j==finish);
                for(int k=0;k<n;k++){
                    int cost=abs(locations[j]-locations[k]);
                    if(j!=k&&i-cost>=0){
                        cnt=(cnt%mod+dp[k][i-cost]%mod)%mod;
                    }
                }
                dp[j][i]=cnt;
            }
        }

        return dp[start][fuel];
    }
};