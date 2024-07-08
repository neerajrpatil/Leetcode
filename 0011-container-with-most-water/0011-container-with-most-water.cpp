class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=0,n=height.size();
        j=n-1;
        long long ans=-1e9;
        while(i<j){
            long long cur = 1LL*(j-i)*min(height[i],height[j]);
            ans=max(ans,cur);
            if(height[i]>=height[j])j--;
            else i++;
        }
        return ans;
    }
};