class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        int j=n-1;
        vector<int>bits(32,0);
        auto add=[&](int ele){
            for(int i=0;i<32;i++){
                bits[i]+=(ele&(1<<i))!=0;
            }
        };
        auto sub=[&](int ele){
            for(int i=0;i<32;i++){
                bits[i]-=(ele&(1<<i))!=0;
            }
        };
        auto chk=[&](int ele){
            for(int i=0;i<32;i++){
                if(ele&(1<<i))
                if(bits[i]<=1)return false;
            }
            return true;
        };
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            add(nums[i]);
            while(j>i){
                if(chk(nums[j])){
                    sub(nums[j]);
                    j--;
                }
                else break;
            }
            ans[i]=j-i+1;
        }
        return ans;
    }
};