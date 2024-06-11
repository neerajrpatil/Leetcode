class Solution {
public:
    #define fi first
    #define se second
    #define pii pair<int,int>
    string pushDominoes(string v) {
        queue<pii>q;
        //startind point,neigbhours,

        for(int i=0;i<v.size();i++){
            if(v[i]=='L')
            {
                q.push({i,-1});
            }
            else if(v[i]=='R'){
                q.push({i,1});
            }
        }
        while(!q.empty()){
            int k=q.size();
            unordered_map<int,int>mp;
            //why do i need map?
            //bcz i can push in q on first visit
            //cuz other neightbhour also can visit
            while(k--){
                auto node=q.front();q.pop();
                int ind=node.fi;
                int dir=node.se;
                if(dir==-1){
                    if(ind-1>=0&&v[ind-1]=='.'){
                        //cant put in queue
                        mp[ind-1]--;
                    }
                }else{
                    if(ind+1<v.size() && v[ind+1]=='.'){
                        mp[ind+1]++;
                    }
                }
            }
            for(auto [ind,dir]:mp){
                if(dir!=0)q.push({ind,dir});
                if(dir==-1)v[ind]='L';
                else if(dir==0)v[ind]='.';
                else v[ind]='R';
            }
        }
        return v;
    }
};