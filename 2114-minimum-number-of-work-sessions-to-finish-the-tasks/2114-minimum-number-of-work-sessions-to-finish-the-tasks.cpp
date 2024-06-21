class Solution {
public:
    int n;
    // unordered_map<int,unordered_map<int,unordered_map<int,int>>>mp;
    int dp[14][16384][16];
    int dfs(int i,int mask,int val,int maxVal,vector<int>&tasks){
        if(mask==(1<<n)-1)return 0;
        int ans=INT_MAX;
        //if(mp.count(i)&&mp[i].count(mask)&&mp[i][mask].count(val))return mp[i][mask][val];
        if(dp[i][mask][val]!=-1)return dp[i][mask][val];
        for(int j=0;j<tasks.size();j++){
            int cur;
            if(mask&(1<<j))continue;
            cur=1+dfs(j,mask|(1<<j),tasks[j],maxVal,tasks);
            if(val+tasks[j]<=maxVal)
            cur=min(cur,dfs(j,mask|(1<<j),val+tasks[j],maxVal,tasks));
            ans=min(ans,cur);
        }
        return dp[i][mask][val]=ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        n=tasks.size();
        for(int i=0;i<14;i++){
            for(int j=0;j<16384;j++){
                for(int k=0;k<16;k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return dfs(0,1,tasks[0],sessionTime,tasks)+1;
    }
};