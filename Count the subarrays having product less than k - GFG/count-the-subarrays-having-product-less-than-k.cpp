//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        //count of subarray is hashmap
        //sinnce +ve i can use sliding window
        
        int l=0,r=0;
        long long p=1;
        int cnt=0;
        if(k<=*min_element(begin(a),end(a)))return 0;
        while(r<a.size()){
          p*=a[r];
          if(p<k){
              
              
              
          }else{
              while(p>=k){
                  p/=a[l];
                  l++;
              }
          }
          cnt+=(r-l+1);
          r++;
          
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends