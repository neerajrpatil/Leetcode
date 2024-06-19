class Solution {
public:
    int f(int i,vector<int>& v,vector<long long>&dp){
        if(i>=v.size())return 0;
        if(dp[i]!=LLONG_MIN)return dp[i];
       int ans=INT_MIN;
       int val=0;
       for(int j=i;j<=i+2&&j<v.size();j++){
            val+=v[j];
            ans=max(ans,val-f(j+1,v,dp));
       }
       return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        
        vector<long long>dp(stoneValue.size(),LLONG_MIN);
        int ans=f(0,stoneValue,dp);
        if(ans>0)return "Alice";
        else if(ans<0)return "Bob";
        else return "Tie";
        
    }
};