class Solution {
public:
    string smallestSubsequence(string s) {
        
        int n=s.length();
        
        stack<char>S;
        
        unordered_map<char,int>lastidx;
        unordered_map<char,bool>visited;
        
        string res="";
        
        for(int i=0;i<n;++i){
            lastidx[s[i]]=i;
        }
        
        for(int i=0;i<n;++i){
            
            if(visited[s[i]]){
                continue;
            }
            
            while(!S.empty() && (S.top() > s[i]) && (lastidx[S.top()] > i)){
                
                visited[S.top()] = false;
                S.pop();
                
            }
            
            visited[s[i]] = true;
            S.push(s[i]);
            
        }
        
        while(!S.empty()){
            
            res+=S.top();
            S.pop();
            
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};