//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        
        int ans=0;
        while(N!=0){
            if(N&1==1)ans++;
            N/=2;      //right shift, can use N<<1 as int type
        }
        return ans;
      return __builtin_popcount(N); //this is O(1)XD
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends