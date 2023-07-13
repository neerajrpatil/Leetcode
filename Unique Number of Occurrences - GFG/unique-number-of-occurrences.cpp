//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int a[])
    {   
        //hash frequeicies
        //hash k badle vector me freq store kar k,vector k sort kar k
        //adjacent value same hai tho return false, but 2x1e9 ka vector chahiye
        
        //now why is hash better than vecot?
        //max hash size will go to 1e5, in worts case, vector will go to 
        //2e9..how am i saying this??look at constrains
        /*
        sort(a,a+n);
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<n){
            if(a[i]==a[j])j++;
            else {
                if(mp[j-i]++!=0)return false;
                i=j;
            }
            
        }
        if(mp[j-i]++!=0)return false;
        return true;
        */
        
        //to do in O(n)i can use two maps..
        unordered_map<int,int>mp1,mp2;
        
        for(int i=0;i<n;i++){
            mp1[a[i]]++;
        }
        for(auto it:mp1){
            if(mp2[it.second]++!=0)return false;
        }
        return true;
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends