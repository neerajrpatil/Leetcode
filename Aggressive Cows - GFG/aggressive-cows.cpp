//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool f(int n, int k, vector<int> &stalls,int mid){
        //can i place k cows with dist >=mid(>=)?
        //this is what my fn will do
        int cnt=1;
        int l=0,r=1;
        while(r<n){
            int L=stalls[l];
            int R=stalls[r];
            if(R-L<mid){
                r++;
            }else{
                cnt++;
                l=r;
                r=l+1;
            }
        }
        
        return cnt>=k;
    }
    int solve(int n, int k, vector<int> &stalls) {
        
        // Write your code here
       
        int s=1;
        sort(stalls.begin(),stalls.end());
        //end shd be max-min element
        int e=stalls[n-1]-stalls[0];
        e=INT_MAX;
        int ans=INT_MIN;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(f(n,k,stalls,mid)){
                ans=max(ans,mid);
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends