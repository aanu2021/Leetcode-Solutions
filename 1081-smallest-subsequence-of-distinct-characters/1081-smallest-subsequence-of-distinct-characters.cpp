class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        unordered_map<char,int>lastIdx;
        unordered_map<char,int>visited;
        for(int i=0;i<n;i++){
            lastIdx[s[i]] = i;
            visited[s[i]] = 0;
        }
        stack<char>S;
        for(int i=0;i<n;i++){
            if(visited[s[i]]==1) continue;
            while(!S.empty() && (S.top() > s[i]) && lastIdx[S.top()] > i){
                visited[S.top()] = 0;
                S.pop();
            }
            S.push(s[i]);
            visited[s[i]] = 1;
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