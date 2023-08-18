//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    
    bool isMatch(char c1,char c2){
        if(c1=='(' && c2==')') return true;
        if(c1=='{' && c2=='}') return true;
        if(c1=='[' && c2==']') return true;
        return false;
    }
    
    bool ispar(string s)
    {
        int n = s.length();
        stack<char>S;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                S.push(s[i]);
            }
            else{
                if(S.empty()) return false;
                char c = S.top(); S.pop();
                if(isMatch(c,s[i]) == false) return false;
            }
        }
        return S.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends