class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        int dist_char = 0;
        vector<int>freq(26,0);
        for(int i=0;i<m;i++){
            if(freq[s1[i]-'a'] == 0) dist_char++;
            freq[s1[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            if(freq[s2[i]-'a']==0) dist_char++;
            freq[s2[i]-'a']--;
            if(freq[s2[i]-'a']==0) dist_char--;
            if(i >= m){
                if(freq[s2[i-m]-'a']==0) dist_char++;
                freq[s2[i-m]-'a']++;
                if(freq[s2[i-m]-'a']==0) dist_char--;
            }
            if(dist_char == 0) return true;
        }
        return false;
    }
};