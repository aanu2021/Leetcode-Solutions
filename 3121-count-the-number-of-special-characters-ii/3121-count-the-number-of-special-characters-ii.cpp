class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int>freqCap(26, -1);
        vector<int>freqSma(26, -1);
        for(int i=0;i<n;i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                freqSma[word[i]-'a'] = i;
            }
            else{
                if(freqCap[word[i]-'A'] == -1){
                    freqCap[word[i]-'A'] = i;
                }
            }
        }
        int answer = 0;
        for(int i=0;i<26;i++){
            if(freqSma[i] != -1 && freqCap[i] != -1){
                if(freqCap[i] < freqSma[i]) continue;
                answer++;
            }
        }
        return answer;
    }
};