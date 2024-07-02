class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>a(1001,0),b(1001,0);
        for(int ele:nums1)a[ele]++;
        for(int ele:nums2)b[ele]++;
        vector<int>ans;
        for(int i=0;i<=1000;i++){
            //ele is i
            //its f is min(a[i],b[i])
            int k=min(a[i],b[i]);
            while(k--){
                ans.push_back(i);
            }
        }
        return ans;
    }
};