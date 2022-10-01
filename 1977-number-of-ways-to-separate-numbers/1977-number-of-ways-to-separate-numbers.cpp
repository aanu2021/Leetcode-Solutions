class Solution {
public:
    
    typedef long long ll;
    
    const ll M = 1e9 + 7;
    
    ll mod(ll a){
        return ((a%M)+M)%M;
    }
    
    ll mul(ll a,ll b){
        return mod(mod(a)*mod(b));
    }
    
    ll add(ll a,ll b){
        ll c=(a+b);
        c+=M;
        c%=M;
        return c;
    }
    
    // Whether the last string is greater than or equal to second last string //
    
     int compare(int i, int j, int len, vector<vector<int>>&same, string &s){
        //returns true if s[i: i+len-1] <= s[i+len,i+2*len-1] 
        
        int common = same[i][j];   
        if(common >= len) return 1;              //equal substrings
        if(s[i+common] < s[j+common]) return 1;  //first substring is smaller
        else return 0;
    }
    
//     int compare(string &s,int i,int j,vector<vector<int>>&same){
        
//         int len = (j-i+1);
        
//         int common = same[i][j];
        
//         if(common >= len) return 1;
        
//         if(s[i+common] < s[j+common]) return 1;
        
//         return 0;
        
//     }
    
    int numberOfCombinations(string num) {
        
        int n=num.length();
        
        if(num[0]=='0') return 0;
        
        // Store the longest common prefix b/w substring starting at index i and index j //
        
        vector<vector<int>>same(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if(num[i]==num[j]){
                    same[i][j]=same[i+1][j+1]+1;
                }
            }
        }
        
        // dp[i][j] --> stores the number of ways to form the list , with the last string ending at index j and starting at index i //

        
         vector<vector<int>> pref(n, vector<int>(n)); 

        //base case
        for(int j=0; j<n; ++j) pref[0][j] = 1;
        
 
        for(int i=1; i<n; ++i){ 
            if(num[i]=='0') { pref[i] = pref[i-1]; continue; }
            
            for(int j=i; j<n; ++j){ 
                int len = j-i+1, prevStart  = i-1-(len-1), count = 0;
                
                
                //second last number cant have length = len
                if(prevStart<0) count = pref[i-1][i-1]; //= dp[0][i-1] + dp[1][i-1] ... dp[i-1][i-1]
                
                else {
                    
                    //when length of second last number < len
                    count = add(pref[i-1][i-1], -pref[prevStart][i-1]); //= dp[prevStart+1][i-1] ... dp[i-1][i-1]
                    
                    //length of second last number == len
                    if(compare(prevStart,i,len,same,num)){
                        int cnt = (prevStart==0 ? pref[prevStart][i-1] : 
                                   add(pref[prevStart][i-1], -pref[prevStart-1][i-1]));
                        count = add(count, cnt);
                    }
                }
                
                
                pref[i][j] = add(pref[i-1][j], count);   //updating prefix sum
                
            }
        }

        
        return pref[n-1][n-1];
        
    }
};


    
  