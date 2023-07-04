//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

string reverseWord(string str){
    
  //Your code here
  int l=0;
  int r=str.size()-1;
  while(l<r){
      
      str[r]=str[l]^str[r];
      str[l]=str[l]^str[r];
      str[r]=str[l]^str[r];
      l++;
      r--;
  }
  return str;
  
}



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends