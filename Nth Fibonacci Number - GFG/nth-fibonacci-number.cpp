//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        vector<int>fib(n+1);
        int p2=0;
        int p1=1;
        
        if(n==1)return n;
        int cur;
        for(int i=2;i<=n;i++){
            cur=((p2)%1000000007+(p1)%1000000007)%1000000007;
            p2=p1;
            p1=cur;
            
        }
        return cur;
                 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends