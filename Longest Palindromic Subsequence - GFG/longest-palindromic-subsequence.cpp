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
        //lcs of (a,rev(a)) is answer
        
        int m=A.size();
        int arr[m+1][m+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0)arr[i][j]=0;
            }
            
        }
        string B=A;
        reverse(B.begin(),B.end());
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                if(A[i-1]==B[j-1]){
                    arr[i][j]=1+arr[i-1][j-1];
                }else{
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