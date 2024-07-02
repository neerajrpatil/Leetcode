class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int ma=*max_element(begin(nums),end(nums));
        int mi=*min_element(begin(nums),end(nums));
        vector<vector<int>>dp(1005,vector<int>(1005,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int diff=mi-ma;diff<=ma-mi;diff++){
            if(nums[i]-diff>=0) dp[nums[i]][diff+500]=1+dp[nums[i]-diff][diff+500];
            else dp[nums[i]][diff+500]=1;
            ans=max(ans,dp[nums[i]][diff+500]);
            }
        }
        return ans;
    }
};