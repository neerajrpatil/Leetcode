class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int>mp;
        int n=nums.size();
        int i=0,j=0,ans=0;
        int mi=nums[0];int ma=nums[0];
        while(j<n){
            mp[nums[j]]++;
            mi=mp.begin()->first;
            ma=mp.rbegin()->first;
           while(abs(mi-ma)>limit){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                mi=mp.begin()->first;
                 ma=mp.rbegin()->first;
                i++;
           }
           ans=max(ans,j-i+1);
           j++;
        }
        return ans;
    }
};