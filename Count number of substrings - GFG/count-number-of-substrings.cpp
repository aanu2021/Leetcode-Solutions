//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
    typedef long long int ll;
  
    ll func(string &s,int k){
        int n = s.length();
        ll ans = 0LL;
        int l = 0, r = 0;
        int cnt = 0;
        vector<int>freq(26,0);
        while(r<n){
            freq[s[r]-'a']++;
            if(freq[s[r]-'a']==1) cnt++;
            while(l<=r && cnt > k){
                freq[s[l]-'a']--;
                if(freq[s[l]-'a']==0) cnt--;
                l++;
            }
            ans += (ll)(r-l+1);
            r++;
        }
        return ans;
    }
  
    long long int substrCount (string s, int k) {
    	int n = s.length();
    	ll ans = func(s,k) - func(s,k-1);
    	return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends