class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        //i   i+k-1
        //i-(k-1)
        /*
        queue<int>q;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!q.empty()&&i>q.front()){
                q.pop();
            }
            cout<<q.size()<<" ";
            if((nums[i]+q.size())%2==0){
                if(i+k-1>=n)return -1;
                cout<<i+k-1<<" ";
                cnt++;
                q.push(i+k-1);
            }
        }
        return cnt;
        */
        //i-j+1==(k)

        /*
        int n=nums.size();
        int cnt=0,ans=0;
        vector<int>flip(n,0);
        for(int i=0;i<n;i++){
            if(i-k>=0 && flip[i-k])cnt--;
            if((nums[i]+cnt)%2==0){
                if(i+k>n)return -1;
                flip[i]=1;
                cnt++;
                ans++;
            }
        }
        return ans;
        */
        int n=nums.size();
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(i-k>=0 && nums[i-k]==-1)cnt--;
            if((nums[i]+cnt)%2==0){
                if(i+k>n)return -1;
                nums[i]=-1;
                cnt++;
                ans++;
            }
        }
        return ans;
    }
};