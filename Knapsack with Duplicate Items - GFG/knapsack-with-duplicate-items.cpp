//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int n=N;
        int w=W;
        vector<vector<int>>dp(n+1,vector<int>(w+1,0));
        //int dp[n+1][w+1]={{0}};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=w;j++){
                int nt=dp[i-1][j];
                int t=0;
                if(j-wt[i-1]>=0)t=val[i-1]+dp[i][j-wt[i-1]];
                dp[i][j]=max(t,nt);
            }
        }
        return dp[n][w];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends