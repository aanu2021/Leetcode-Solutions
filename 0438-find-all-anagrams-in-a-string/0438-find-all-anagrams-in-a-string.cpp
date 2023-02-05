class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int>freq(26,0);
        vector<int>ans;
        int dist_char = 0;
        for(char ch:p){
            if(freq[ch-'a']==0) dist_char++;
            freq[ch-'a']++;
        }
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']==0) dist_char++;
            freq[s[i]-'a']--;
            if(freq[s[i]-'a']==0) dist_char--;
            if(i >= m){
                if(freq[s[i-m]-'a']==0) dist_char++;
                freq[s[i-m]-'a']++;
                if(freq[s[i-m]-'a']==0) dist_char--;
            }
            if(dist_char == 0){
                ans.push_back(i-m+1);
            }
        }
        return ans;
    }
};