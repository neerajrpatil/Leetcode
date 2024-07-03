class Solution {
public:
    bool check(string str,int ans){
        int cnt=0;
        unordered_map<char,int>mp;
        unordered_map<string,int>mpp;
        int i=0,j=0,n=str.size();
        while(j<n){
            mp[str[j]]++;
            if(j-i+1<ans)j++;
            else{
                if(mp.size()==1){
                    int chk=++mpp[str.substr(i,ans)];
                    if(chk>=3)return 1;
                }
                mp[str[i]]--;
                if(mp[str[i]]==0)mp.erase(str[i]);
                i++;
                j++;
            }
        }
        // cout<<ans<<" "<<cnt<<endl;
        return 0;
    }
    int maximumLength(string str) {
        int n=str.size();
        int cnt[26]={0};
        for(char ch:str){
            cnt[ch-'a']++;
        }        
        bool chk=0;
        for(int i=0;i<26;i++){
            if(cnt[i]>2){
                chk=1;break;
            }
        }
        if(!chk)return -1;
        int s=1,e=n-2;
        int mid;
        while(s<=e){
            mid=s+(e-s)/2;
            if(check(str,mid))s=mid+1;
            else e=mid-1;
        }
        return e;
    }
};