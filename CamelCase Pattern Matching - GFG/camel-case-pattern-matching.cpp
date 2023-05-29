//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    string getCamelCase(string &str){
        
        int n = str.length();
        
        string res = "";
        
        for(int i=0;i<n;i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                res += str[i];
            }
            else{
                continue;
            }
        }
        
        return res;
        
    }
    
    bool isSubSequence(string &s,string &t){
        
        int m = s.length();
        int n = t.length();
        
        int j = 0;
        
        if(m < n) return false;
        
        for(int i=0;i<n;i++){
            if(s[i] != t[i]) return false;
        }
        
        return true;
        
    }
  
    vector<string> CamelCase(int N, vector<string> dictionary, string pattern) {
        
        vector<string>reducedDictionary(N);
        
        for(int i=0;i<N;i++){
            reducedDictionary[i] = getCamelCase(dictionary[i]);
        }
        
        vector<string>answer;
        for(int i=0;i<N;i++){
            if(isSubSequence(reducedDictionary[i],pattern)){
                answer.push_back(dictionary[i]);
            }
        }
        
        if(answer.size()==0){
            return {"-1"};
        }
        else{
            return answer;
        }

        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends