class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //1 2 3 4 
        int i=0,n=profits.size(),ans=0;
        priority_queue<int>pq;
        vector<pair<int,int>>v(n);
        for(int i=0;i<profits.size();i++){
            v[i]={profits[i],capital[i]};
        }
        sort(begin(v),end(v),[&](pair<int,int> a,pair<int,int> b){
            return a.second<b.second;
        });
        while(k--){
            while(i<n && v[i].second<=w)pq.push(v[i++].first);
            if(!pq.empty()){
                w+=pq.top();pq.pop();
            }
        }
        return w;   
    }
};