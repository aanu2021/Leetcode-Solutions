//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    unordered_set<string>st;
	    vector<string>answer;
	
	    void func(string &s,int i,int n,string &sol,vector<int>&vis){
	        
	        if(i == n){
	            if(st.find(sol) == st.end()){
	                answer.push_back(sol);
	                st.insert(sol);
	            }
	            return;
	        }
	        
	        for(int j=0;j<n;j++){
	            if(vis[j]) continue;
	            vis[j] = 1;
	            sol += s[j];
	            func(s,i+1,n,sol,vis);
	            sol.pop_back();
	            vis[j] = 0;
	        }
	        
	    }
	
		vector<string>find_permutation(string S)
		{
		   
		   st.clear();
		   answer.clear();
		   
		   sort(S.begin(),S.end());
		   
		   string sol = "";
		   
		   int n = S.length();
		   vector<int>vis(n,0);
		   
		   func(S,0,n,sol,vis);
		  
		   return answer;
		   
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
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends