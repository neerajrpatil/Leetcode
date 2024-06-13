class Solution {
public:
    unordered_map<int,unordered_map<int,double>>dp;
    double f(int i,int k,vector<int>& nums,vector<int>& pre){
        if(i==nums.size())return 0;
        if(k==0)return -1e9;
        //if(dp[i][k]!=-1.0)return dp[i][k];
        if(dp.count(i)&&dp[i].count(k))return dp[i][k];
        double ans=0;
        for(int j=i;j<nums.size();j++){
            double cur=0;
            cur=(1.0*pre[j]-pre[i]+nums[i])/(j-i+1);
            cur+=f(j+1,k-1,nums,pre);
            ans=max(ans,cur);
        }
        return dp[i][k]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        //memset(dp,-1.0,sizeof(dp));
        int n=nums.size();
        vector<int>pre(n);
        partial_sum(begin(nums),end(nums),begin(pre));
        return f(0,k,nums,pre);
    }
};