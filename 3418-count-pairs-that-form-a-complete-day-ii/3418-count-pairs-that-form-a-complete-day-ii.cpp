class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<long long,long long>mp;
        long long ans=0,i=0;
        for(auto it:hours){
            ans+=mp[(-it%24+24)%24];
            mp[it%24]++;
            //a+b=24
            //b=24-a
            //b%24=0-(a)%24
            //apply neg mod formula 
        }
        return ans;
    }
};