class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int lvl) {
        vector<string>ans;
        int n=friends.size();
        vector<int>vis(n,0);
        vis[id]=1;
        queue<int>q;
        q.push(id);
        int level=0;
        unordered_map<string,int>mp;
        while(!q.empty()){
            int k=q.size();
            for(int x=0;x<k;x++){
                int u=q.front();q.pop();
                if(level==lvl){
                    for(string vid:watchedVideos[u]){
                        mp[vid]++;
                    }
                }
                else{
                    for(int v:friends[u]){
                    if(!vis[v]){
                        vis[v]=1;
                        q.push(v);
                    }
                }
                }
            }
            level++;
            
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        for(auto [k,v]:mp){
            pq.push({v,k});
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};