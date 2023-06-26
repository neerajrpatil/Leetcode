//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>arr(n);
        for(int i=0;i<n;i++){
            arr[i]={end[i],start[i]};
        }
        
        //sort based on end time,not start time
        
        //bcz if first meeting start at time 1 ans end at time
        //11 (highest hours) we will do only 1 meeting if i sort 
        //based on start time...
        
        sort(arr.begin(),arr.end());
        int count=0;
        int i=0;
        while(i<n){
            int st=arr[i].second;
            int et=arr[i].first;
            count++;
            while(i<n && st<=et){
                i++;
                st=arr[i].second;
            }
            
        }
        return count;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends