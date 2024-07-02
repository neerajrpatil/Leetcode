class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /*
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
        */
        vector<int>ans;
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        int i=0,j=0;
        int n=nums1.size(),m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};