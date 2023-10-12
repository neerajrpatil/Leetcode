//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        //greedy approach
        
        //using max jump variable, i can tell if 
        //index i is reshable or no
        //in recursion if call has went to that index
        //that it was rechable, here due to question 
        //specification i can use greedy 
        
        int maxReach=0; //i can reach all ind till here
        for(int i=0;i<N-1;i++){
            if(i <= maxReach){ //reachable
                maxReach=max(maxReach,i+A[i]);
            }
        }
        return maxReach>= N-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends