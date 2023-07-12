//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int n,int R)
    {
        //according to question there will only be positive numbers
       //Your code here
       // normal approch is O(1),but can be done in O(logn)
       //binary exponanation
       long long ans=1;
       
       long long N=n;
       while(R>0){
           if(R&1){
               ans=(ans*N)%1000000007;
               R--;
           }else{
               N=(N*N)%1000000007;
               R=R/2;
               
           }
       }
       return ans%1000000007;
       
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends