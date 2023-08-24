//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        int sign = 1;
        if(s1[0]=='-'){
            sign *= -1;
            s1 = s1.substr(1);
        }
        if(s2[0]=='-'){
            sign *= -1;
            s2 = s2.substr(1);
        }
        int m = s1.length();
        int n = s2.length();
        if(m==0 || n==0) return "";
        string res = "";
        int dp[m+n];
        memset(dp,0,sizeof(dp));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int sum = dp[i+j+1];
                sum += (s1[i]-'0')*(s2[j]-'0');
                int val = sum%10;
                int rem = sum/10;
                dp[i+j+1] = val;
                dp[i+j] += rem;
            }
        }
        for(int i=0;i<m+n;i++){
            res += (char)(dp[i]+'0');
        }
        reverse(res.begin(),res.end());
        while(res.length() && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res[0]=='0'){
            return res;
        }
        else{
            if(sign == -1){
                res = "-" + res;
            }
            return res;
        }
    }

};

// 0 1 2 3
// 0 0 3 3
//       2
//       0
     
     
// m = 3
// n = 3

     
// 0 1 2      
// 1 2 3 
// 4 5 6
// 0 1 2


// dp[0] = 0
// dp[1] = 5
// dp[2] = 6
// dp[3] = 0
// dp[4] = 8
// dp[5] = 8





//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends