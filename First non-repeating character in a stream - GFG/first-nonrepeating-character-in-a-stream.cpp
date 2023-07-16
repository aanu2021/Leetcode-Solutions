//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    int n = s.length();
		    vector<int>Index(26,-1);
		    for(int i=0;i<n;i++){
		        if(Index[s[i]-'a'] == -1){
		            Index[s[i]-'a'] = i;
		        }
		    }
		  //  for(int i=0;i<26;i++){
		  //      cout<<Index[i]<<" ";
		  //  }cout<<"\n";
		    vector<int>freq(26,0);
		    for(int i=0;i<n;i++){
		        freq[s[i]-'a']++;
		    }
		    for(int i=n-1;i>=0;i--){
		        int minIndex = n;
		        char temp = s[i];
		        for(int j=0;j<26;j++){
		            if(freq[j] == 1){
		                minIndex=min(minIndex,Index[j]);
		            }
		        }
		      //  cout<<minIndex<<" ";
		        if(minIndex == n){
		            s[i] = '#';
		        }
		        else{
		            s[i] = s[minIndex];
		        }
		        freq[temp-'a']--;
		    }
		    return s;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends