//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	   //sort
	   //2 pass, one more max,one more 2nd max
	   int a=-1,b=-1;
	   for(int i=0;i<n;i++){
	       if(a<arr[i])a=arr[i];
	   }
	   for(int i=0;i<n;i++){
	       if(b<arr[i]&&arr[i]!=a)b=arr[i];
	   }
	   return b;
	   
	   //2 variables method
	   }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends