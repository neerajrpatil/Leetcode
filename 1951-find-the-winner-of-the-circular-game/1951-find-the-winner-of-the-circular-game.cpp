class Solution {
public:
    int findTheWinner(int n, int k) {
        set<int>st;
        for(int i=1;i<=n;i++){
            st.insert(i);
        }
        int ind=0;
        while(st.size()>1){
            ind+=k-1;
            ind%=st.size();
            auto it=st.begin();
            advance(it,ind);
            st.erase(it);
            if(ind==st.size())ind=0;
        }
        return *st.begin();
    }
};