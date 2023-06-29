//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    
	    int n = s.length();
	    
	    int odd_cnt = 0, even_cnt = 0;
	    
	    for(int i=0;i<n;i+=2){
	        if(s[i]=='1'){
	            odd_cnt++;
	        }
	    }
	    
	    for(int i=1;i<n;i+=2){
	        if(s[i]=='1'){
	            even_cnt++;
	        }
	    }
	    
	    return (abs(odd_cnt-even_cnt)%3==0);
	    
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends