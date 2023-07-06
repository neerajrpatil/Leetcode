//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 int f(int i,int j,int k,vector<int>& price,vector<vector<vector<int>>>& dp){
     int op1,op2;
     if(dp[i][j][k]!=-1)return dp[i][j][k];
     if(k==2)return 0;
     
     if(i==price.size())return 0;
     
     op1=f(i+1,j,k,price,dp);
     if(j==0){
         op2=f(i+1,1,k,price,dp)-price[i];
     }else{
         
         op2=f(i+1,0,k+1,price,dp)+price[i];
     }
     return dp[i][j][k]=max(op1,op2);
 }
int maxProfit(vector<int>&price){
    //Write your code here..
    
    //stock questions must be space optimised after top down 
    //to make TC equal to other simple logical soln
    //as non recursive solution also existt
    int n=price.size();
      vector<vector<vector<int>>> dp(n+1,
                                    vector<vector<int>> 
                                            (2,vector<int>(3,-1)));
    return f(0,0,0,price,dp);
    
    
    
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends