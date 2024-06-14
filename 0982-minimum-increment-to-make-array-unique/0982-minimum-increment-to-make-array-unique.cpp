class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int score=0;
        for(int i=1;i<n;i++){
            if(nums[i]>=nums[i-1]+1)continue;
            int cur=abs(nums[i-1]+1-nums[i]);
            nums[i]+=cur;
            score+=cur;
        }
        return score;
    }
};