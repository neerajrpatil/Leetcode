class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();
        int m=to_string(nums[0]).size();
        vector<string>v;
        for(auto it:nums){
            v.push_back(to_string(it));
        }
        long long ans=0;
        for(int i=0;i<m;i++){
            map<int,int>mp;
            for(auto str:v){
                mp[(str[i]-'0')]++;
            }
        // int cn = n;
        // for (auto& it : mp) {
        // cn -= it.second;
        // ans += (long long)(it.second) * cn;
        // }
        long long cur=0;
        for(auto [k,v]:mp){
            cur+=1LL*v*(n-v);
        }
        ans+=cur/2;
        }
        return ans;
    }
};