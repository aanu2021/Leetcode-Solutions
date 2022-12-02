class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char ch:word1){
            freq1[ch-'a']++;
        }
        for(char ch:word2){
            freq2[ch-'a']++;
        }
        vector<int>v1,v2;
        for(int i=0;i<26;i++){
            if(freq1[i]==0 && freq2[i]==0) continue;
            if(freq1[i]==0 || freq2[i]==0) return false;
            v1.push_back(freq1[i]);
            v2.push_back(freq2[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]) return false;
        }
        return true;
    }
};


 /*

swap any two existing character --> any permutation of the string

transform every occurence of one existing character --> aacab --> bbcbb  --> freq1[i]>0 && freq2[i]>0 --> convert all the characters of both the strings into character (i+'a') , adnd we are done with the problem.

a -> 2    a -> 1
b -> 3    b -> 2
c -> 1    c -> 3 
    
    */