class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,1),count(n,1);
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            int maxi=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                   if(lis[j]+1>lis[i]){
                    lis[i]=lis[j]+1;count[i]=count[j];
                   }
                   else if(lis[j]+1==lis[i]){
                    count[i]+=count[j];
                   }
                }
            }
        }
       int maxi=*max_element(begin(lis),end(lis));
       int ans=0;
       for(int i=0;i<lis.size();i++){
        if(lis[i]==maxi)ans+=count[i];
       }
       return ans;
    }
};