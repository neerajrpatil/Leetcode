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
        if(n<r)return 0;
        if(n==r || r==0)return 1;
        if(dp[n][r]!=-1)return dp[n][r];
        return dp[n][r]= (nCr(n-1,r)+nCr(n-1,r-1))%mod;
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