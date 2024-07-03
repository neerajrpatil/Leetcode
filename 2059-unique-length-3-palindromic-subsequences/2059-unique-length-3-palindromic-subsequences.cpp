class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,int>first,last;
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch=s[i];
            last[ch]=i;
            if(first.count(ch)==0)first[ch]=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            char ch='a'+i;
            if(first.count(ch)==0)continue;
            int l=first[ch]+1,r=last[ch]-1;
            set<char>st;
            while(l<=r){
                st.insert(s[l]);
                l++;
            }
            ans+=st.size();
        }
        return ans;
    }
};