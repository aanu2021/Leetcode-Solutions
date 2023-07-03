class Solution {
public:
    bool buddyStrings(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        int cnt = 0;
        int idx1 = -1, idx2 = -1;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            if(s[i] != t[i]){
                cnt++;
                if(idx1 == -1){
                    idx1 = i;
                }
                idx2 = i;
            }
        }
        
        if(cnt == 0 || cnt == 2){
            if(idx1==-1 || idx2==-1){
                for(int i=0;i<26;i++){
                    if(freq[i] > 1){
                        return true;
                    }
                }
                return false;
            }
            else{
                swap(s[idx1],s[idx2]);
                return s==t;
            }
        }
        else{
            return false;
        }
    }
};