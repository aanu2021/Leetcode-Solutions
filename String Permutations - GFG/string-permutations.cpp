//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void recursion(string &s,int idx,vector<string>&answer){
        if(idx == s.length()){
            answer.push_back(s);
            return;
        }
        for(int i=idx;i<s.length();++i){
            swap(s[i],s[idx]);
            recursion(s,idx+1,answer);
            swap(s[i],s[idx]);
        }
    }
    
    vector<string> permutation(string s)
    {
        vector<string>answer;
        recursion(s,0,answer);
        sort(answer.begin(),answer.end());
        return answer;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends