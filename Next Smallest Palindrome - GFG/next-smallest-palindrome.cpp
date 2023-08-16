//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

    bool isPalindrome(string &str){
        int n = str.length();
        int l = 0, r = n-1;
        while(l < r){
            if(str[l++] != str[r--]){
                return false;
            }
        }
        return true;
    }
    
    string add_1(string &str){
        int n = str.length();
        string res = "";
        int carry = 1;
        for(int i=n-1;i>=0;i--){
            int bit = carry;
            bit += (str[i]-'0');
            carry = (bit/10);
            bit = (bit%10);
            res += (char)(bit+'0');
        }
        if(carry){
            res += (char)(carry + '0');
        }
        reverse(res.begin(),res.end());
        return res;
    }

	vector<int> generateNextPalindrome(int num[], int n) {
	    
	    string str = "";
	    
	    for(int i=0;i<n;i++){
	        str += (char)(num[i]+'0');
	    }
	    
	    n = str.length();
	    
	    if(isPalindrome(str)){
	        str = add_1(str);
	    }
	    
	    n = str.length();
	    
	    if(n > 1 && n%2){
	        string left = str.substr(0,n/2);
	        string right = str.substr((n/2)+1);
	        string rleft = left;
	        reverse(rleft.begin(),rleft.end());
	        if(rleft > right){
	            for(int i=(n/2)+1;i<n;i++){
	                str[i] = str[n-i-1];
	            }
	        }
	        else{
	            string curr = str.substr(0,(n+1)/2);
	            curr = add_1(curr);
	            for(int i=0;i<=(n/2);i++){
	                str[i] = curr[i];
	            }
	            for(int i=(n/2)+1;i<n;i++){
	                str[i] = str[n-i-1];
	            }
	        }
	    }
	    
	    else if(n > 1 && (n%2)==0){
	        string left = str.substr(0,n/2);
	        string right = str.substr(n/2);
	        string rleft = left;
	        reverse(rleft.begin(),rleft.end());
	        if(rleft > right){
	            for(int i=(n/2);i<n;i++){
	                str[i] = str[n-i-1];
	            }
	        }
	        else{
	            string curr = str.substr(0,n/2);
	            curr = add_1(curr);
	            for(int i=0;i<(n/2);i++){
	                str[i] = curr[i];
	            }
	            for(int i=(n/2);i<n;i++){
	                str[i] = str[n-i-1];
	            }
	        }
	    }
	    
	    vector<int>answer;
	    
	    for(int i=0;i<str.length();i++){
	        answer.push_back(str[i]-'0');
	    }
	    
	    return answer;
	    
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends