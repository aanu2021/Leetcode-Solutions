//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string stringPartition(string s, int a, int b){
        int n = s.length();
        vector<int>LR(n+1,0);
        vector<int>RL(n+1,0);
        LR[0] = (s[0]-'0')%a;
        for(int i=1;i<n;i++){
            LR[i] = ((LR[i-1]*10) + (s[i]-'0'))%a;
        }
        RL[n-1] = (s[n-1]-'0')%b;
        int power = 10;
        for(int i=n-2;i>=0;i--){
            RL[i] = (RL[i+1] + (power*(s[i]-'0')))%b;
            power *= 10;
            power %= b;
        }
        int idx = -1;
        for(int i=0;i<n-1;i++){
            if(LR[i]==0 && RL[i+1]==0){
                idx = i+1;
                break;
            }
        }
        if(idx==-1){
            return "-1";
        }
        return s.substr(0,idx) + " " + s.substr(idx);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
} 
// } Driver Code Ends