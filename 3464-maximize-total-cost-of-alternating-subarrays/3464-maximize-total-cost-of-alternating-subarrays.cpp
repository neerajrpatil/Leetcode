class Solution {
public:
    #define ll long long
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<ll>prev(2,0),cur(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                ll t=0,nt=0;
                nt=prev[j^1]+nums[i]*(j?-1:1);
                t=prev[0]+nums[i]*(j?-1:1);
                cur[j]=max(t,nt);
            }
            prev=cur;
        }
        return cur[0];
    }
};