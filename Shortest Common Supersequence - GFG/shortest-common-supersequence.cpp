//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        //smallest super sequence 
        
        int arr[m+1][n+1];
        for(int i=0;i<=m;i++)arr[i][0]=0;
        for(int j=0;j<=n;j++)arr[0][j]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1])arr[i][j]=1+arr[i-1][j-1];
                else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
        int lcs=arr[m][n];
        return m+n-lcs;     //bcz lcs will dono me tha,jo repeate hora hai 
        
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends