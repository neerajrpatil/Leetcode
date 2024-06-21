class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        if(n==k){
            return accumulate(begin(arr),end(arr),0);
        }
        vector<int>prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+arr[i-1];
        }
        reverse(begin(arr),end(arr));
        vector<int>suffix(n+1,0);
        for(int i=1;i<=n;i++){
            suffix[i]=suffix[i-1]+arr[i-1];
        }
        int ans=0;
        for(int pre=0;pre<=k;pre++){
            int suf=k-pre;
            int cur=prefix[pre]+suffix[suf];
            ans=max(ans,cur);
        }
        return ans;
    }
};