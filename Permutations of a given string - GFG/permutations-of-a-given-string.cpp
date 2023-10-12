//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void dfs(string &s,int i,int n,vector<string>&answer){
	        if(i==n){
	            answer.push_back(s);
	            return;
	        }
	        unordered_set<char>S;
	        for(int j=i;j<n;j++){
	            if(S.find(s[j]) != S.end()) continue;
	            S.insert(s[j]);
	            swap(s[i],s[j]);
	            dfs(s,i+1,n,answer);
	            swap(s[i],s[j]);
	        }
	    }
	
		vector<string>find_permutation(string s)
		{
		     int n = s.length();
		     sort(s.begin(),s.end());
		     vector<string>answer;
		     dfs(s,0,n,answer);
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