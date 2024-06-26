//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        int arr[n+1][m+1];   // n+1,m+1 bcz base cond at -1
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                
                if(i==0 || j==0){
                    arr[i][j]=0;
                }
            }
        }
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s1[i-1]==s2[j-1]){
                    arr[i][j]=1+arr[i-1][j-1];
                }else{
                    arr[i][j]=0;
                }
            }
        }
        int res=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
res=max(res,arr[i][j]);
                
                }
            }
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends