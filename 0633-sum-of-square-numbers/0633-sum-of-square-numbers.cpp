class Solution {
public:
    bool judgeSquareSum(int C) {
        #define ll long long
        ll c=C;
        for(ll a=0;a*a<=c;a++){
            ll b=sqrt(c-a*a);
            if(b*b==(c-a*a))return 1;
        }
        return 0;
    }
};