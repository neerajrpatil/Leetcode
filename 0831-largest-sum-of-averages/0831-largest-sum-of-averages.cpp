class Solution {
public:
    double dp[101][101];
    double f(int i,int k,vector<int>& nums,vector<int>& pre){
        if(i==nums.size())return 0;
        if(k==0)return -1e9;
        if(dp[i][k]!=-1.0)return dp[i][k];

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
       for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            dp[i][j]=-1.0;
        }
       }
        int n=nums.size();
        vector<int>pre(n);
        partial_sum(begin(nums),end(nums),begin(pre));
        return f(0,k,nums,pre);
    }
};