class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n=s.length();
        
        stack<pair<char,int>>S;
        
        for(int i=0;i<n;++i){
            
            if(!S.empty() && S.top().first == s[i]){
                
                S.top().second++;
                
            }
            
            else{
                
                S.push({s[i],1});
                
            }
            
            if(!S.empty() && S.top().second==k){
                S.pop();
            }
            
        }
        
        string res = "";
        
        while(!S.empty()){
            
            int occ   = S.top().second;
            char curr = S.top().first;
            S.pop();
            
            while(occ>0){
                
                res += curr;
                occ--;
                
            }
            
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};