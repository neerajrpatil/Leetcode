//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	set<string>se;
	void f(string s,unordered_map<int,int>&mp,string res){
	    if(res.size()==s.size()){
	        se.insert(res);
	        return;
	    }
	    
	    for(int i=0;i<s.size();i++){
	        
	        if(mp[i]==0){
	            mp[i]=1;
	            res.push_back(s[i]);
	            f(s,mp,res);
	            res.pop_back();
	            mp[i]=0;
	        }
	    }
	    
	}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    unordered_map<int,int>mp;
		    sort(S.begin(),S.end());
		    f(S,mp,"");
		    return vector<string>(se.begin(),se.end());
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends