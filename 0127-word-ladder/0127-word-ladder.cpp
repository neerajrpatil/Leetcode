class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_map<string,int>mp;
        if(beginWord==endWord)return 0;
        for(auto it:wordList)mp[it]++;
        if(mp.count(endWord)==0)return 0;
        map<string,vector<string>>adj;
        for(auto s:wordList){
            for(int i=0;i<s.size();i++){
                for(int j=0;j<26;j++){
                    string temp=s;
                    temp[i]='a'+j;
                    if(temp!=s && mp.count(temp)){
                        adj[s].push_back(temp);
                        // adj[temp].push_back(s);
                    }

                }
            }
        }
        queue<pair<string,int>>q;
        unordered_map<string,int>vis;
        q.push({beginWord,0});
        vis[beginWord]=1;
        int cnt=1;
        while(!q.empty() ){
                auto node=q.front();q.pop();
                for(auto it:adj[node.first]){
                    if(it==endWord)return node.second+2;
                    if(vis[it]==0){
                        vis[it]=1;
                        q.push({it,node.second+1});
                    }
                }
        }
        return 0;
    }
};