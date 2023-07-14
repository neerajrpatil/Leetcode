//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  int f(int ind,int buyLock,int n,vector<int>& prices){
      if(ind==n)return 0;
      int op1=0+f(ind+1,buyLock,n,prices);
      int op2=0;
      if(buyLock==0){
          op2=f(ind+1,1,n,prices)-prices[ind];
      }else{
          op2=f(ind+1,0,n,prices)+prices[ind];
      }
      return max(op1,op2);
  }
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        //0 is lock on buy, 1 hai tho buy ni kar sakta
        //return f(0,0,n,prices);
        
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                int op1=0,op2=0;
                op1=dp[i+1][j]+0;
                if(j==0){
                    op2=dp[i+1][1]-prices[i];
                }else{
                    op2=dp[i+1][0]+prices[i];
                }
                dp[i][j]=max(op1,op2);
            }
        }
        return dp[0][0];
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends