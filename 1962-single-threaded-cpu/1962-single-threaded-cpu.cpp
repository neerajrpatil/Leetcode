class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }
        sort(begin(tasks),end(tasks));
        long long time=tasks[0][0];
        vector<int>ans;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int i=0,n=tasks.size();
        while(i<n||!pq.empty()){
            while(i<n && (1LL*tasks[i][0]<=time||pq.empty())){
                pq.push({tasks[i][1],tasks[i][2],tasks[i][0]});
                i++;
            }
            time+=pq.top()[0];
            time=max(time,1LL*pq.top()[2]+1LL*pq.top()[0]);
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        return ans;
    }
};