class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(begin(nums),end(nums),[](string a,string b){
            int m=a.size(),n=b.size();
            
            if(m>n)return 1;
            if(!(n>m) && a>b)return 1;
            return 0;
        });
        // for(auto it:nums)cout<<it<<" ";
        return nums[k-1];
    }
};