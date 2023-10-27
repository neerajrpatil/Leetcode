//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    int minimumNumberOfDeletions(string S) { 
        // code here
        string a=S,b=S;
        reverse(a.begin(),a.end());
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //init done
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
        
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends