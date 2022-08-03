class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n=s.length();
        
        map<char,int>lastidx;
        map<char,bool>visited;
        
        for(int i=0;i<n;++i){
            lastidx[s[i]]=i;
            visited[s[i]]=false;
        }
        
        stack<char>S;
        
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