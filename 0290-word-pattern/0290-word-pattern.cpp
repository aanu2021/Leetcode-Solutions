class Solution {
public:
    bool wordPattern(string p, string s) {
        int m = p.length();
        int n = s.length();
        int idx=0;
        
        unordered_map<char,string>mapp;
        unordered_set<string>Set;
        
        for(int i=0;i<n;i++){
            if(s[i]==' ') continue;
            int j = i;
            if(idx==m) return false;
            string word = "";
            while(j<n && s[j]!=' '){
                word+=s[j];
                j++;
            }
            if(mapp.find(p[idx])==mapp.end()){
                if(Set.find(word)!=Set.end()) return false;
                Set.insert(word);
                mapp[p[idx]] = word;
            }
            else{
                if(mapp[p[idx]]!=word) return false;
            }
            i=j;
            i--;
            idx++;
        }
        if(idx==m) return true;
        return false;
    }
};