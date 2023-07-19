class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.length();
        
        stack<char>S;
        
        unordered_map<char,bool>visited;
        unordered_map<char,int>lastIdx;
        
        for(int i=0;i<n;i++){
            visited[s[i]] = false;
            lastIdx[s[i]] = i;
        }
        
        for(int i=0;i<n;i++){
            if(visited[s[i]]) continue;
            while(!S.empty() && (S.top() > s[i]) && lastIdx[S.top()] > i){
                visited[S.top()] = false;
                S.pop();
            }
            S.push(s[i]);
            visited[s[i]] = true;
        }
        
        string res = "";
        while(!S.empty()){
            res += S.top();
            S.pop();
        }
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};