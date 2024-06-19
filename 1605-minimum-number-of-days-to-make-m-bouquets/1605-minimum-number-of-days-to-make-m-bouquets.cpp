class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
       int n=v.size();
       int mid;
       auto f=[&](){
        int cnt=0;
        int run=0;
        for(int i=0;i<n;i++){
            if(v[i]<=mid){
                run++;
            }
            else{
                cnt+=(run/k);
                run=0;
            }
        }
        cnt+=run/k;
        return cnt>=m;
       };
       if(1LL*m*k>1LL*n)return -1;
       int s=1,e=1e9;
       while(s<=e){
        mid= s+(e-s)/2;
        bool chk=f();
        if(chk==false){
            s=mid+1;
        }else{
            e=mid-1;
        }
       }
       return s;
    }
};