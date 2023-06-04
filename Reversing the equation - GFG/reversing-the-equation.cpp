//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
  
    bool isDigit(char ch){
        if(ch >= '0' && ch <= '9'){
            return true;
        } 
        else{
            return false;
        }
    }
    
    bool isOperator(char ch){
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            return true;
        }
        else{
            return false;
        }
    }
  
    string reverseEqn (string s)
    {
       int n = s.length();
       
       stack<string>operands;
       stack<char>operators;
       
       for(int i=0;i<n;i++){
           if(isOperator(s[i])){
               operators.push(s[i]);
           }
           else{
               int j = i;
               string curr = "";
               while(j < n && isDigit(s[j])){
                   curr += s[j];
                   j++;
               }
               operands.push(curr);
               i = j;
               i--;
           }
       }
       
       string res = "";
       
       while(!operands.empty()){
           auto str = operands.top(); operands.pop();
           res += str;
           if(!operators.empty()){
               res += operators.top(); operators.pop();
           }
       }
       
       return res;
       
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends