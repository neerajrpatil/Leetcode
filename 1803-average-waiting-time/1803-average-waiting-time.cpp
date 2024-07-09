class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long pT=0,wT=0;
        int n=customers.size();
        int curT=customers[0][0];
        for(auto it:customers){
            int arrival=it[0],task=it[1];
            if(arrival<=curT){
                pT+=task;
                wT+=curT-arrival;
                curT+=task;
            }
            else{
                curT=arrival+task;
                pT+=task;
            }
        }
        return 1.0*(pT+wT )/customers.size();



    }
};