//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    // 	long long int sum=0;
    // 	for(int i=0;i<n;i++){
    // 	    for(int j=i+1;j<n;j++){
    // 	        sum += arr[i]^arr[j];
    // 	    }
    // 	}
    // 	return sum;
    long long int sum=0;
    int m=1e9+7;
    for(int i=0;i<32;i++){
        //how many numbers are there with ith set
        int cnt=0;
        //ele<<i is mask
        int mask = 1 << i;
        for(int j=0;j<n;j++){
            //get ith bit
            int ele=arr[j];
            if( ele&mask )cnt++;
        }
        //sum +=   pow(2,i)*cnt*(n-cnt);
        // cout<<sum<<endl;
        sum += (1LL * cnt * (n-cnt) * (1<<i));
    }
    return sum;
    
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends