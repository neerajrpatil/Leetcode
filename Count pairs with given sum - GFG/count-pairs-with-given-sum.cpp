//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        
        unordered_map<int,int>mp;
        // for(int i=0;i<n;i++){
        //     mp[arr[i]]++;
        // }
        // int cnt=0;
        // sort(arr,arr+n);
        // int l=0,r=n-1;
        // while(l<r){
        //     int val=arr[l]+arr[r];
        //     if(val<k){
        //         l++;
        //     }
        //     else if(val>k){
        //         r--;
                
        //     }else{
        //     int a=arr[l];
        //         int b=arr[r];
        //         if(a==b)cnt+=(mp[a]*(mp[a]-1)/2);
        //         else
        //         cnt+=mp[a]*mp[b];
                
        //         while(arr[l]==a)l++;
        //         while(arr[r]==b)r--;
                
        //     }
        // }
        // return cnt;
        
        //so i learned that 
        ///if different ele number of pairs formed = product of a x product of b
        //is same element ,then number of pair  formed is (a*(a-1)/2)
        
        //mp[0]++;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=mp[k-arr[i]];
            mp[arr[i]]++;
        }
        return cnt;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends