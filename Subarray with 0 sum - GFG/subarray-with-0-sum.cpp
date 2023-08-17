//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_map<int,int>mp;
        //no need to put 0, in starting
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0)break;
            if(mp.find(sum)!=mp.end()){
                return true;
            }
            mp[sum]++;
            //if longest was asked i can only insert once, i
            //if i insert everytime i will get smallest
        }
        if(sum==0)return true;
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
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
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends