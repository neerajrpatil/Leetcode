class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        #define ll long long 
        ll cnt=0;
        vector<int>v(n,0);
        for(auto it:roads){
            v[it[0]]++;
            v[it[1]]++;
        }
        sort(begin(v),end(v));
        for(int i=n;i>0;i--){
            cnt+=1LL*v[i-1]*i;
        }
        return cnt;
    }
};