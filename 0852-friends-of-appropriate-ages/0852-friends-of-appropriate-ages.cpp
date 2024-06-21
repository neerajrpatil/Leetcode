class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        //[0......i-1]
        //v[j]>0.5*age[i]+7
        sort(begin(ages),end(ages));
        int cnt=0;
        map<int,int>mp;
        for(int i=ages.size()-1;i>=0;i--){
            if(mp.count(ages[i])){
                cnt+=mp[ages[i]];continue;
            }
            auto ub=upper_bound(begin(ages),end(ages),ages[i]/2+7);
            if(ub>=begin(ages)+i)continue;
            int cur=distance(ub,begin(ages)+i);
            cnt+=cur;
            mp[ages[i]]=cur;
            //16 16 16
        }
        return cnt;
    }
};