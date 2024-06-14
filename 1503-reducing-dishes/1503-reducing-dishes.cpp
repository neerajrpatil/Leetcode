class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int dp[n+2][n+2];
        int maxi=0;
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j>=1;j--){
                dp[i][j]=max(dp[i+1][j],nums[i]*j+dp[i+1][j+1]);
                // maxi=max(maxi,dp[i][j]);
            }
        }
        for(int i=0;i<n;i++)maxi=max(maxi,dp[i][1]);
        return maxi;
    }
};