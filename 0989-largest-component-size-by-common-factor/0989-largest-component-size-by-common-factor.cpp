class Solution {
public:
    vector<int>parent,sz;
    int get(int i){
        if(parent[i]==i)return i;
        else return parent[i]=get(parent[i]);
    }
    void merge(int i,int j){
        i=get(i);
        j=get(j);
        if(i==j)return;
        if(sz[i]<sz[j]){
            parent[i]=j;
            sz[j]+=sz[i];
        }
        else{
            parent[j]=i;
            sz[i]+=sz[j];
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n=*max_element(begin(nums),end(nums));
        parent.resize(n+1);
        sz.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
            sz[i]=1;
        }
        unordered_map<int,int>nums_id;
        for(int ele:nums){
            vector<int>primeFactors;
            int i=2;
            while(i*i<=ele){
                if(ele%i==0){
                    int f1=ele/i;
                    int f2=ele/f1;
                    merge(ele,f2);
                    merge(ele,f1);
                }
                i++;
            }
        }
        int maxi=0;
        map<int,int>mp;
        for(int ele:nums){
            mp[get(ele)]++;
            maxi=max(maxi,mp[get(ele)]);
        }
        return maxi;
    }
   
};