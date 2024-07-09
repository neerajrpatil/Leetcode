class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        int prevFinished=0;
        long long time=0;
        for(auto it:customers){
            if(it[0]<prevFinished){
                time+=it[1]+prevFinished-it[0];
                prevFinished+=it[1];
            }
            else{
                time+=it[1];
                prevFinished= it[0]+it[1];
            }
        }
        return 1.0*time/n;
    }
};