class Solution {
public:
    string smallestSubsequence(string s) {
        
        int n=s.length();
        
        stack<char>S;
        
        map<char,bool>visited;
        map<char,int>lastidx;
        
        for(int i=0;i<n;++i){
            visited[s[i]]=false;
            lastidx[s[i]]=i;
        }
        
        
        for(int i=0;i<n;++i){
            
            if(visited[s[i]]){
                continue;
            }
            
            while(!S.empty() && S.top()>s[i] && lastidx[S.top()]>i){
                
                visited[S.top()]=false;
                S.pop();
                
            }
            
            S.push(s[i]);
            visited[s[i]]=true;
            
        }
        
        string res="";
        
        while(!S.empty()){
            res+=S.top();
            S.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};