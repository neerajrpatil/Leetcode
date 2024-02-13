class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto str:words){
            int l=0,r=str.size()-1;
            bool chk=true;
            while(l<r){
                if(str[l]!=str[r]){
                    chk=false;break;
                }
                l++;
                r--;
            }
            if(chk)return str;
        }
        return "";
    }
};