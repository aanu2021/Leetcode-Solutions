//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:

    typedef long long ll;

    long long solve(int X,int Y,string s){
       int n = s.length();
       stack<char>S;
       ll ans1 = 0LL ,ans2 = 0LL;
       for(int i=0;i<n;i++){
           if(s[i]=='r'){
               if(!S.empty() && S.top()=='p'){
                   ans1 += (ll)X;
                   S.pop();
               }else{
                   S.push(s[i]);
               }
           }
           else{
               S.push(s[i]);
           }
       }
       string str = "";
       while(!S.empty()){
           str += S.top();
           S.pop();
       }
       reverse(str.begin(),str.end());
       for(int i=0;i<str.length();i++){
           if(str[i]=='p'){
               if(!S.empty() && S.top()=='r'){
                   ans1 += (ll)Y;
                   S.pop();
               }else{
                   S.push(str[i]);
               }
           }
           else{
               S.push(str[i]);
           }
       }
       str = "";
       while(!S.empty()) S.pop();
       for(int i=0;i<n;i++){
           if(s[i]=='p'){
               if(!S.empty() && S.top()=='r'){
                   ans2 += (ll)Y;
                   S.pop();
               }else{
                   S.push(s[i]);
               }
           }
           else{
               S.push(s[i]);
           }
       }
       while(!S.empty()){
           str += S.top(); 
           S.pop();
       }
       reverse(str.begin(),str.end());
       for(int i=0;i<str.length();i++){
           if(str[i]=='r'){
               if(!S.empty() && S.top()=='p'){
                   ans2 += (ll)X;
                   S.pop();
               }else{
                   S.push(str[i]);
               }
           }
           else{
               S.push(str[i]);
           }
       }
       return max(ans1,ans2);
    }
};

/*

pr -> 5
rp -> 4

p r p r

first  preference remove "pr" and gain +X points corresponding to that
second preference remove "rp" and gain +Y points corresponding to that

first  preference remove "rp" and gain +Y points corresponding to that
second preference remove "pr" and gain +X points corresponding to that

X = 5 , Y = 4

p r p r p

8

10 

*/



//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends