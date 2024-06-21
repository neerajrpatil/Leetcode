class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int minDiff=INT_MAX;
        int closest=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int t=target-nums[i]-nums[j];
                auto lb=lower_bound(begin(nums)+j+1,end(nums),t);
                if(lb!=end(nums)){
                    if(*lb==t)return target;
                    if(*lb-t<minDiff){
                        minDiff=*lb-t;
                        closest=nums[i]+nums[j]+*lb;
                    }
                }
                if(lb!=begin(nums)+j+1){
                    lb--;
                    if(t-*lb<minDiff){
                        minDiff=t-*lb;
                        closest=nums[i]+nums[j]+*lb;
                    }
                }
            }
        }
        return closest;
    }
};