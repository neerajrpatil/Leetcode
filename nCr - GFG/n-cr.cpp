//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
long long mod=1e9+7;
vector<vector<int>>dp(1001,vector<int>(800+1,-1));
class Solution{
public:
    int nCr(int n, int r){
        // code here
        //1. pascal triangle method, draw triangle 
        //2 k sare methods 
        /*if(n<r)return 0;
        if(n==r || r==0)return 1;
        if(dp[n][r]!=-1)return dp[n][r];
        return dp[n][r]= (nCr(n-1,r)+nCr(n-1,r-1))%mod;
        */
        for(int i=0;i<=n;i++){
            for(int j=0;j<=r;j++){
                if(i<j)dp[i][j]=0;
                else if(i==j || j==0)dp[i][j]=1;
                else{
                    dp[i][j]=(dp[i-1][j])%mod+(dp[i-1][j-1])%mod;
                }
            }
        }
        return dp[n][r]%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends