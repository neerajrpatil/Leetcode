class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        int n=costs.size();
        int l=candidates,r=n-candidates-1;

        if(l>r){
            sort(begin(costs),end(costs));
            return accumulate(begin(costs),begin(costs)+k,0LL);
        }
        
        priority_queue<int,vector<int>,greater<int>>p1,p2;

        for(int i=0;i<l;i++)p1.push(costs[i]);
        for(int i=n-1;i>r;i--)p2.push(costs[i]);
        while(k--){
            int a=(p1.size()?p1.top():INT_MAX);
            int b=(p2.size()?p2.top():INT_MAX);
            cout<<a<<" "<<b<<endl;
            if(a<=b){
                if(p1.size())p1.pop();
                ans+=a;
                if(l<=r)
                p1.push(costs[l++]);
            }
            else{
               if(p2.size()) p2.pop();
                ans+=b;
                if(l<=r)
                p2.push(costs[r--]);
            }
        }
        cout<<ans;
        return ans;
    }
};