//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int ub(vector<int> a,int target){
        int s=0;
        int e=a.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int val=a[mid];
            if(val>=target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return s;
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>v;
       for(int i=0;i<n;i++){
           if(v.empty()||a[i]>v.back()){
               v.push_back(a[i]);
           }else{
               int posi=ub(v,a[i]);
               v[posi]=a[i];
           }
       }
       return v.size();
       
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends