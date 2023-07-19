//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        string B=A;
        reverse(B.begin(),B.end());
        
        int m=A.size();
        vector<vector<int>>arr(m+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++){
            arr[i][0]=0;
            arr[0][i]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(A[i-1]==B[j-1]){ //cuz i,j are len,not index
                    arr[i][j]=1+arr[i-1][j-1];
                }
                else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return arr[m][m];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends