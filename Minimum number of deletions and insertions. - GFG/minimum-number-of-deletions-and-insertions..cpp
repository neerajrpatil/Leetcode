//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    //agar insert delete replace 
	    //tino hote tho wo apne aap me hi khud k questions hai
	    
	    //gfg leetcode pe question sightly different hai
	    //tho dono check kiya karo
	    
	    int m=str1.size();
	    int n=str2.size();
	    int arr[m+1][n+1];
	    for(int i=0;i<=m;i++){
	       for(int j=0;j<=n;j++){
	           arr[i][j]=0;
	       }
	    }
	    
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=n;j++){
	            if(str1[i-1]==str2[j-1]){
	                arr[i][j]=1+arr[i-1][j-1];
	            }else{
	                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
	            }
	        }
	    }
	    int del=n-arr[m][n];
	    int add=m-arr[m][n];
	    //str 1 me se non lcs ko nikal do
	    //str 2 me jo lcs k andar nahi aaye wo character add karo
	    
	    return del+add;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends