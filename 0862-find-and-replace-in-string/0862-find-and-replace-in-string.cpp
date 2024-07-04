class Solution {
public:
    #define pii pair<pair<int,int>,int> 
    #define fi first
    #define se second
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<pii> v;
        for(int i=0;i<indices.size();i++){
            string check=sources[i];
            int ind=indices[i];
            if(s.substr(ind,check.size())==check){
                v.push_back({ { ind,ind+check.size()-1 } ,i } );
            }
        }
        string res;
        sort(begin(v),end(v),[&](pii a,pii b){
            return a.fi.fi<b.fi.fi;
        });
        int i=0,j=0;
        int n=s.size(),m=indices.size();
        while(i<n){
            if(j>=v.size()||i<v[j].fi.fi)res+=s[i++];
            else{
                res+=targets[v[j].se];
                i=v[j].fi.se+1;
                j++;
            }
        }
        return res;
    }
};