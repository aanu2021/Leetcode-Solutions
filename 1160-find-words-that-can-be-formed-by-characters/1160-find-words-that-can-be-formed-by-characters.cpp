class Solution {
public:
    int countCharacters(vector<string>& words, string str) {
        int n = str.length();
        unordered_map<char,int>freq;

        for(char ch : str){
            freq[ch]++;
        }
        
        int sumLen = 0;
        
        for(int i=0;i<words.size();i++){
            bool flag = true;
            for(char ch : words[i]){
                freq[ch]--;
                if(freq[ch] < 0){
                    flag = false;
                }
            }
            if(flag) sumLen += words[i].length();
            for(char ch : words[i]){
                freq[ch]++;
            }
        }
        
        return sumLen;
    }
};