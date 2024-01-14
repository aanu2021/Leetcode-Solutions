class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        vector<int>freq1(26, 0);
        vector<int>freq2(26, 0);
        for(char ch : word1){
            freq1[ch-'a']++;
        }
        for(char ch : word2){
            freq2[ch-'a']++;
        }
        vector<int>v1, v2;
        for(int i=0;i<26;i++){
            if(freq1[i] == 0 && freq2[i] == 0) continue;
            if(freq1[i] == 0 || freq2[i] == 0) return false;
            v1.push_back(freq1[i]);
            v2.push_back(freq2[i]);
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        for(int i=0;i<freq1.size();i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }
};



