//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        vector<int>ans;
        int r1=0,r2=n-1,c1=0,c2=m-1;
        int counter=0;
        while(r1<=r2&&c1<=c2){
            if(counter==0){
                int i=c1;
                while(i<=c2){
                    ans.push_back(a[r1][i]);
                    i++;
                }
                r1++;
                
            }
            else if(counter==1){
                int i=r1;
                while(i<=r2){
                    ans.push_back(a[i][c2]);
                    i++;
                }
                c2--;
            }
            else if(counter==2){
                int i=c2;
                while(i>=c1){
                    ans.push_back(a[r2][i]);
                    i--;
                }
                r2--;
            }
            else{
                int i=r2;
                while(i>=r1){
                    ans.push_back(a[i][c1]);
                    i--;
                }
                c1++;
                
            }
            
            
            counter=(counter+1)%4;
        }
        return ans[k-1];
        
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends