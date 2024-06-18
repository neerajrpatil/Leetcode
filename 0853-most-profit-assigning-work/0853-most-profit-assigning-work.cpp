class Solution {
public:
#define V(type) vector<type>
#define pb(vec, val) vec.push_back(val)
#define ppb(vec) vec.pop_back()
#define so(vec) sort(vec.begin(), vec.end())
#define rev(vec) reverse(vec.begin(), vec.end())
#define f0(i, n) for(int i = 0; i < n; ++i)
#define p(vec) do { cout << "//"; for (const auto& elem : vec) cout << " " << elem; cout << " //" << endl; } while (0)
#define minheap(type) priority_queue<type, vector<type>, greater<type>>
#define pii pair<int,int>
#define fi first
#define se second
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        /*
        V(pii) v;
        int n=difficulty.size(),m=worker.size();
        for(int i=0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(begin(v),end(v));
        vector<int>maxTillInd(n);
        int val=0;
        for(int i=0;i<n;i++){
            val=max(val,v[i].second);
            maxTillInd[i]=val;
        }
        int ans=0;
        sort(begin(difficulty),end(difficulty));
        for(auto ele:worker){
            auto ub=upper_bound(begin(difficulty),end(difficulty),ele);
            int j=distance(begin(difficulty),ub);
            if(j==0)continue;
            j--;
            ans+=maxTillInd[j];
        }
        return ans;
        */
        V(pii) v;
        int n=difficulty.size(),m=worker.size();
        for(int i=0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
        }
        int i=0;
        sort(begin(v),end(v));
        sort(begin(worker),end(worker));
        priority_queue<int>pq;
        int ans=0;
        for(int j=0;j<m;j++){
            while(i<n && v[i].fi<=worker[j]){
                pq.push(v[i].second);
                i++; //lazy greedy
            }
            if(!pq.empty())
            ans+=pq.top();
        }
        return ans;
        
    }
};