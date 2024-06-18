class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& worker) {
        int ans=0,n=d.size();
        for(int w:worker){
            int maxi=0;
            for(int i=0;i<n;i++){
                if(w>=d[i]){
                    maxi=max(maxi,p[i]);
                }
            }
            ans+=maxi;
        }
        return ans;
    }
};