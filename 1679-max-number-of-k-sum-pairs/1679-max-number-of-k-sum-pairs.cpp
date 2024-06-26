class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      map<int,int>mp;
        int cnt=0;
        for(auto it:nums){
            if(mp[k-it]>=1){
                mp[k-it]--;
                cnt++;
            }
            else{
                mp[it]++;
            }
        }
        return cnt;
    }
};