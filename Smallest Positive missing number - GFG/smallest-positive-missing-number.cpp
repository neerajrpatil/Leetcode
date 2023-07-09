//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{   
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        sort(arr,arr+n);
        int i=0;
        while(i<n&&arr[i]<=0)i++;
        if(i==n)return 1; //1 is ans as there is no positive number in arr
        //else i will be index of smalles positive number of in arr
        set<int>s(arr+i,arr+n);
        //to remove duplicates
        int ans=1;
        for(auto it:s){
            if(it!=ans)break;
            ans++;
        }
        return ans;
        
        
        
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends